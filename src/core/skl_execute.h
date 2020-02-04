/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute.h
 * Author: lij25
 *
 * Created on 2019年12月30日, 上午11:16
 */

#ifndef SKL_EXECUTE_H
#define SKL_EXECUTE_H


typedef struct expression_result_s expression_result_t;

enum expression_result_type_e {
    expression_result_type_int = 1,
    expression_result_type_double,
    expression_result_type_string,
    expression_result_type_bool,
    expression_result_type_null,
};

struct expression_result_s {
    enum expression_result_type_e type;
    union {
        int b;
        int i;
        double d;
        char *s;
    } value;
};

void execute();

expression_result_t *execute_statement(statement_list_t *statement_list, hash_t *variable_table);

void execute_before();

void execute_after();

void destroy_statement_list(statement_list_t *statement_list);

#endif /* SKL_EXECUTE_H */

