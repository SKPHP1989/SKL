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
#include "skl_execute_if.h"

/**
 * 
 * @param ifs
 * @param variable_table
 * @return 
 */
statement_control_t *execute_if_statement(if_statement_t *ifs, hash_t *variable_table) {
    zvalue_t *compare = execute_expression(ifs->expression, variable_table);
    int bool = zvalue_convert_bool(compare);
    if (bool) {
        return execute_statement(ifs->if_statement_list, variable_table);
    } else {
        return execute_statement(ifs->else_statement_list, variable_table);
    }
}