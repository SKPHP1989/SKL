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
void print_expression_result(zvalue_t *v) {
    switch (v->type) {
        case zvalue_type_integer:
            printf("zvalue_type_integer:%d\n", v->value.i);
            break;
        case zvalue_type_double:
            printf("zvalue_type_double:%f\n", v->value.d);
            break;
        case zvalue_type_string:
            printf("zvalue_type_string:%s\n", v->value.str.val);
            break;
        case zvalue_type_bool:
            printf("zvalue_type_boll:%d\n", v->value.b);
            break;
    }
}

/**
 * 打印表达式结果
 * @param res
 */
void print_variable(variable_t *v) {
    switch (v->value->type) {
        case zvalue_type_null:
            printf("zvalue_type_null:%s\n", "null");
            break;
        case zvalue_type_integer:
            printf("zvalue_type_integer:%d\n", v->value->value.i);
            break;
        case zvalue_type_double:
            printf("zvalue_type_double:%f\n", v->value->value.d);
            break;
        case zvalue_type_string:
            printf("zvalue_type_string:%s\n", v->value->value.str.val);
            break;
    }
}