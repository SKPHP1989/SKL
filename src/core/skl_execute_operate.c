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
 *
 * @param left
 * @param right
 * @return
 */
expression_result_t *operate_add(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->type = expression_result_type_int;
        result->value.i = left_i + right_i;
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->type = expression_result_type_double;
        result->value.d = left_i + right_d;
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
        result->type = expression_result_type_double;
        result->value.d = left_d + right_i;
    } else {
        result->type = expression_result_type_double;
        result->value.d = left_d + right_d;
    }
    return result;
}

/**
 *
 * @param left
 * @param right
 * @return
 */
expression_result_t *operate_sub(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->type = expression_result_type_int;
        result->value.i = left_i - right_i;
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->type = expression_result_type_double;
        result->value.d = left_i - right_d;
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
        result->type = expression_result_type_double;
        result->value.d = left_d - right_i;
    } else {
        result->type = expression_result_type_double;
        result->value.d = left_d - right_d;
    }
    return result;
}

/**
 *
 * @param left
 * @param right
 * @return
 */
expression_result_t *operate_mul(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->type = expression_result_type_int;
        result->value.i = left_i * right_i;
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->type = expression_result_type_double;
        result->value.d = left_i * right_d;
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
        result->type = expression_result_type_double;
        result->value.d = left_d * right_i;
    } else {
        result->type = expression_result_type_double;
        result->value.d = left_d * right_d;
    }
    return result;
}

/**
 *
 * @param left
 * @param right
 * @return
 */
expression_result_t *operate_div(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->type = expression_result_type_int;
        result->value.i = left_i / right_i;
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->type = expression_result_type_double;
        result->value.d = left_i / right_d;
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
        result->type = expression_result_type_double;
        result->value.d = left_d / right_i;
    } else {
        result->type = expression_result_type_double;
        result->value.d = left_d / right_d;
    }
    return result;
}

/**
 *
 * @param left
 * @param right
 * @return
 */
expression_result_t *operate_gt(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = expression_result_type_bool;
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->value.b = (int) left_i > right_i;
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->value.b = (int) left_i > right_d;
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
        result->value.b = (int) left_d > right_i;
    } else {
        result->value.b = (int) left_d > right_d;
    }
    return result;
}

/**
 *
 * @param left
 * @param right
 * @return
 */
expression_result_t *operate_ge(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = expression_result_type_bool;
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->value.b = (int) (left_i >= right_i);
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->value.b = (int) (left_i >= right_d);
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
        result->value.b = (int) left_d >= right_i;
    } else {
        result->value.b = (int) left_d >= right_d;
    }
    return result;
}

/**
 *
 * @param left
 * @param right
 * @return
 */
expression_result_t *operate_lt(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = expression_result_type_bool;
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->value.b = (int) left_i < right_i;
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->value.b = (int) left_i < right_d;
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
        result->value.b = (int) left_d < right_i;
    } else {
        result->value.b = (int) left_d < right_d;
    }
    return result;
}

/**
 *
 * @param left
 * @param right
 * @return
 */
expression_result_t *operate_le(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = expression_result_type_bool;
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->value.b = (int) left_i <= right_i;
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->value.b = (int) left_i <= right_d;
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
        result->value.b = (int) left_d <= right_i;
    } else {
        result->value.b = (int) left_d <= right_d;
    }
    return result;
}

/**
 *
 * @param left
 * @param right
 * @return
 */
expression_result_t *operate_ne(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = expression_result_type_bool;
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->value.b = (int) (left_i != right_i);
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->value.b = (int) (left_i != right_i);
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
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
expression_result_t *operate_eq(expression_result_t *left, expression_result_t *right) {
    expression_result_t *result = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    int left_i, right_i;
    double left_d, right_d;
    int left_value_type, right_value_type;
    //
    operate_method_value(left, right, &left_i, &right_i, &left_d, &right_d, &left_value_type, &right_value_type);
    //
    result->type = expression_result_type_bool;
    if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_int) {
        result->value.b = (int) (left_i == right_i);
    } else if (left_value_type == expression_result_type_int && right_value_type == expression_result_type_double) {
        result->value.b = (int) (left_i == right_d);
    } else if (left_value_type == expression_result_type_double && right_value_type == expression_result_type_int) {
        result->value.b = (int) (left_d == right_i);
    } else {
        result->value.b = (int) (left_d == right_i);
    }
    return result;
}

/**
 * 
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
operate_method_value(expression_result_t *left, expression_result_t *right, int *left_i, int *right_i, double *left_d,
        double *right_d, int *left_value_type, int *right_value_type) {
    //
    switch (left->type) {
        case expression_result_type_int:
            *left_i = left->value.i;
            *left_value_type = expression_result_type_int;
            break;
        case expression_result_type_double:
            *left_d = left->value.d;
            *left_value_type = expression_result_type_double;
            break;
        case expression_result_type_string:
            *left_i = atoi(left->value.s);
            *left_value_type = expression_result_type_int;
            break;
        case expression_result_type_bool:
            *left_i = left->value.b;
            *left_value_type = expression_result_type_int;
            break;
    }
    switch (right->type) {
        case expression_result_type_int:
            *right_i = right->value.i;
            *right_value_type = expression_result_type_int;
            break;
        case expression_result_type_double:
            *right_d = right->value.d;
            *right_value_type = expression_result_type_double;
            break;
        case expression_result_type_string:
            *right_i = atoi(right->value.s);
            *right_value_type = expression_result_type_int;
            break;
        case expression_result_type_bool:
            *right_i = right->value.b;
            *right_value_type = expression_result_type_int;
            break;
    }
}