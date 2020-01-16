/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute_debug.c
 * Author: lij25
 *
 * Created on 2020年1月13日, 上午11:39
 */


#include "skl_execute.h"
#include "skl_execute_debug.h"
extern statement_list_t *global_statement_list;

void execute_statement_debug(hash_t *variable_table) {
    statement_list_item_t *item;
    item = global_statement_list->top;
    printf("\n");
    while (item) {
        printf("debug: global_statement_list->%d\n", item->statement->type);
        item = item->next;
    }
}

/**
 * 打印表达式结果
 * @param res
 */
void print_expression_result(expression_result_t *res) {
    switch (res->type) {
        case expression_result_type_int:
            printf("expression_result_type_int:%d\n", res->value.i);
            break;
        case expression_result_type_double:
            printf("expression_result_type_double:%f\n", res->value.d);
            break;
        case expression_result_type_string:
            printf("expression_result_type_string:%s\n", res->value.s);
            break;
        case expression_result_type_bool:
            printf("expression_result_type_bool:%d\n", res->value.b);
            break;
    }
}