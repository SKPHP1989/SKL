/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "skl_core.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"
#include "skl_execute.h"
#include "skl_execute_expression.h"
#include "skl_execute_function.h"

extern hash_t *global_function_table;
extern hash_t *global_variable_table;

/**
 * 执行函数表达式
 * @param fe
 * @param variable_table
 * @return 
 */
expression_result_t *execute_function_expression(function_expression_t *fe, hash_t *variable_table) {
    function_t *function;
    expression_result_t *res;
    variable_t *return_v;
    function = (function_t *) find_hash(global_function_table, fe->function_name, strlen(fe->function_name));
    if (is_empty(function)) {
        error_exception("Function:%s not found!", fe->function_name);
    }

    if (!function->is_native) {
        // 函数变量
        hash_t *function_variable_table = create_hash();
        insert_user_function_params(function, function_variable_table, variable_table, fe->params);
        res = execute_statement(function->statement_list, function_variable_table);
        destroy_hash(function_variable_table);
    } else {
        call_params_list_t *call_params_list = insert_internal_function_params(function, variable_table, fe->params);
        return_v = function->func_addr(call_params_list);
        res = convert_variable_to_expression_result(return_v);
    }
    return res;
}

/**
 * 插入函数参数
 * @param function_name
 * @param function_variable_table
 * @param variable_table
 * @param param_list
 */
void insert_user_function_params(function_t *function, hash_t *function_variable_table, hash_t *variable_table, expression_list_t *param_list) {
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

/**
 * 
 * @param function
 * @param variable_table
 * @param param_list
 */
call_params_list_t *insert_internal_function_params(function_t *function, hash_t *variable_table, expression_list_t *param_list) {
    expression_list_item_t *item = param_list->top;
    call_params_list_t *list_param = NULL, *list_param_prev = NULL, *list_param_head = NULL;
    variable_t *var;
    expression_result_t *res;
    char *identifier = memory_alloc(sizeof ("return"));
    strcpy(identifier, "return");
    while (item) {
        res = execute_expression(item->expression, variable_table);
        var = convert_expression_result_to_variable(identifier, res);
        list_param = (call_params_list_t *) memory_alloc(sizeof (call_params_list_t));
        if (is_empty(list_param_head)) {
            list_param_head = list_param;
        }
        if (is_not_empty(list_param_prev)) {
            list_param_prev->next = list_param;
        }
        list_param->var = var;
        list_param->next = NULL;
        list_param_prev = list_param;
        item = item->next;
    }
    return list_param_head;
}