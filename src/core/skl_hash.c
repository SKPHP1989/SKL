#include "skl_core.h"
#include "skl_hash.h"

/**
 * hash表初始化
 * @return
 */
hash_t *create_hash(void) {
    unsigned int mem_size;
    hash_t *hash;
    hash = (hash_t *) memory_alloc(sizeof (hash_t));
    hash->size = HASH_INIT_SIZE;
    hash->mask = hash->size - 1;
    hash->ele_num = 0;
    hash->fill_ratio = 0.0;
    hash->list_head = NULL;
    hash->list_tail = NULL;
    mem_size = hash->size * sizeof (hash_bucket_t);
    hash->table = (hash_bucket_t **) memory_alloc(mem_size);
    memset(hash->table, 0, mem_size);
    return hash;
}

/**
 * 操作哈希桶
 * @param key
 * @param key_len
 * @param index
 * @param data
 * @return
 */
hash_bucket_t *create_hash_bucket(char *key, unsigned int key_len, int index, void *data) {
    hash_bucket_t *new_bucket;
    new_bucket = (hash_bucket_t *) memory_alloc(sizeof (hash_bucket_t));
    new_bucket->next = new_bucket->prev = NULL;
    new_bucket->list_next = new_bucket->list_prev = NULL;
    new_bucket->index_num = 0;
    new_bucket->data = data;
    new_bucket->index = index;
    new_bucket->key = key;
    new_bucket->key_len = key_len;
    return new_bucket;
}

/**
 * hash查找
 * @param hash
 * @param key
 * @return
 */
void *find_hash(hash_t *hash, char *key, int key_len) {
    int index = index_hash_key(key, key_len) % hash->mask;
    hash_bucket_t *bucket;
    bucket = hash->table[index];

    while (bucket) {
        if (strcmp(bucket->key, key) == 0) {
            bucket->index_num++;
            return bucket->data;
        }
        bucket = bucket->next;
    }
    return NULL;
}

/**
 * 插入或更新哈希表
 * @param hash
 * @param key
 * @param key_len
 * @param data
 * @return
 */
int insert_or_update_hash(hash_t *hash, char *key, unsigned int key_len, void *data) {
    int ret;
    //查找更新
    void *old_data;
    int hash_index = index_hash_key(key, key_len);
    int index = hash_index % hash->mask;
    hash_bucket_t *bucket, *new_bucket;
    bucket = hash->table[index];
    while (bucket) {
        if (strcmp(bucket->key, key) == 0) {
            old_data = bucket->data;
            bucket->data = data;
            memory_free(old_data);
            return RET_SUCCESS;
        }
        bucket = bucket->next;
    }
    // 插入
    new_bucket = create_hash_bucket(key, key_len, index, data);
    if (hash->table[index]) {
        hash->table[index]->prev = new_bucket;
        new_bucket->next = hash->table[index];
    }
    hash->table[index] = new_bucket;
    hash->ele_num++;
    hash->fill_ratio = (float) hash->ele_num / hash->size;

    if (hash->list_tail) {
        new_bucket->list_prev = hash->list_tail;
        hash->list_tail->list_next = new_bucket;
    }
    hash->list_tail = new_bucket;
    if (hash->ele_num == 1) {
        hash->list_head = new_bucket;
    }
    //判断容积率
    if (hash->fill_ratio > HASH_EXPAND_RATIO) {
        ret = expand_hash(hash);
        if (ret != RET_SUCCESS) {
            return ret;
        }
    }
    return RET_SUCCESS;
}

/**
 * 哈希删除
 * @param hash
 * @param key
 * @param key_len
 * @return
 */
int delete_hash(hash_t *hash, char *key, int key_len) {
    int opt_ret = RET_FAIL;
    int index = index_hash_key(key, key_len) % hash->mask;
    hash_bucket_t *bucket, *prev_bucket;
    prev_bucket = NULL;
    bucket = hash->table[index];
    while (bucket) {
        //find it
        if (strcmp(bucket->key, key) == 0) {
            if (bucket->list_prev && bucket->list_next) {
                //中间
                bucket->list_prev->list_next = bucket->list_next;
                bucket->list_next->list_prev = bucket->list_prev;
            } else if (bucket->list_prev && !bucket->list_next) {
                //尾
                bucket->list_prev->list_next = NULL;
                hash->list_tail = bucket->list_prev;
            } else if (!bucket->list_prev && bucket->list_next) {
                //头
                bucket->list_next->list_prev = NULL;
                hash->list_head = bucket->list_next;
            }
            if (bucket->prev && bucket->next) {
                //中间
                bucket->prev->next = bucket->next;
                bucket->next->prev = bucket->prev;
            } else if (bucket->prev && !bucket->next) {
                //尾
                bucket->prev->next = NULL;
            } else if (!bucket->prev && bucket->next) {
                //头
                bucket->next->prev = NULL;
                hash->table[index] = bucket->next;
            } else {
                hash->table[index] = NULL;
            }
            memory_free(bucket);
            bucket = NULL;
            opt_ret = RET_SUCCESS;
            hash->ele_num--;
            hash->fill_ratio = (float) hash->ele_num / hash->size;
            break;
        }
        prev_bucket = bucket;
        bucket = bucket->next;
    }
    if (opt_ret == RET_SUCCESS && hash->fill_ratio <= HASH_REDUCE_RATIO) {
        opt_ret = reduce_hash(hash);
        if (opt_ret != RET_SUCCESS) {
            return opt_ret;
        }
    }
    return opt_ret;
}

