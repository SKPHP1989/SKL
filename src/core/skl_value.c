#include "skl_core.h"
#include "skl_value.h"

/**
 * 创建字符串值
 * @param identifier
 * @param str
 * @param str_len
 * @return
 */
zvalue_t *create_string_zvalue(char *str, int str_len) {
    zvalue_t *v = create_null_zvalue();
    v->type = zvalue_type_string;
    v->refer = 0;
    v->value.str.val = str;
    v->value.str.len = str_len;
    return v;
}

/**
 * 创建整形变量
 * @param identifier
 * @param i
 * @return
 */
zvalue_t *create_integer_zvalue(int i) {
    zvalue_t *v = create_null_zvalue();
    v->type = zvalue_type_integer;
    v->value.i = i;
    v->refer = 0;
    return v;
}

/**
 * 创建双整形变量
 * @param identifier
 * @param d
 * @return
 */
zvalue_t *create_double_zvalue(double d) {
    zvalue_t *v = create_null_zvalue();
    v->type = zvalue_type_double;
    v->value.d = d;
    v->refer = 0;
    return v;
}

/**
 * 创建空值变量
 * @param identifier
 * @return
 */
zvalue_t *create_null_zvalue() {
    zvalue_t *v = (zvalue_t *) memory_alloc(sizeof (zvalue_t));
    v->type = zvalue_type_null;
    v->refer = 0;
    v->is_temp = 1;
    return v;
}

/**
 * 创建布尔变量
 * @param identifier
 * @param b
 * @return
 */
zvalue_t *create_bool_zvalue(int b) {
    zvalue_t *v = create_null_zvalue();
    v->type = zvalue_type_bool;
    v->value.b = b;
    return v;
}
/**
 * 
 * @param val
 */
void release_temp_zvalue(zvalue_t *val) {
    if (is_empty(val)) {
        return;
    }
    if (!val->is_temp) {
        return;
    }
    if (val->type == zvalue_type_string) {
        memory_free(val->value.str.val);
    }
    memory_free(val);
}