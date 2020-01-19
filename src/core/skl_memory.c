/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "skl_core.h"
#include "skl_memory.h"

void *memory_alloc(int size) {
    return (void *) malloc(size);
}

void memory_free(void *p) {
    free(p);
}