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

#ifndef SKL_VALUE_H
#define SKL_VALUE_H


typedef struct zvalue_s zvalue_t;

enum zvalue_type_e {
    zvalue_type_null = 1,
    zvalue_type_bool,
    zvalue_type_integer,
    zvalue_type_double,
    zvalue_type_string
};

struct zvalue_s {
    enum zvalue_type_e type;
    int refer;
    int is_temp;

    union {
        int b;

        struct {
            char *val;
            unsigned int len;
        } str;
        int i;
        double d;
    } value;
};

zvalue_t *create_string_zvalue(char *str, int str_len);

zvalue_t *create_integer_zvalue(int i);

zvalue_t *create_double_zvalue(double d);

zvalue_t *create_null_zvalue();

zvalue_t *create_bool_zvalue(int b);

void release_temp_zvalue(zvalue_t *val);

#endif /* SKL_VARIABLE_H */

