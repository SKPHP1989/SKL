/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "skl_core.h"
#include "skl_memory.h"

/**
 * 内存分配
 */
void *memory_alloc(int size) {
    return (void *) malloc(size);
}

/**
 * 内存释放
 */
void memory_free(void *p) {
    if (is_not_empty(p)) {
        free(p);
    }
}