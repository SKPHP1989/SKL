/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//
// Created by lij25 on 2020/1
//

#ifndef SKL_EXECUTE_DEBUG_H
#define SKL_EXECUTE_DEBUG_H

void print_expression_result(zvalue_t *v);

void execute_statement_debug(hash_t *variable_table);

void print_variable(variable_t *v);

#endif