/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_function.h
 * Author: lij25
 *
 * Created on 2019年12月30日, 上午11:14
 */

#ifndef SKL_FUNCTION_H
#define SKL_FUNCTION_H


typedef struct call_params_list_s call_params_list_t;

struct call_params_list_s {
    zvalue_t *value;
    call_params_list_t *next;
};

int register_all_internal_function();

void register_internal_function(char *function_name, void *(*func_addr)(call_params_list_t *));

void *function_var_dump(call_params_list_t *call_params_list);

void *function_sleep(call_params_list_t *call_params_list);

void *function_time(call_params_list_t *call_params_list);

#endif /* SKL_FUNCTION_H */