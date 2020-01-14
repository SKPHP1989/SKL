/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "skl_compiler.h"

// 加载编译器配置
extern int yyparse(void);
//
extern FILE *yyin;
//
hash_t *global_function_table, *global_variable_table, *global_script_table;
//
statement_list_t *global_statement_list, *global_include_statement_list;

int global_include_mode;

/**
 * 初始化编译器
 */
void init_compiler(char *filename) {
    global_function_table = create_hash();
    global_variable_table = create_hash();
    CURRENT_FILENAME = filename;
    CURRENT_LINE = 0;
    //
    global_statement_list = (statement_list_t *) memory_alloc(sizeof (statement_list_t));
    global_statement_list->top = global_statement_list->tail = NULL;
    //
    global_include_statement_list = (statement_list_t *) memory_alloc(sizeof (statement_list_t));
    global_include_statement_list->top = global_include_statement_list->tail = NULL;
    //
    global_include_mode = 0;
}

/**
 * 设置语句列表
 * @param statement_list
 * @param statement
 * @return
 */
void set_global_statement_list(statement_t *statement) {
    if (global_include_mode) {
        return set_global_include_statement_list(statement);
    }
    statement_list_item_t *item = (statement_list_item_t *) memory_alloc(sizeof (statement_list_item_t));
    item->statement = statement;
    item->next = NULL;
    if (is_empty(global_statement_list->top)) {
        global_statement_list->top = item;
    }
    statement_list_item_t *current_item = global_statement_list->tail;
    if (is_empty(current_item)) {
        global_statement_list->tail = item;
    } else {
        global_statement_list->tail = item;
        current_item->next = item;
    }
}

/**
 * 
 * @param statement
 */
void set_global_include_statement_list(statement_t *statement) {
    statement_list_item_t *item = (statement_list_item_t *) memory_alloc(sizeof (statement_list_item_t));
    item->statement = statement;
    item->next = NULL;
    if (is_empty(global_include_statement_list->top)) {
        global_include_statement_list->top = item;
    }
    statement_list_item_t *current_item = global_include_statement_list->tail;
    if (is_empty(current_item)) {
        global_include_statement_list->tail = item;
    } else {
        global_include_statement_list->tail = item;
        current_item->next = item;
    }
}

/**
 * 获取语句列表
 * @return
 */
statement_list_t *get_global_statement_list() {
    return global_statement_list;
}

/**
 * 创建函数
 * @param identifier
 * @return
 */
function_t *create_function(char *identifier, param_list_t *param_list, statement_list_t *statement_list) {
    function_t *function = (function_t *) memory_alloc(sizeof (function_t));
    function->identifier = identifier;
    function->is_native = 0;
    function->statement_list = statement_list;
    function->param_list = param_list;
    void *function_exist = find_hash(global_function_table, identifier, strlen(identifier));
    if (is_not_empty(function_exist)) {
        error_exception("(%s:%d) Function: %s has been defined!", CURRENT_FILENAME, CURRENT_LINE, identifier);
    }
    // 插入函数
    insert_or_update_hash(global_function_table, identifier, strlen(identifier), (void *) function);
    return function;
}

/**
 * 创建包含语句
 * @param filename
 */
statement_t *create_include_statment(char *filename) {
    include_statement_t *is = (include_statement_t *) memory_alloc(sizeof (include_statement_t));
    is->filename = filename;
    statement_t *statement = (statement_t *) memory_alloc(sizeof (statement_t));
    statement->type = statement_type_include;
    statement->u.in = is;
    return statement;
}

/**
 * 创建表达式语句
 * @param e
 * @return
 */
statement_t *create_expression_statement(expression_t *e) {
    expression_statement_t *es = (expression_statement_t *) memory_alloc(sizeof (expression_statement_t));
    es->expression = e;
    statement_t *statement = (statement_t *) memory_alloc(sizeof (statement_t));
    statement->type = statement_type_expression;
    statement->u.e = es;
    return statement;
}

/**
 * 
 * @param condition
 * @param if_statement_list
 * @param else_statement_list
 * @return 
 */
statement_t *create_if_statement(expression_t *condition, statement_list_t *if_statement_list, statement_list_t *else_statement_list) {
    statement_t *statement = (statement_t *) memory_alloc(sizeof (statement_t));
    statement->type = statement_type_if;
    if_statement_t *if_statement = (if_statement_t *) memory_alloc(sizeof (if_statement_t));
    if_statement->expression = condition;
    if_statement->if_statement_list = if_statement_list;
    if_statement->else_statement_list = else_statement_list;
    statement->u.i = if_statement;
    return statement;
}

