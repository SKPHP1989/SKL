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

#include "skl_core.h"

typedef struct variable_s variable_t;

enum variable_type_e {
    variable_type_null = 1,
    variable_type_int,
    variable_type_double,
    variable_type_string
};

struct variable_s {
    variable_type_e type;
    char *identifier;
    union {
        char *str;
        unsigned int str_len;
        int i;
        double d;
    } value;
};

variable_t *create_string_variable(char *identifier, char *str, int str_len);

variable_t *create_integer_variable(char *identifier, int i);

variable_t *create_double_variable(char *identifier, double d);

variable_t *create_null_variable(char *identifier);

#endif /* SKL_VARIABLE_H */

