/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute_if.h
 * Author: ASUS
 *
 * Created on 2020年2月17日, 下午6:13
 */

#ifndef SKL_EXECUTE_IF_H
#define SKL_EXECUTE_IF_H

statement_control_t *execute_for_statement(for_statement_t *fors, hash_t *variable_table);

int expression_result_to_bool(expression_result_t *res);

#endif /* SKL_EXECUTE_IF_H */

