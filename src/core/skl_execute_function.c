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
}