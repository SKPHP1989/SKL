/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute.h
 * Author: lij25
 *
 * Created on 2019年12月30日, 上午11:16
 */

#ifndef SKL_EXECUTE_H
#define SKL_EXECUTE_H

#include "skl_core.h"

typedef struct expression_result_s expression_result_t;

enum expression_result_type_e {
    expression_result_type_int = 1,
    expression_result_type_double,
    expression_result_type_string,
    expression_result_type_bool,
    expression_result_type_variable,
};

struct expression_result_s {
    enum expression_result_type_e type;

    union {
        int b;
        int i;
        double d;
        char *s;
    } value;
};

void execute();

void before_execute();

void after_execute();

expression_result_t *execute_assign_expression(assign_expression_t *ae, hash_t *variable_table);

expression_result_t *execute_expression(expression_t *expression, hash_t *variable_table);

expression_result_t *execute_primary_expression(primary_expression_t *pe);

expression_result_t *execute_function_expression(function_expression_t *fe, hash_t *function_variable_table);

expression_result_t *execute_binary_expression(binary_expression_t *be, hash_t *variable_table);

void print_expression_result(expression_result_t *res);
#endif /* SKL_EXECUTE_H */

