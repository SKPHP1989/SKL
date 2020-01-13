/* 
 * File:   skl_compiler.h
 * Author: lij25
 *
 * Created on 2019年12月30日, 上午11:08
 */

#ifndef SKL_COMPILER_H
#define SKL_COMPILER_H

#include "skl_core.h"

int CURRENT_LINE;
char *CURRENT_FILENAME;
char *CURRENT_SCRIPT_PATH;

typedef union expression_uni expression_u;
typedef struct expression_s expression_t;
typedef struct function_expression_s function_expression_t;
typedef struct primary_expression_s primary_expression_t;
typedef struct binary_expression_s binary_expression_t;
typedef struct assign_expression_s assign_expression_t;
typedef struct expression_statement_s expression_statement_t;
typedef struct for_statement_s for_statement_t;
typedef struct if_statement_s if_statement_t;
typedef struct return_statement_s return_statement_t;
typedef struct statement_s statement_t;
typedef struct statement_list_s statement_list_t;
typedef struct statement_list_item_s statement_list_item_t;
typedef struct param_list_s param_list_t;
typedef struct param_list_item_s param_list_item_t;
typedef struct function_s function_t;
typedef struct expression_list_s expression_list_t;
typedef struct expression_list_item_s expression_list_item_t;

enum expression_type_e {
    expression_type_primary = 1,
    expression_type_binary,
    expression_type_assign,
    expression_type_global,
    expression_type_func
};

union expression_uni {
    primary_expression_t *primary;
    binary_expression_t *binary;
    assign_expression_t *assign;
    expression_t *expression;
    function_expression_t *function;
};

struct expression_s {
    enum expression_type_e type;
    expression_u expression;
};

enum value_type_e {
    value_type_integer = 1,
    value_type_double,
    value_type_string,
    value_type_bool,
    value_type_identifier,
    value_type_invalid
};

struct function_expression_s {
    char *function_name;
    expression_list_t *params;
};

struct primary_expression_s {
    enum value_type_e type;

    union {
        int i;
        double d;
        int b;
        char *string;
        char *identifier;
    } u;
};

enum expression_action_e {
    expression_action_add = 1,
    expression_action_sub,
    expression_action_mul,
    expression_action_div,
    expression_action_gt,
    expression_action_ge,
    expression_action_lt,
    expression_action_le,
    expression_action_eq,
    expression_action_ne
};

struct binary_expression_s {
    enum expression_action_e action;
    expression_t *left;
    expression_t *right;
};

struct assign_expression_s {
    char *identifier;
    expression_t *expression;
};

enum statement_type_e {
    statement_type_expression = 1,
    statement_type_if,
    statement_type_for,
    statement_type_break,
    statement_type_continue,
    statement_type_return,
    statement_type_global,

};

struct expression_statement_s {
    expression_t *expression;
};

struct for_statement_s {
    expression_t *before;
    expression_t *condition;
    expression_t *after;
    statement_list_t *statement_list;
};

struct if_statement_s {
    expression_t *expression;
    statement_list_t *if_statement_list;
    statement_list_t *else_statement_list;
};

struct return_statement_s {
    expression_t *expression;
};

struct statement_s {
    enum statement_type_e type;

    union {
        expression_statement_t *e;
        for_statement_t *f;
        if_statement_t *i;
        return_statement_t *r;
    } u;
};

struct statement_list_s {
    statement_list_item_t *top;
    statement_list_item_t *tail;
};

struct statement_list_item_s {
    statement_list_item_t *next;
    statement_t *statement;
};

struct expression_list_s {
    expression_list_item_t *top;
    expression_list_item_t *tail;
};

struct expression_list_item_s {
    expression_t *expression;
    expression_list_item_t *next;
};

struct param_list_s {
    param_list_item_t *top;
    param_list_item_t *tail;
};

struct param_list_item_s {
    char *identifier;
    param_list_item_t *next;
};

struct function_s {
    char *identifier;
    int is_native;
    void *func_addr;
    statement_list_t *statement_list;
    param_list_t *param_list;
};

//初始化编译器
void init_compiler(char *filename);

//
char *malloc_string(char *s);

// 设置语句列表
void set_global_statement_list(statement_t *statement);

// 创建包含语句
void create_include_statment(char *filename);

// 获取语句列表
statement_list_t *get_global_statement_list();

// 创建函数
function_t *create_function(char *identifier, param_list_t *param_list, statement_list_t *statement_list);

// 创建表达式语句
statement_t *create_expression_statement(expression_t *expression);

// 创建if语句
statement_t *create_if_statement(expression_t *condition, statement_list_t *if_statement_list, statement_list_t *else_statement_list);

// 创建for表达式
statement_t *create_for_statement(expression_t *before, expression_t *condition, expression_t *after,
        statement_list_t *statement_list);

// 创建return语句
statement_t *create_return_statement(expression_t *expression);

// 创建break语句
statement_t *create_break_statement();

// 创建continue语句
statement_t *create_continue_statement();

// 创建赋值表达式
expression_t *create_assign_expression(char *identifier, expression_t *expression);

// 全局变量语句
statement_t *create_global_variable_statement(char *identifier, expression_t *expression);

// 语句列表
statement_list_t *create_statement_list(statement_t *statement);

statement_list_t *insert_statement_list(statement_list_t *statement_list, statement_t *statement);

// 标识表达式
expression_t *create_integer_expression(int i);

expression_t *create_double_expression(double d);

expression_t *create_string_expression(char *s);

expression_t *create_identifier_expression(char *identifier);

// 二元表达式
expression_t *create_binary_expression(enum expression_action_e action, expression_t *left, expression_t *right);

// 变量赋值表达式
expression_t *create_variable_expression(char *identifier, expression_t *expression);

// 调用函数表达式
expression_t *create_call_function_expression(char *identifier, expression_list_t *expression_list);

// 参数列表
param_list_t *insert_param_list(param_list_t *param_list, char *identifier);

param_list_t *create_param_list(char *identifier);

// 调用参数列表
expression_list_t *create_call_param_list(expression_t *expression);

expression_list_t *insert_call_param_list(expression_list_t *expression_list, expression_t *expression);

#endif /* SKL_COMPILER_H */

