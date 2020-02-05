/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute_include.c
 * Author: lij25
 *
 * Created on 2020年1月15日, 下午2:50
 */
#include "skl_core.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"
#include "skl_execute_include.h"

extern global_info_t global_info;

/**
 * 执行include
 * @param is
 */
void execute_include_statment(include_statement_t *is, statement_list_t *statement_list) {
    char *filename = is->filename;
    FILE *input = fopen(filename, FILE_OPT_READ);
    if (is_empty(input)) {
        error_exception("File:%s can not be read!", filename);
    }
    global_info.include_mode = 1;
    yyrestart(input);
    if (yyparse()) {
        error_exception("System parse file:%s failed !", filename);
    }
    global_info.include_mode = 0;
    // 脚本hash
    if (!find_hash(global_info.script_table, filename, strlen(filename))) {
        insert_or_update_hash(global_info.script_table, filename, strlen(filename), filename);
    }
    merge_execute_statement_list(statement_list);
    fclose(input);
}

/**
 * 执行语句列表合并
 */
void merge_execute_statement_list(statement_list_t *statement_list) {
    if (global_info.include_statement_list->tail) {
        global_info.include_statement_list->tail->next = statement_list->top->next;
        statement_list->top = global_info.include_statement_list->top;
    } else {
        statement_list->top = statement_list->top->next;
    }
    //reset
    global_info.include_statement_list->top = global_info.include_statement_list->tail = NULL;
}