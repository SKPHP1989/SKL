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
    expression_result_type_assign
};

struct expression_result_s {
    expression_result_type_e type;
    union {
        int i;
        double d;
        char *s;
    } value;
};

void execute();

void execute_expression(expression_t *expression);

void execute_primary_expression(primary_expression_t *pe);

void execute_function_expression(function_expression_t *fe);

void execute_binary_expression(binary_expression_t *be);

#endif /* SKL_EXECUTE_H */

