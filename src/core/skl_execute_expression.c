/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute_expression.c
 * Author: lij25
 *
 * Created on 2020年1月15日, 下午2:57
 */

#include "skl_execute_expression.h"
#include "skl_execute_operate.h"
#include "skl_execute_function.h"
#include "skl_execute_debug.h"

/**
 * 
 * @param et
 * @param variable_table
 * @return 
 */
expression_result_t *execute_expression_statement(expression_statement_t *et, hash_t *variable_table) {
    expression_t *e = et->expression;
    return execute_expression(e, variable_table);
}

/**
 * 
 * @param expression
 * @param variable_table
 * @return 
 */
expression_result_t *execute_expression(expression_t *e, hash_t *variable_table) {
    switch (e->type) {
        case expression_type_assign:
            return execute_assign_expression(e->expression.assign, variable_table);
            break;
        case expression_type_func:
            return execute_function_expression(e->expression.function, variable_table);
            break;
        case expression_type_binary:
            return execute_binary_expression(e->expression.binary, variable_table);
            break;
        case expression_type_primary:
            return execute_primary_expression(e->expression.primary, variable_table);
            break;
        default:
            error_exception("Undefined epression type(%d)!", e->type);
    }
}

/**
 * 执行赋值表达式
 * @param ae
 * @return
 */
expression_result_t *execute_assign_expression(assign_expression_t *ae, hash_t *variable_table) {
    expression_result_t *res = execute_expression(ae->expression, variable_table);
    variable_t *v = convert_expression_result_to_variable(ae->identifier, res);
    insert_or_update_hash(variable_table, ae->identifier, strlen(ae->identifier), (void *) v);
    return res;
}

/**
 * 
 * @param res
 * @return 
 */
variable_t *convert_expression_result_to_variable(char *identifier, expression_result_t *res) {
    switch (res->type) {
        case expression_result_type_int:
            return create_integer_variable(identifier, res->value.i);
            break;
        case expression_result_type_double:
            return create_double_variable(identifier, res->value.d);
            break;
        case expression_result_type_string:
            return create_string_variable(identifier, res->value.s, strlen(res->value.s));
            break;
        case expression_result_type_bool:
            return create_bool_variable(identifier, res->value.b);
            break;
        case expression_result_type_null:
            return create_null_variable(identifier);
            break;
        default:
            error_exception("Undefined assign:%s type(%d)!", identifier, res->type);
    }
}

/**
 * 执行二元表达式
 * @param be
 * @return
 */
expression_result_t *execute_binary_expression(binary_expression_t *be, hash_t *variable_table) {
    expression_result_t *left_res, *right_res, *res;
    left_res = execute_expression(be->left, variable_table);
    right_res = execute_expression(be->right, variable_table);
    switch (be->action) {
        case expression_action_add:
            res = operate_add(left_res, right_res);
            break;
        case expression_action_sub:
            res = operate_sub(left_res, right_res);
            break;
        case expression_action_mul:
            res = operate_mul(left_res, right_res);
            break;
        case expression_action_div:
            res = operate_div(left_res, right_res);
            break;
        case expression_action_gt:
            res = operate_gt(left_res, right_res);
            break;
        case expression_action_ge:
            res = operate_ge(left_res, right_res);
            break;
        case expression_action_lt:
            res = operate_lt(left_res, right_res);
            break;
        case expression_action_le:
            res = operate_lt(left_res, right_res);
            break;
        case expression_action_ne:
            res = operate_ne(left_res, right_res);
            break;
        case expression_action_eq:
            res = operate_eq(left_res, right_res);
            break;
        default:
            error_exception("Undefined expression action(%d)!", be->action);
    }
    print_expression_result(res);
    return res;
}

/**
 * 执行基础表达式
 * @param pe
 * @param variable_table
 * @return 
 */
expression_result_t *execute_primary_expression(primary_expression_t *pe, hash_t *variable_table) {
    expression_result_t *res = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    switch (pe->type) {
        case value_type_integer:
            res->type = expression_result_type_int;
            res->value.i = pe->u.i;
            break;
        case value_type_double:
            res->type = expression_result_type_double;
            res->value.d = pe->u.d;
            break;
        case value_type_string:
            res->type = expression_result_type_string;
            res->value.s = pe->u.string;
            break;
        case value_type_identifier:
            convert_variable_to_result(pe->u.identifier, variable_table, res);
            break;
        case value_type_bool:
            res->type = expression_result_type_bool;
            res->value.b = pe->u.b;
            break;
        case value_type_invalid:
        default:
            error_exception("Undefined value type!");
    }
    return res;
}

void *convert_variable_to_result(char *identifier, hash_t *variable_table, expression_result_t *res) {
    variable_t *v = (variable_t *) find_hash(variable_table, identifier, strlen(identifier));
    if (is_empty(v)) {
        error_exception("Variable:%s is undefined!", identifier);
    }
    switch (v->type) {
        case variable_type_null:
            res->type = expression_result_type_null;
            break;
        case variable_type_bool:
            res->type = expression_result_type_bool;
            res->value.b = v->value.b;
            break;
        case variable_type_int:
            res->type = expression_result_type_int;
            res->value.i = v->value.i;
            break;
        case variable_type_double:
            res->type = expression_result_type_bool;
            res->value.d = v->value.d;
            break;
        case variable_type_string:
            res->type = expression_result_type_string;
            res->value.s = v->value.str;
            break;
        default:
            error_exception("Undefined variable:%s type!", identifier);
    }
}

/**
 * 
 * @return 
 */
expression_result_t *create_null_result() {
    expression_result_t *res = (expression_result_t *) memory_alloc(sizeof (expression_result_t));
    res->type = expression_result_type_null;
    return res;
}