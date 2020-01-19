/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute_expression.h
 * Author: lij25
 *
 * Created on 2020年1月15日, 下午2:57
 */

#ifndef SKL_EXECUTE_EXPRESSION_H
#define SKL_EXECUTE_EXPRESSION_H


expression_result_t *execute_expression_statement(expression_statement_t *et, hash_t *variable_table);

expression_result_t *execute_assign_expression(assign_expression_t *ae, hash_t *variable_table);

expression_result_t *execute_expression(expression_t *e, hash_t *variable_table);

expression_result_t *execute_primary_expression(primary_expression_t *pe, hash_t *variable_table);

expression_result_t *execute_binary_expression(binary_expression_t *be, hash_t *variable_table);

variable_t *convert_expression_result_to_variable(char *identifier, expression_result_t *res);

void *convert_variable_to_result(char *identifier, hash_t *variable_table, expression_result_t *res);

expression_result_t *convert_variable_to_expression_result(variable_t *v);

expression_result_t *create_null_result();

#endif /* SKL_EXECUTE_EXPRESSION_H */

