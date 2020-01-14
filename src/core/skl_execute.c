/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "skl_execute.h"
#include "skl_execute_operate.h"
#include "skl_execute_function.h"
#include "skl_execute_debug.h"

extern hash_t *global_function_table;
extern hash_t *global_variable_table;
extern statement_list_t *global_statement_list, *global_include_statement_list;
extern int global_include_mode;

/**
 * 执行
 */
void execute() {
    execute_statement(global_variable_table);
}

/**
 * 执行语句
 */
void execute_statement(hash_t *variable_table) {
    int is_include = 0;
    statement_list_item_t *current = global_statement_list->top;
    execute_before();
    while (current) {
        statement_t *statement = current->statement;
        switch (statement->type) {
            case statement_type_expression:
                execute_expression(statement->u.e->expression, variable_table);
                break;
            case statement_type_return:
                break;
            case statement_type_if:
                break;
            case statement_type_continue:
                break;
            case statement_type_global:
                break;
            case statement_type_for:
                break;
            case statement_type_break:
                break;
            case statement_type_include:
                execute_include(statement->u.in);
                is_include = 1;
                break;
            default:
                error_exception("Undefined statement type(%d)!", statement->type);
        }
        if (is_include) {
            current = global_statement_list->top;
            is_include = 0;
        } else {
            current = current->next;
        }
        //內存释放
        memory_free(statement);
    }
    execute_after();
}

/**
 * 
 */
void execute_before() {
    printf("before_excute\n");
}

/**
 * 
 */
void execute_after() {
    printf("after_excute\n");
}

/**
 * 执行include
 * @param is
 */
void execute_include(include_statement_t *is) {
    char *filename = is->filename;
    FILE *input = fopen(filename, FILE_OPT_READ);
    if (is_empty(input)) {
        error_exception("File:%s can not be read!", filename);
    }
    global_include_mode = 1;
    yyrestart(input);
    if (yyparse()) {
        error_exception("System parse file:%s failed !", filename);
    }
    global_include_mode = 0;
    execute_statement_list_merge();
    fclose(input);
    memory_free(filename);
}

/**
 * 执行语句列表合并
 */
void execute_statement_list_merge() {
    global_include_statement_list->tail->next = global_statement_list->top->next;
    global_statement_list->top = global_include_statement_list->top;
    global_include_statement_list->top = global_include_statement_list->tail = NULL;
}

/**
 * 执行表达式
 * @param expression
 */
expression_result_t *execute_expression(expression_t *expression, hash_t *variable_table) {
    expression_result_t *res;
    switch (expression->type) {
        case expression_type_assign:
            res = execute_assign_expression(expression->expression.assign, variable_table);
            break;
        case expression_type_func:
            res = execute_function_expression(expression->expression.function, variable_table);
            break;
        case expression_type_binary:
            res = execute_binary_expression(expression->expression.binary, variable_table);
            break;
        case expression_type_primary:
            res = execute_primary_expression(expression->expression.primary);
            break;
        default:
            error_exception("Undefined epression type(%d)!", expression->type);
    }
    memory_free(expression);
    return res;
}

/**
 * 执行赋值表达式
 * @param ae
 * @return
 */
expression_result_t *execute_assign_expression(assign_expression_t *ae, hash_t *variable_table) {
    expression_result_t *res = execute_expression(ae->expression, variable_table);
    variable_t *v;
    switch (res->type) {
        case expression_result_type_int:
            v = create_integer_variable(ae->identifier, res->value.i);
            break;
        case expression_result_type_double:
            v = create_double_variable(ae->identifier, res->value.d);
            break;
        case expression_result_type_string:
            v = create_string_variable(ae->identifier, res->value.s, strlen(res->value.s));
            break;
        case expression_result_type_bool:
            v = create_bool_variable(ae->identifier, res->value.b);
            break;
        default:
            error_exception("Undefined assign:%s type(%d)!", ae->identifier, res->type);
    }
    insert_or_update_hash(variable_table, ae->identifier, strlen(ae->identifier), (void *) v);
    return res;
}

/**
 * 执行二元表达式
 * @param be
 * @return
 */
expression_result_t *execute_binary_expression(binary_expression_t *be, hash_t *variable_table) {
    expression_result_t *left_res, *right_res, *res;
    left_res = execute_expression(be->left, variable_table);
    right_res = execute_expression(be->right, variable_table);
    switch (be->action) {
        case expression_action_add:
            res = operate_add(left_res, right_res);
            break;
        case expression_action_sub:
            res = operate_sub(left_res, right_res);
            break;
        case expression_action_mul:
            res = operate_mul(left_res, right_res);
            break;
        case expression_action_div:
            res = operate_div(left_res, right_res);
            break;
        case expression_action_gt:
            res = operate_gt(left_res, right_res);
            break;
        case expression_action_ge:
            res = operate_ge(left_res, right_res);
            break;
        case expression_action_lt:
            res = operate_lt(left_res, right_res);
            break;
        case expression_action_le:
            res = operate_lt(left_res, right_res);
            break;
        case expression_action_ne:
            res = operate_ne(left_res, right_res);
            break;
        case expression_action_eq:
            res = operate_eq(left_res, right_res);
            break;
        default:
            error_exception("Undefined expression action(%d)!", be->action);
    }
    //销毁
    memory_free(be);
    print_expression_result(res);
    return res;
}

/**
 * 执行基础表达式
 * @param pe
 * @return 
 */
expression_result_t *execute_primary_expression(primary_expression_t *pe) {
    expression_result_t *res = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    switch (pe->type) {
        case value_type_integer:
            res->type = expression_result_type_int;
            res->value.i = pe->u.i;
            break;
        case value_type_double:
            res->type = expression_result_type_double;
            res->value.d = pe->u.d;
            break;
        case value_type_string:
            res->type = expression_result_type_string;
            res->value.s = pe->u.string;
            break;
        case value_type_identifier:
            res->type = expression_result_type_variable;
            res->value.s = pe->u.identifier;
            break;
        case value_type_bool:
            res->type = expression_result_type_bool;
            res->value.b = pe->u.b;
            break;
        case value_type_invalid:
        default:
            error_exception("Undefined value type!");
    }
    memory_free(pe);
    return res;
}