/**
 * 创建for语句
 * @param before
 * @param confition
 * @param after
 * @param statement_list
 * @return
 */
statement_t *create_for_statement(expression_t *before, expression_t *condition, expression_t *after,
        statement_list_t *statement_list) {
    statement_t *statement = (statement_t *) memory_alloc(sizeof (statement_t));
    statement->type = statement_type_for;
    for_statement_t *for_statement = (for_statement_t *) memory_alloc(sizeof (for_statement_t));
    for_statement->statement_list = statement_list;
    for_statement->before = before;
    for_statement->condition = condition;
    for_statement->after = after;
    statement->u.f = for_statement;
    return statement;
}

/**
 * 创建return语句
 * @param expression
 * @return
 */
statement_t *create_return_statement(expression_t *expression) {
    statement_t *statement = (statement_t *) memory_alloc(sizeof (statement_t));
    statement->type = statement_type_return;
    return_statement_t *return_statement = (return_statement_t *) memory_alloc(sizeof (return_statement_t));
    return_statement->expression = expression;
    statement->u.r = return_statement;
    return statement;
}

/**
 * 创建break语句
 * @return
 */
statement_t *create_break_statement() {
    statement_t *statement = (statement_t *) memory_alloc(sizeof (statement_t));
    statement->type = statement_type_break;
    statement->u.e = NULL;
    return statement;
}

/**
 * 创建continue语句
 * @return
 */
statement_t *create_continue_statement() {
    statement_t *statement = (statement_t *) memory_alloc(sizeof (statement_t));
    statement->type = statement_type_continue;
    statement->u.e = NULL;
    return statement;
}

/**
 * 创建赋值表达式
 * @param identifier
 * @param expression
 * @return
 */
expression_t *create_assign_expression(char *identifier, expression_t *expression) {
    assign_expression_t *ae = (assign_expression_t *) memory_alloc(sizeof (assign_expression_t));
    ae->identifier = identifier;
    ae->expression = expression;
    expression_t *e = (expression_t *) memory_alloc(sizeof (expression_t));
    e->expression.assign = ae;
    e->type = expression_type_assign;
    return e;
}

/**
 * 创建全局变量语句
 * @param identifier
 * @param expression
 * @return
 */
statement_t *create_global_variable_statement(char *identifier, expression_t *expression) {
    statement_t *statement = (statement_t *) memory_alloc(sizeof (statement_t));
    statement->type = statement_type_global;
    statement->u.e = NULL;
    return statement;
}

/**
 * 创建语句列表
 * @param statement
 * @return
 */
statement_list_t *create_statement_list(statement_t *statement) {
    statement_list_t *sl = (statement_list_t *) memory_alloc(sizeof (statement_list_t));
    statement_list_item_t *slt = (statement_list_item_t *) memory_alloc(sizeof (statement_list_item_t));
    slt->next = NULL;
    slt->statement = statement;
    sl->top = sl->tail = slt;
    return sl;
}

/**
 * 插入语句列表
 * @param statement_list
 * @param statement
 * @return
 */
statement_list_t *insert_statement_list(statement_list_t *statement_list, statement_t *statement) {
    statement_list_item_t *slt = (statement_list_item_t *) memory_alloc(sizeof (statement_list_item_t));
    slt->statement = statement;
    slt->next = NULL;
    statement_list_item_t *current_tail = statement_list->tail;
    current_tail->next = slt;
    statement_list->tail = slt;
    return statement_list;
}

/**
 * 创建整型表达式
 * @param i
 * @return
 */
expression_t *create_integer_expression(int i) {
    primary_expression_t *pe = (primary_expression_t *) memory_alloc(sizeof (primary_expression_t));
    pe->type = value_type_integer;
    pe->u.i = i;
    expression_t *e = (expression_t *) memory_alloc(sizeof (expression_t));
    e->type = expression_type_primary;
    e->expression.primary = pe;
    return e;
}

/**
 * 创建双整型表达式
 * @param d
 * @return
 */
expression_t *create_double_expression(double d) {
    primary_expression_t *pe = (primary_expression_t *) memory_alloc(sizeof (primary_expression_t));
    pe->type = value_type_double;
    pe->u.d = d;
    expression_t *e = (expression_t *) memory_alloc(sizeof (expression_t));
    e->type = expression_type_primary;
    e->expression.primary = pe;
    return e;
}

