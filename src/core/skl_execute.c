/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "skl_execute.h"
#include "skl_execute_expression.h"
#include "skl_execute_include.h"

extern hash_t *global_function_table;
extern hash_t *global_variable_table;
extern hash_t *global_script_table;
extern statement_list_t *global_statement_list;

/**
 * 执行
 */
void execute() {
    execute_statement(global_variable_table);
}

/**
 * 执行语句
 */
void execute_statement(hash_t *variable_table) {
    int is_include = 0;
    statement_list_item_t *current_p, *current;
    current = global_statement_list->top;
    execute_before();
    while (current) {
        current_p = current;
        statement_t *statement = current->statement;
        switch (statement->type) {
            case statement_type_expression:
                execute_expression_statement(statement->u.e, variable_table);
                break;
            case statement_type_return:
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
                execute_include_statment(statement->u.in);
                is_include = 1;
                break;
            default:
                error_exception("Undefined statement type(%d)!", statement->type);
        }
        // 回到头部
        if (is_include) {
            current = global_statement_list->top;
            is_include = 0;
        } else {
            current = current->next;
        }
        global_statement_list->top = current;
        //內存释放
        memory_free(statement);
        memory_free(current_p);
    }
    execute_after();
}

/**
 * 
 */
void execute_before() {
    printf("before_excute\n");
}

/**
 * 
 */
void execute_after() {
    printf("after_excute\n");
}