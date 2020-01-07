#include "skl_variable.h"

/**
 * 创建字符串变量
 * @param identifier
 * @param str
 * @param str_len
 * @return
 */
variable_t *create_string_variable(char *identifier, char *str, int str_len) {
    variable_t *v = (variable_t *) memory_alloc(sizeof(variable_t));
    v->type = variable_type_string;
    v->identifier = identifier;
    v->value.str = str;
    v->value.str_len = str_len;
}

/**
 * 创建整形变量
 * @param identifier
 * @param i
 * @return
 */
variable_t *create_integer_variable(char *identifier, int i) {
    variable_t *v = (variable_t *) memory_alloc(sizeof(variable_t));
    v->type = variable_type_int;
    v->identifier = identifier;
    v->value.i = i;
}

/**
 * 创建双整形变量
 * @param identifier
 * @param d
 * @return
 */
variable_t *create_double_variable(char *identifier, double d) {
    variable_t *v = (variable_t *) memory_alloc(sizeof(variable_t));
    v->type = variable_type_double;
    v->identifier = identifier;
    v->value.d = d;
}

/**
 * 创建空值变量
 * @param identifier
 * @return
 */
variable_t *create_null_variable(char *identifier) {
    variable_t *v = (variable_t *) memory_alloc(sizeof(variable_t));
    v->type = variable_type_null;
    v->identifier = identifier;
    v->value = NULL;
}