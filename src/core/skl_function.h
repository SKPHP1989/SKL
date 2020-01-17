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

#include "skl_core.h"

void register_internal_function(void *function_addr, char *function_name);


variable_t *function_var_dump(call_params_list_t *call_params_list);


#endif /* SKL_FUNCTION_H */