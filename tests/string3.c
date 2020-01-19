/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   string3.c
 * Author: lij25
 *
 * Created on 2020年1月19日, 下午2:36
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ty_s ty_t;

struct ty_s {
    int id;

    union {
        char *name;
        struct {
            char *val;
            int len;
        } str;
    } v;
};

/*
 * 
 */
int main(int argc, char** argv) {
    char *s = (char *) malloc(sizeof ("test"));
    strcpy(s, "test");
    ty_t *t = (ty_t *) malloc(sizeof (ty_t));
    t->id = 1;
    t->v.str.val = s;
    t->v.str.len = strlen(s);
    printf("t->v.str = %s \n", t->v.str.val);
    return 0;
}

