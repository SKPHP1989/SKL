/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute_function.h
 * Author: lij25
 *
 * Created on 2020年1月13日, 下午5:21
 */

#ifndef SKL_EXECUTE_FUNCTION_H
#define SKL_EXECUTE_FUNCTION_H
#include "skl_core.h"
#include "skl_execute.h"

expression_result_t *execute_function_expression(function_expression_t *fe, hash_t *variable_table);

#endif /* SKL_EXECUTE_FUNCTION_H */