//
// Created by lij25 on 2020/1/8.
//

#ifndef SKL_EXECUTE_OPERATE_H
#define SKL_EXECUTE_OPERATE_H


zvalue_t *operate_add(zvalue_t *left, zvalue_t *right);

zvalue_t *operate_sub(zvalue_t *left, zvalue_t *right);

zvalue_t *operate_mul(zvalue_t *left, zvalue_t *right);

zvalue_t *operate_div(zvalue_t *left, zvalue_t *right);

zvalue_t *operate_gt(zvalue_t *left, zvalue_t *right);

zvalue_t *operate_ge(zvalue_t *left, zvalue_t *right);

zvalue_t *operate_lt(zvalue_t *left, zvalue_t *right);

zvalue_t *operate_le(zvalue_t *left, zvalue_t *right);

zvalue_t *operate_ne(zvalue_t *left, zvalue_t *right);

zvalue_t *operate_eq(zvalue_t *left, zvalue_t *right);


void
operate_method_value(zvalue_t *left, zvalue_t *right, int *left_i, int *right_i, double *left_d,
                     double *right_d, int *left_zvalue_type, int *right_zvalue_type);

#endif //SKL_EXECUTE_OPERATE_H
