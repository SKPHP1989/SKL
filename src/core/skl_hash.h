/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   skl_hash.h
 * Author: lij25
 *
 * Created on 2019年12月31日, 下午4:50
 */

#ifndef SKL_HASH_H
#define SKL_HASH_H


#define HASH_MAX_SIZE 0x1000000000

#define HASH_EXPAND_RATIO 0.8
#define HASH_REDUCE_RATIO 0.2
#define HASH_INIT_SIZE 4

typedef struct hash_bucket_s hash_bucket_t;
typedef struct hash_s hash_t;

struct hash_s {
    unsigned int size;
    unsigned int mask;
    unsigned int ele_num;
    float fill_ratio;
    hash_bucket_t *list_head;
    hash_bucket_t *list_tail;
    hash_bucket_t **table;
};

struct hash_bucket_s {
    unsigned long index;
    unsigned int key_len;
    unsigned int index_num;
    char *key;
    void *data;
    hash_bucket_t *list_next;
    hash_bucket_t *list_prev;
    hash_bucket_t *next;
    hash_bucket_t *prev;
};

typedef void (*destroy_hash_callback_func)(void *data);

hash_t *create_hash(void);

hash_bucket_t *create_hash_bucket(char *, unsigned int, int, void *);

void *find_hash(hash_t *, char *, int);

int insert_or_update_hash(hash_t *, char *, unsigned int, void *);

int delete_hash(hash_t *, char *, int);

int expand_hash(hash_t *);

int reduce_hash(hash_t *);

int destroy_hash(hash_t *);

int destroy_hash_callback(hash_t *hash,destroy_hash_callback_func callback);

int index_hash_key(char *key, int);

void foreach_hash(hash_t *);

void dump_hash(hash_t *);

#endif /* SKL_HASH_H */

