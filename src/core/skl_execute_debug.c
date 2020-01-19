/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute_debug.c
 * Author: lij25
 *
 * Created on 2020年1月13日, 上午11:39
 */

#include "skl_core.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"
#include "skl_execute.h"
#include "skl_execute_debug.h"

/**
 * 打印表达式结果
 * @param res
 */
void print_expression_result(expression_result_t *res) {
    switch (res->type) {
        case expression_result_type_int:
            printf("expression_result_type_int:%d\n", res->value.i);
            break;
        case expression_result_type_double:
            printf("expression_result_type_double:%f\n", res->value.d);
            break;
        case expression_result_type_string:
            printf("expression_result_type_string:%s\n", res->value.s);
            break;
        case expression_result_type_bool:
            printf("expression_result_type_bool:%d\n", res->value.b);
            break;
    }
}

/**
 * 打印表达式结果
 * @param res
 */
void print_variable(variable_t *v) {
    switch (v->type) {
        case variable_type_null:
            printf("variable_type_null:%s\n", "null");
            break;
        case variable_type_int:
            printf("variable_type_int:%d\n", v->value.i);
            break;
        case variable_type_double:
            printf("variable_type_double:%f\n", v->value.d);
            break;
        case variable_type_string:
            printf("variable_type_string:%s\n", v->value.str.val);
            break;
    }
}