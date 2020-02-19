/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_variable.h
 * Author: lij25
 *
 * Created on 2019年12月30日, 上午11:10
 */

#ifndef SKL_VARIABLE_H

#define SKL_VARIABLE_H


typedef struct variable_s variable_t;

struct variable_s {
    char *identifier;
    zvalue_t *value;
};

variable_t *create_variable(char *identifier, zvalue_t *value);

#endif /* SKL_VARIABLE_H */

