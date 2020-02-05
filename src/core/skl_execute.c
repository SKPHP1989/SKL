/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "skl_core.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"
#include "skl_execute.h"
#include "skl_execute_expression.h"
#include "skl_execute_include.h"
#include "skl_execute_return.h"

extern global_info_t global_info.info;

/**
 * 执行
 */
void execute() {
    register_all_internal_function();
    execute_before();
    execute_statement(global_info.statement_list, global_info.variable_table);
    destroy_hash(global_info.variable_table);
    execute_after();
}

/**
 * 执行语句
 * @param statement_list
 * @param variable_table
 * @return 
 */
expression_result_t *execute_statement(statement_list_t *statement_list, hash_t *variable_table) {
    // 空语句列表
    if (is_empty(statement_list)) {
        return create_null_result();
    }
    int is_include = 0, is_return = 0;
    expression_result_t *res = NULL;
    statement_list_item_t *current, *old_top;
    old_top = current = statement_list->top;
    while (current) {
        statement_t *statement = current->statement;
        switch (statement->type) {
            case statement_type_expression:
                execute_expression_statement(statement->u.e, variable_table);
                break;
            case statement_type_return:
                res = execute_return_statement(statement->u.r, variable_table);
                is_return = 1;
                break;
            case statement_type_if:
                break;
            case statement_type_continue:
                break;
            case statement_type_global:
                break;
            case statement_type_for:
                break;
            case statement_type_break:
                break;
            case statement_type_include:
                execute_include_statment(statement->u.in, statement_list);
                is_include = 1;
                break;
            default:
                error_exception("Undefined statement type(%d)!", statement->type);
        }
        // 跳出
        if (is_return) {
            break;
        }
        // 回到头部
        if (is_include) {
            current = statement_list->top;
            is_include = 0;
        } else {
            current = current->next;
        }
        // 头部
        statement_list->top = current;
    }
    statement_list->top = old_top;
    if (is_empty(res)) {
        res = create_null_result();
    }
    return res;
}

/**
 * 执行前
 */
void execute_before() {
}

/**
 * 执行后
 */
void execute_after() {
    destroy_statement_list(global_info.statement_list);
    destroy_hash_callback(global_info.function_table, destroy_function_hash_callback);
    destroy_hash_callback(global_info.variable_table, destroy_variable_hash_callback);
    destroy_hash(global_info.script_table);
}

/**
 * 
 * @param data
 */
void destroy_variable_hash_callback(void *data) {
    variable_t *v = (variable_t *) data;
    memory_free(v->identifier);
    switch (v->type) {
        case variable_type_string:
            memory_free(v->value.str.val);
            break;
        case variable_type_null:
        case variable_type_bool:
        case variable_type_int:
        case variable_type_double:
        default:
            break;
    }
    memory_free(v);
}

/**
 * 
 * @param data
 */
void destroy_function_hash_callback(void *data) {
    function_t *f = (function_t *) data;
    if (!f->is_native) {
        destroy_statement_list(f->statement_list);
        param_list_t *param_list = f->param_list;
        param_list_item_t *param_item = param_list->top;
        while (param_item) {
            memory_free(param_item->identifier);
            param_item = param_item->next;
        }
        memory_free(param_list);
    }
    memory_free(f->identifier);
    memory_free(f);
}

/**
 * 销毁语句列表
 * @param statement_list
 */
void destroy_statement_list(statement_list_t *statement_list) {
    statement_list_item_t *current;
    statement_t *sm;
    current = statement_list->top;
    while (current) {
        sm = current->statement;
        switch (sm->type) {
            case statement_type_if:
                memory_free(sm->u.i->expression);
                destroy_statement_list(sm->u.i->if_statement_list);
                destroy_statement_list(sm->u.i->else_statement_list);
                break;
            case statement_type_for:
                memory_free(sm->u.f->before);
                memory_free(sm->u.f->condition);
                memory_free(sm->u.f->after);
                destroy_statement_list(sm->u.f->statement_list);
                break;
            case statement_type_expression:
                memory_free(sm->u.e);
                break;
            case statement_type_return:
                memory_free(sm->u.r->expression);
                break;
            case statement_type_include:
                memory_free(sm->u.in->filename);
                break;
            case statement_type_global:
            case statement_type_break:
            case statement_type_continue:
            default:
                break;
        }
        memory_free(current->statement);
        current = current->next;
    }
    memory_free(statement_list);
}