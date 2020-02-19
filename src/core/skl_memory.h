/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_memory.h
 * Author: lij25
 *
 * Created on 2019年12月30日, 上午11:13
 */

#ifndef SKL_MEMORY_H
#define SKL_MEMORY_H

void *memory_alloc(int size);
void memory_free(void *p);
void memory_copy(void *dest, void *source, size_t size);
#endif /* SKL_MEMORY_H */

