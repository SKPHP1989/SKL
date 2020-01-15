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

#include "skl_execute_include.h"

extern statement_list_t *global_statement_list, *global_include_statement_list;
extern int global_include_mode;
extern hash_t *global_script_table;

/**
 * 执行include
 * @param is
 */
void execute_include_statment(include_statement_t *is) {
    char *filename = is->filename;
    FILE *input = fopen(filename, FILE_OPT_READ);
    if (is_empty(input)) {
        error_exception("File:%s can not be read!", filename);
    }
    global_include_mode = 1;
    yyrestart(input);
    if (yyparse()) {
        error_exception("System parse file:%s failed !", filename);
    }
    global_include_mode = 0;
    // 脚本hash
    if (!find_hash(global_script_table, filename, strlen(filename))) {
        insert_or_update_hash(global_script_table, filename, strlen(filename), filename);
    }
    merge_execute_statement_list();
    fclose(input);
    memory_free(is);
}

/**
 * 执行语句列表合并
 */
void merge_execute_statement_list() {
    global_include_statement_list->tail->next = global_statement_list->top->next;
    global_statement_list->top = global_include_statement_list->top;
    //reset
    global_include_statement_list->top = global_include_statement_list->tail = NULL;
}