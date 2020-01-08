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
    while (current) {
        statement_t *statement = current->statement;
        switch (statement->type) {
            case statement_type_expression:
                execute_expression(statement->u.e->expression);
                printf("statement_type_expression\n");
                break;
            case statement_type_return:
                printf("statement_type_return\n");
                break;
            case statement_type_if:
                printf("statement_type_if\n");
                break;
            case statement_type_continue:
                printf("statement_type_continue\n");
                break;
            case statement_type_global:
                printf("statement_type_global\n");
                break;
            case statement_type_for:
                printf("statement_type_for\n");
                break;
            case statement_type_break:
                printf("statement_type_break\n");
                break;
        }
        current = current->next;
    }
}

/**
 * 执行表达式
 * @param expression
 */
expression_result_t *execute_expression(expression_t *expression) {
    printf("operate_res =%d\n", expression->type);
    switch (expression->type) {
        case expression_type_assign:
            execute_assign_expression(expression->expression.assign);
            break;
        case expression_type_func:
            execute_function_expression(expression->expression.function);
            break;
        case expression_type_binary:;
            execute_binary_expression(expression->expression.binary);
            break;
        case expression_type_primary:
            execute_primary_expression(expression->expression.primary);
            break;
    }
}

expression_result_t *execute_assign_expression(assign_expression_t *ae) {
    printf("ae->identifier=%s\n", ae->identifier);
    expression_result_t *res = execute_expression(ae->expression);
    printf("ae->identifier->value=%d\n", res->value.i);
}

/**
 * 执行函数表达式
 * @param fe
 */
expression_result_t *execute_function_expression(function_expression_t *fe) {
    // 函数变量表
    hash_t *function_variable_table = create_hash();
    expression_result_t *er;
    //
    function_t *function;
    function = (function_t *) find_hash(global_function_table, fe->function_name, strlen(fe->function_name));
    if (is_empty(function)) {
        error_exception("Function:%s not be found!", fe->function_name);
    }
}

/**
 *
 * @param be
 * @return
 */
expression_result_t *execute_binary_expression(binary_expression_t *be) {
    expression_result_t *left_res, *right_res, *operate_res;
    left_res = execute_expression(be->left);
    right_res = execute_expression(be->right);
    switch (be->action) {
        case expression_action_add:
            operate_res = operate_add(left_res, right_res);
            break;
        case expression_action_sub:
            operate_res = operate_sub(left_res, right_res);
            break;
        case expression_action_mul:
            operate_res = operate_mul(left_res, right_res);
            break;
        case expression_action_div:
            operate_res = operate_div(left_res, right_res);
            break;
        case expression_action_gt:
            operate_res = operate_gt(left_res, right_res);
            break;
        case expression_action_ge:
            operate_res = operate_ge(left_res, right_res);
            break;
        case expression_action_lt:
            operate_res = operate_lt(left_res, right_res);
            break;
        case expression_action_le:
            operate_res = operate_lt(left_res, right_res);
            break;
        case expression_action_ne:
            operate_res = operate_ne(left_res, right_res);
            break;
    }
    return operate_res;
}

expression_result_t *execute_primary_expression(primary_expression_t *pe) {

}