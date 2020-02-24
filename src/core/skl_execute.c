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
#include "skl_execute_if.h"
#include "skl_execute_for.h"

extern global_info_t global_info;

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
statement_control_t *execute_statement(statement_list_t *statement_list, hash_t *variable_table) {
    // 空语句列表
    if (is_empty(statement_list)) {
        return create_default_statement_control();
    }
    int is_include = 0, is_break = 0;
    statement_control_t *control_exe = NULL, *control_res = NULL;
    statement_list_item_t *current, *old_top;
    old_top = current = statement_list->top;
    //
    while (current) {
        statement_t *statement = current->statement;
        switch (statement->type) {
            case statement_type_expression:
                execute_expression_statement(statement->u.e, variable_table);
                break;
            case statement_type_return:
                control_exe = execute_return_statement(statement->u.r, variable_table);
                break;
            case statement_type_if:
                control_exe = execute_if_statement(statement->u.i, variable_table);
                break;
            case statement_type_continue:
                control_exe = execute_continue_statement();
                break;
            case statement_type_global:
                break;
            case statement_type_for:
                control_exe = execute_for_statement(statement->u.f, variable_table);
                break;
            case statement_type_break:
                control_exe = execute_break_statement();
                break;
            case statement_type_while:
                control_exe = execute_while_statement(statement->u.w, variable_table);
                break;
            case statement_type_include:
                execute_include_statment(statement->u.in, statement_list);
                is_include = 1;
                break;
            default:
                error_exception("Undefined statement type(%d)!", statement->type);
        }
        // 判断运行的语句值并生成结果集
        if (is_not_empty(control_exe)) {
            switch (control_exe->type) {
                case statement_control_type_return:
                case statement_control_type_break:
                case statement_control_type_continue:
                    control_res = control_exe;
                    is_break = 1;
                    break;
                case statement_control_type_default:
                default:
                    break;
            }
        }
        if (is_break) {
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
    //沒有运行值
    if (is_empty(control_res)) {
        control_res = create_default_statement_control();
    }
    return control_res;
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
    switch (v->value->type) {
        case zvalue_type_string:
            memory_free(v->value->value.str.val);
            break;
        case zvalue_type_null:
        case zvalue_type_bool:
        case zvalue_type_integer:
        case zvalue_type_double:
        default:
            break;
    }
    memory_free(v->value);
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
    if (is_empty(statement_list)) {
        return;
    }
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

/**
 * 创建默认语句控制
 * @return 
 */
statement_control_t *create_default_statement_control() {
    statement_control_t *control_default;
    control_default = (statement_control_t *) memory_alloc(sizeof (statement_control_t));
    control_default->type = statement_control_type_default;
    control_default->result = create_null_zvalue();
    return control_default;
}

/**
 * 创建空语句控制
 * @return 
 */
statement_control_t *create_null_statement_control() {
    statement_control_t *control_null;
    control_null = (statement_control_t *) memory_alloc(sizeof (statement_control_t));
    control_null->type = statement_control_type_default;
    control_null->result = NULL;
    return control_null;
}

/**
 * 转换变量为表达式结果
 * @param identifier
 * @param variable_table
 * @param v
 * @return 
 */
zvalue_t *find_variable_value(char *identifier, hash_t *variable_table) {
    variable_t *v = (variable_t *) find_hash(variable_table, identifier, strlen(identifier));
    if (is_empty(v)) {
        error_exception("Variable:%s is undefined!", identifier);
    }
    return v->value;
}

/**
 * 值转化为布尔值
 * @param res
 * @return 
 */
int zvalue_convert_bool(zvalue_t *res) {
    int bool = BOOL_FALSE;
    switch (res->type) {
        case zvalue_type_integer:
            bool = res->value.i == 0 ? BOOL_FALSE : BOOL_TURE;
            break;
        case zvalue_type_double:
            bool = res->value.d == 0 ? BOOL_FALSE : BOOL_TURE;
            break;
        case zvalue_type_string:
            bool = atoi(res->value.str.val) == 0 ? BOOL_FALSE : BOOL_TURE;
            break;
        case zvalue_type_bool:
            bool = res->value.b == 0 ? BOOL_FALSE : BOOL_TURE;
            break;
        case zvalue_type_null:
        default:
            break;
    }
    return bool;
}