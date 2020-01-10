/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "skl_execute.h"
#include "skl_execute_operate.h"

extern hash_t *global_function_table;
extern hash_t *global_variable_table;
extern statement_list_t *global_statement_list;

/**
 * 执行语句
 */
void execute() {
    statement_list_item_t *current = global_statement_list->top;
    before_execute();
    while (current) {
        statement_t *statement = current->statement;
        switch (statement->type) {
            case statement_type_expression:
                execute_expression(statement->u.e->expression, global_function_table);
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
            default:
                error_exception("Undefined statement type(%d)!", statement->type);
        }
        current = current->next;
    }
    after_execute();
}

void before_execute() {
    printf("before_excute\n");
}

void after_execute() {
    printf("after_excute\n");
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
 * 
 * @param fe
 * @param function_variable_table
 * @return 
 */
expression_result_t *execute_function_expression(function_expression_t *fe, hash_t *function_variable_table) {
    expression_result_t *er;
    function_t *function;
    function = (function_t *) find_hash(global_function_table, fe->function_name, strlen(fe->function_name));
    if (is_empty(function)) {
        error_exception("Function:%s not be found!", fe->function_name);
    }
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
    return res;
}

/**
 * 打印表达式结果
 * @param res
 */
void print_expression_result(expression_result_t *res) {
    switch (res->type) {
        case expression_result_type_int:
            printf("expression_result_type_int:%d\n", res->value.i);
            break;
        case expression_result_type_double:
            printf("expression_result_type_double:%f\n", res->value.d);
            break;
        case expression_result_type_string:
            printf("expression_result_type_string:%s\n", res->value.s);
            break;
        case expression_result_type_bool:
            printf("expression_result_type_bool:%d\n", res->value.b);
            break;
        case expression_result_type_variable:
            printf("expression_result_type_variable:%s\n", res->value.s);
            break;
    }
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