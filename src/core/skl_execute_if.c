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

/**
 * 
 * @param ifs
 * @param variable_table
 * @return 
 */
expression_result_t *execute_if_statement(if_statement_t *ifs, hash_t *variable_table){
    expression_result_t *compare = execute_expression_statement(ifs->expression ,variable_table);
    int bool = 0;
    switch(compare->type){
        case expression_result_type_int:
            bool = compare->value.i == 0 ? 0 : 1;
            break;
        case expression_result_type_double:
            bool = compare->value.d == 0 ? 0 : 1;
            break;
        case expression_result_type_string:
            bool = atoi(compare->value.s) == 0 ? 0 : 1;
            break;
        case expression_result_type_bool:
            bool = compare->value.b == 0 ? 0 : 1;
            break;
        case expression_result_type_null:
        default:
            break;
    }
    if(bool){
        return execute_statement(ifs->if_statement_list,variable_table);
    }else{
        return execute_statement(ifs->else_statement_list,variable_table);
    }
}