/**
 * hash扩张
 * @param hash
 * @return
 */
int expand_hash(hash_t *hash) {
    hash->size = hash->size << 1;
    if (hash->size > HASH_MAX_SIZE) {
        return RET_FAIL;
    }
    // define
    int index;
    unsigned int mem_size;
    hash_bucket_t *bucket, *tmp_bucket;
    hash_bucket_t **new_table;
    hash->mask = hash->size - 1;
    //
    mem_size = sizeof (hash_bucket_t) * hash->size;
    new_table = (hash_bucket_t **) memory_alloc(mem_size);
    memset(new_table, 0, mem_size);
    memory_free(hash->table);
    hash->table = new_table;
    hash->fill_ratio = hash->ele_num / hash->size;
    bucket = hash->list_head;
    //
    while (bucket) {
        bucket->next = bucket->prev = NULL;
        index = index_hash_key(bucket->key, bucket->key_len) % hash->mask;
        bucket->index = index;
        if (hash->table[index]) {
            hash->table[index]->prev = bucket;
            bucket->next = hash->table[index];
        }
        hash->table[index] = bucket;
        bucket = bucket->list_next;
    }
    return RET_SUCCESS;
}

/**
 * 哈希缩编
 * @param hash
 * @return
 */
int reduce_hash(hash_t *hash) {
    hash->size = hash->size >> 1;
    hash->size = hash->size < HASH_INIT_SIZE ? HASH_INIT_SIZE : hash->size;
    // define
    int index;
    unsigned int mem_size;
    hash_bucket_t *bucket, *tmp_bucket;
    hash_bucket_t **new_table;
    hash->mask = hash->size - 1;
    //
    mem_size = sizeof (hash_bucket_t) * hash->size;
    new_table = (hash_bucket_t **) memory_alloc(mem_size);
    memset(new_table, 0, mem_size);
    memory_free(hash->table);
    hash->table = new_table;
    hash->fill_ratio = hash->ele_num / hash->size;
    bucket = hash->list_head;
    //
    while (bucket) {
        bucket->next = bucket->prev = NULL;
        index = index_hash_key(bucket->key, bucket->key_len) % hash->mask;
        bucket->index = index;
        if (hash->table[index]) {
            hash->table[index]->prev = bucket;
            bucket->next = hash->table[index];
        }
        hash->table[index] = bucket;
        bucket = bucket->list_next;
    }
    return RET_SUCCESS;
}

/**
 * hash字符串index
 * @param key
 * @return
 */
int index_hash_key(char *key, int key_len) {
    unsigned int hash = 1315423911;
    unsigned int i = 0;
    for (i = 0; i < key_len; key++, i++) {
        hash ^= ((hash << 5) + (*key) + (hash >> 2));
    }
    return hash;
}

/**
 * 销毁哈希
 * @param hash
 * @return
 */
int destroy_hash(hash_t *hash) {
    hash_bucket_t *bucket, *while_bucket;
    while_bucket = hash->list_head;
    while (while_bucket) {
        bucket = while_bucket;
        memory_free(bucket->key);
        memory_free(bucket);
        while_bucket = while_bucket->list_next;
    }
    memory_free(hash);
    return RET_SUCCESS;
}

/**
 * 销毁哈希回调
 * @param hash
 * @param callback
 * @return 
 */
int destroy_hash_callback(hash_t *hash, destroy_hash_callback_func callback) {
    hash_bucket_t *bucket, *while_bucket;
    while_bucket = hash->list_head;
    while (while_bucket) {
        bucket = while_bucket;
        callback(bucket->data);
        memory_free(bucket->key);
        memory_free(bucket);
        while_bucket = while_bucket->list_next;
    }
    memory_free(hash);
    return RET_SUCCESS;
}

/**
 * 遍历哈希
 * @param hash
 */
void foreach_hash(hash_t *hash) {
    hash_bucket_t *bucket;
    bucket = hash->list_head;
    while (bucket) {
        printf("[key:%s(%d)]->%d\n", bucket->key, bucket->index, *(int *) bucket->data);
        bucket = bucket->list_next;
    }
}

/**
 * dump哈希
 * @param hash
 */
void dump_hash(hash_t *hash) {
    hash_bucket_t *bucket;
    int i;
    for (i = 1; i <= hash->size; i++) {
        bucket = hash->table[i];
        printf("node:%03d-->", i);
        while (bucket) {
            printf("[%s(%d)]=>%d->", bucket->key, bucket->index, *(int *) bucket->data);
            bucket = bucket->next;
        }
        printf("\n");
    }
}