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
#include "skl_execute_return.h"

extern global_info_t global_info;

statement_control_t *execute_global_statement(statement_t *s, hash_t *variable_table) {
    zvalue_t *res = execute_expression(s->u.g->expression, variable_table);
}

/**
 * 执行返回语句
 * @param rs
 * @param variable_table
 * @return 
 */
statement_control_t *execute_return_statement(return_statement_t *rs, hash_t *variable_table) {
    statement_control_t *control_res = create_null_statement_control();
    zvalue_t *expression_res = execute_expression(rs->expression, variable_table);
    control_res->type = statement_control_type_return;
    control_res->result = expression_res;
    return control_res;
}

/**
 * 
 * @param rs
 * @param variable_table
 * @return 
 */
statement_control_t *execute_break_statement() {
    statement_control_t *control_res = create_null_statement_control();
    control_res->type = statement_control_type_break;
    return control_res;
}

/**
 * 
 * @param rs
 * @param variable_table
 * @return 
 */
statement_control_t *execute_continue_statement() {
    statement_control_t *control_res = create_null_statement_control();
    control_res->type = statement_control_type_continue;
    return control_res;
}