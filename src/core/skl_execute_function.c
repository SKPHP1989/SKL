/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "skl_execute_function.h"
extern hash_t *global_function_table;
extern hash_t *global_variable_table;

/**
 * 
 * @param fe
 * @param variable_table
 * @return 
 */
expression_result_t *execute_function_expression(function_expression_t *fe, hash_t *variable_table) {
    expression_result_t *er;
    function_t *function;
    function = (function_t *) find_hash(global_function_table, fe->function_name, strlen(fe->function_name));
    if (is_empty(function)) {
        error_exception("Function:%s not found!", fe->function_name);
    }
    // 函数变量
    hash_t *function_variable_table = create_hash();
    //
    insert_function_params(function, function_variable_table, variable_table, fe->params);
    //
    return execute_statement(function->statement_list, function_variable_table);
}

/**
 * 
 * @param function_name
 * @param function_variable_table
 * @param variable_table
 * @param param_list
 */
void insert_function_params(function_t *function, hash_t *function_variable_table, hash_t *variable_table, expression_list_t *param_list) {
    expression_list_item_t *item = param_list->top;
    param_list_item_t *param_item = function->param_list->top;
    variable_t *var;
    expression_result_t *res;
    while (param_item) {
        if (is_empty(item) && is_not_empty(param_item)) {
            error_exception("Function:%s's parameter:%s need input completely!", function->identifier, param_item->identifier);
        }
        res = execute_expression(item->expression, variable_table);
        var = convert_expression_result_to_variable(param_item->identifier, res);
        insert_or_update_hash(function_variable_table, param_item->identifier, strlen(param_item->identifier), (void *) var);
        item = item->next;
        param_item = param_item->next;
    }
}