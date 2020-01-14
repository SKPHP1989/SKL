/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   string.c
 * Author: lij25
 *
 * Created on 2020年1月14日, 上午10:03
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* substring(char* ch, int pos, int length);

/*
 * 
 */
int main(int argc, char** argv) {

    char *src = "\"2342342\"";
    char *dest = substring(src, 1, 3);
    printf("s1=%s\n", dest);
}

char* substring(char* ch, int pos, int length) {
    char* pch = ch;
    char* subch = (char*) calloc(sizeof (char), length + 1);
    int i;
    pch = pch + pos;
    for (i = 0; i < length; i++) {
        subch[i] = *(pch++);
    }
    subch[length] = '\0'; 
    return subch; 
} 