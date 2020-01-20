/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_execute_include.h
 * Author: lij25
 *
 * Created on 2020年1月15日, 下午2:50
 */

#ifndef SKL_EXECUTE_INCLUDE_H
#define SKL_EXECUTE_INCLUDE_H

void execute_include_statment(include_statement_t *is, statement_list_t *statement_list);

void merge_execute_statement_list(statement_list_t *statement_list);

#endif /* SKL_EXECUTE_INCLUDE_H */