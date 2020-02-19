/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute_return.h
 * Author: lij25
 *
 * Created on 2020年1月16日, 下午5:34
 */

#ifndef SKL_EXECUTE_RETURN_H
#define SKL_EXECUTE_RETURN_H

statement_control_t *execute_global_statement(statement_t *s, hash_t *variable_table);

statement_control_t *execute_return_statement(return_statement_t *rs, hash_t *variable_table);

statement_control_t *execute_break_statement();

statement_control_t *execute_continue_statement();

#endif /* SKL_EXECUTE_RETURN_H */

