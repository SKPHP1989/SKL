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

/**
 * 执行返回语句
 * @param rs
 * @param variable_table
 * @return 
 */
expression_result_t *execute_return_statement(return_statement_t *rs, hash_t *variable_table) {
    return execute_expression(rs->expression, variable_table);
}