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
#include "skl_core.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"
#include "skl_execute.h"
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
zvalue_t *execute_expression_statement(expression_statement_t *et, hash_t *variable_table) {
    expression_t *e = et->expression;
    return execute_expression(e, variable_table);
}

/**
 * 
 * @param expression
 * @param variable_table
 * @return 
 */
zvalue_t *execute_expression(expression_t *e, hash_t *variable_table) {
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
zvalue_t *execute_assign_expression(assign_expression_t *ae, hash_t *variable_table) {
    zvalue_t *res = execute_expression(ae->expression, variable_table);
    res->is_temp = 0;
    variable_t *v = create_variable(ae->identifier, res);
    insert_or_update_hash(variable_table, ae->identifier, strlen(ae->identifier), (void *) v);
    return res;
}

/**
 * 执行二元表达式
 * @param be
 * @return
 */
zvalue_t *execute_binary_expression(binary_expression_t *be, hash_t *variable_table) {
    zvalue_t *left_res, *right_res, *res;
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
            res = operate_le(left_res, right_res);
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
    release_temp_zvalue(left_res);
    release_temp_zvalue(right_res);
    return res;
}

/**
 * 执行基础表达式
 * @param pe
 * @param variable_table
 * @return 
 */
zvalue_t *execute_primary_expression(primary_expression_t *pe, hash_t *variable_table) {
    zvalue_t *res;
    switch (pe->type) {
        case value_type_integer:
            res = create_integer_zvalue(pe->u.i);
            break;
        case value_type_double:
            res = create_double_zvalue(pe->u.d);
            break;
        case value_type_string:
            res = create_string_zvalue(pe->u.string, strlen(pe->u.string));
            break;
        case value_type_identifier:
            res = find_variable_value(pe->u.identifier, variable_table);
            break;
        case value_type_bool:
            res = create_bool_zvalue(pe->u.b);
            break;
        case value_type_invalid:
        default:
            error_exception("Undefined value type!");
    }
    return res;
}
