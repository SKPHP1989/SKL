/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "skl_execute.h"

extern hash_t *global_function_table;
extern hash_t *global_variable_table;
extern statement_list_t *global_statement_list;

/**
 * 执行语句
 */
void execute() {
    statement_list_item_t *current = global_statement_list->top;
    while (current) {
        statement_t *statement = current->statement;
        switch (statement->type) {
            case statement_type_expression:
                execute_expression(statement->u.e->expression);
                printf("statement_type_expression\n");
                break;
            case statement_type_return:
                printf("statement_type_return\n");
                break;
            case statement_type_if:
                printf("statement_type_if\n");
                break;
            case statement_type_continue:
                printf("statement_type_continue\n");
                break;
            case statement_type_global:
                printf("statement_type_global\n");
                break;
            case statement_type_for:
                printf("statement_type_for\n");
                break;
            case statement_type_break:
                printf("statement_type_break\n");
                break;
        }
        current = current->next;
    }
}

/**
 * 执行表达式
 * @param expression
 */
void execute_expression(expression_t *expression) {
    switch (expression->type) {
        case expression_type_assign:
            break;
        case expression_type_func:
            execute_function_expression(expression->expression.function);
            break;
        case expression_type_binary:;
            printf("expression_type_binary\n");
            break;
        case expression_type_primary:
            printf("expression_type_primary\n");
            break;
    }
}

void execute_function_expression(function_expression_t *fe) {
    fe->function_name;
}