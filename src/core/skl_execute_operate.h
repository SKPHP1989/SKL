//
// Created by lij25 on 2020/1/8.
//

#ifndef SKL_EXECUTE_OPERATE_H
#define SKL_EXECUTE_OPERATE_H

#include "skl_core.h"
#include "skl_execute.h"

expression_result_t *operate_add(expression_result_t *left, expression_result_t *right);

expression_result_t *operate_sub(expression_result_t *left, expression_result_t *right);

expression_result_t *operate_mul(expression_result_t *left, expression_result_t *right);

expression_result_t *operate_div(expression_result_t *left, expression_result_t *right);

expression_result_t *operate_gt(expression_result_t *left, expression_result_t *right);

expression_result_t *operate_ge(expression_result_t *left, expression_result_t *right);

expression_result_t *operate_lt(expression_result_t *left, expression_result_t *right);

expression_result_t *operate_le(expression_result_t *left, expression_result_t *right);

expression_result_t *operate_ne(expression_result_t *left, expression_result_t *right);

expression_result_t *operate_eq(expression_result_t *left, expression_result_t *right);


void
operate_method_value(expression_result_t *left, expression_result_t *right, int *left_i, int *right_i, double *left_d,
                     double *right_d, int *left_value_type, int *right_value_type);

#endif //SKL_EXECUTE_OPERATE_H