/**
 *
 * @param s
 * @return
 */
expression_t *create_string_expression(char *s) {
    primary_expression_t *pe = (primary_expression_t *) memory_alloc(sizeof (primary_expression_t));
    pe->type = value_type_string;
    pe->u.string = s;
    expression_t *e = (expression_t *) memory_alloc(sizeof (expression_t));
    e->type = expression_type_primary;
    e->expression.primary = pe;
    return e;
}

/**
 *
 * @param identifier
 * @return
 */
expression_t *create_identifier_expression(char *identifier) {
    primary_expression_t *pe = (primary_expression_t *) memory_alloc(sizeof (primary_expression_t));
    pe->type = value_type_identifier;
    pe->u.identifier = identifier;
    expression_t *e = (expression_t *) memory_alloc(sizeof (expression_t));
    e->type = expression_type_primary;
    e->expression.primary = pe;
    return e;
}

/**
 * 创建二元表达式
 * @param action
 * @param left
 * @param right
 * @return 
 */
expression_t *create_binary_expression(enum expression_action_e action, expression_t *left, expression_t *right) {
    binary_expression_t *be = (binary_expression_t *) memory_alloc(sizeof (binary_expression_t));
    be->left = left;
    be->right = right;
    be->action = action;
    expression_t *e = (expression_t *) memory_alloc(sizeof (expression_t));
    e->type = expression_type_binary;
    e->expression.binary = be;
    return e;
}

/**
 * 创建变量表达式
 * @param identifier
 * @param expression
 * @return
 */
expression_t *create_variable_expression(char *identifier, expression_t *expression) {
    assign_expression_t *ae = (assign_expression_t *) memory_alloc(sizeof (assign_expression_t));
    ae->identifier = identifier;
    ae->expression = expression;
    expression_t *e = (expression_t *) memory_alloc(sizeof (expression_t));
    e->type = expression_type_assign;
    e->expression.assign = ae;
    return e;
}

/**
 * 创建调用函数表达式
 * @param identifier
 * @param expression_list
 * @return
 */
expression_t *create_call_function_expression(char *identifier, expression_list_t *expression_list) {
    function_expression_t *fe = (function_expression_t *) memory_alloc(sizeof (function_expression_t));
    fe->function_name = identifier;
    fe->params = expression_list;
    expression_t *e = (expression_t *) memory_alloc(sizeof (expression_t));
    e->type = expression_type_func;
    e->expression.function = fe;
    return e;
}

/**
 * 创建参数列表
 * @param identifier
 * @return
 */
param_list_t *create_param_list(char *identifier) {
    param_list_item_t *pli = (param_list_item_t *) memory_alloc(sizeof (param_list_item_t));
    pli->identifier = identifier;
    pli->next = NULL;
    param_list_t *pl = (param_list_t *) memory_alloc(sizeof (param_list_t));
    pl->top = pl->tail = pli;
    return pl;
}

/**
 * 参数列表
 * @param param_list
 * @param identifier
 * @return
 */
param_list_t *insert_param_list(param_list_t *param_list, char *identifier) {
    param_list_item_t *pli = (param_list_item_t *) memory_alloc(sizeof (param_list_item_t));
    pli->identifier = identifier;
    pli->next = NULL;
    param_list_item_t *current_tail = param_list->tail;
    param_list->tail = current_tail->next = pli;
    return param_list;
}

/**
 * 创建调用参数列表
 * @param expression
 * @return
 */
expression_list_t *create_call_param_list(expression_t *expression) {
    expression_list_item_t *eli = (expression_list_item_t *) memory_alloc(sizeof (expression_list_item_t));
    eli->expression = expression;
    eli->next = NULL;
    expression_list_t *el = (expression_list_t *) memory_alloc(sizeof (expression_list_t));
    el->top = el->tail = eli;
    return el;
}

/**
 * 插入调用参数列表
 * @param expression_list
 * @param expression
 * @return
 */
expression_list_t *insert_call_param_list(expression_list_t *expression_list, expression_t *expression) {
    expression_list_item_t *eli = (expression_list_item_t *) memory_alloc(sizeof (expression_list_item_t));
    eli->expression = expression;
    eli->next = NULL;
    expression_list_item_t *current_tail = expression_list->tail;
    expression_list->tail = current_tail->next = eli;
    return expression_list;
}