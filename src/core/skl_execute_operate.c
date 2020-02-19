//
// Created by lij25 on 2020/1/8.
//
#include "skl_core.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"
#include "skl_execute.h"
#include "skl_execute_operate.h"

/**
 * 操作加法
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_add(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->type = zvalue_type_integer;
        result->value.i = left_i + right_i;
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->type = zvalue_type_double;
        result->value.d = left_i + right_d;
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->type = zvalue_type_double;
        result->value.d = left_d + right_i;
    } else {
        result->type = zvalue_type_double;
        result->value.d = left_d + right_d;
    }
    return result;
}

/**
 * 操作减法
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_sub(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->type = zvalue_type_integer;
        result->value.i = left_i - right_i;
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->type = zvalue_type_double;
        result->value.d = left_i - right_d;
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->type = zvalue_type_double;
        result->value.d = left_d - right_i;
    } else {
        result->type = zvalue_type_double;
        result->value.d = left_d - right_d;
    }
    return result;
}

/**
 * 操作乘法
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_mul(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->type = zvalue_type_integer;
        result->value.i = left_i * right_i;
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->type = zvalue_type_double;
        result->value.d = left_i * right_d;
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->type = zvalue_type_double;
        result->value.d = left_d * right_i;
    } else {
        result->type = zvalue_type_double;
        result->value.d = left_d * right_d;
    }
    return result;
}

/**
 * 操作除法
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_div(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->type = zvalue_type_integer;
        result->value.i = left_i / right_i;
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->type = zvalue_type_double;
        result->value.d = left_i / right_d;
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->type = zvalue_type_double;
        result->value.d = left_d / right_i;
    } else {
        result->type = zvalue_type_double;
        result->value.d = left_d / right_d;
    }
    return result;
}

/**
 * 操作大于
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_gt(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = zvalue_type_bool;
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->value.b = (int) left_i > right_i;
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->value.b = (int) left_i > right_d;
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->value.b = (int) left_d > right_i;
    } else {
        result->value.b = (int) left_d > right_d;
    }
    return result;
}

/**
 * 操作大于等于
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_ge(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = zvalue_type_bool;
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->value.b = (int) (left_i >= right_i);
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->value.b = (int) (left_i >= right_d);
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->value.b = (int) left_d >= right_i;
    } else {
        result->value.b = (int) left_d >= right_d;
    }
    return result;
}

/**
 * 操作小于
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_lt(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = zvalue_type_bool;
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->value.b = (int) left_i < right_i;
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->value.b = (int) left_i < right_d;
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->value.b = (int) left_d < right_i;
    } else {
        result->value.b = (int) left_d < right_d;
    }
    return result;
}

/**
 * 操作小于等于
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_le(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = zvalue_type_bool;
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->value.b = (int) left_i <= right_i;
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->value.b = (int) left_i <= right_d;
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->value.b = (int) left_d <= right_i;
    } else {
        result->value.b = (int) left_d <= right_d;
    }
    return result;
}

/**
 * 操作不等于
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_ne(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = zvalue_type_bool;
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->value.b = (int) (left_i != right_i);
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->value.b = (int) (left_i != right_i);
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->value.b = (int) (left_i != right_i);
    } else {
        result->value.b = (int) (left_i != right_i);
    }
    return result;
}

/**
 * 相等操作
 * @param left
 * @param right
 * @return
 */
zvalue_t *operate_eq(zvalue_t *left, zvalue_t *right) {
    zvalue_t *result = create_null_zvalue();
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = zvalue_type_bool;
    if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_integer) {
        result->value.b = (int) (left_i == right_i);
    } else if (left_value_type == zvalue_type_integer && right_value_type == zvalue_type_double) {
        result->value.b = (int) (left_i == right_d);
    } else if (left_value_type == zvalue_type_double && right_value_type == zvalue_type_integer) {
        result->value.b = (int) (left_d == right_i);
    } else {
        result->value.b = (int) (left_d == right_i);
    }
    return result;
}

/**
 * 操作方法的值
 * @param left
 * @param right
 * @param left_i
 * @param right_i
 * @param left_d
 * @param right_d
 * @param left_value_type
 * @param right_value_type
 */
void
operate_method_value(zvalue_t *left, zvalue_t *right, int *left_i, int *right_i, double *left_d,
        double *right_d, int *left_value_type, int *right_value_type) {
    //
    switch (left->type) {
        case zvalue_type_integer:
            *left_i = left->value.i;
            *left_value_type = zvalue_type_integer;
            break;
        case zvalue_type_double:
            *left_d = left->value.d;
            *left_value_type = zvalue_type_double;
            break;
        case zvalue_type_string:
            *left_i = atoi(left->value.str.val);
            *left_value_type = zvalue_type_integer;
            break;
        case zvalue_type_bool:
            *left_i = left->value.b;
            *left_value_type = zvalue_type_integer;
            break;
    }
    switch (right->type) {
        case zvalue_type_integer:
            *right_i = right->value.i;
            *right_value_type = zvalue_type_integer;
            break;
        case zvalue_type_double:
            *right_d = right->value.d;
            *right_value_type = zvalue_type_double;
            break;
        case zvalue_type_string:
            *right_i = atoi(right->value.str.val);
            *right_value_type = zvalue_type_integer;
            break;
        case zvalue_type_bool:
            *right_i = right->value.b;
            *right_value_type = zvalue_type_integer;
            break;
    }
}