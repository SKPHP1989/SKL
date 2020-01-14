%{
#include "skl_core.h"
#include "skl_compiler.h"
#define YYDEBUG 1

%}

%union {
    char *identifier;
    int integer;
    double db;
    variable_t *variable;
    expression_t *expression;
    expression_list_t *expression_list;
    statement_t *statement;
    statement_list_t *statement_list;
    function_t *function;
    param_list_t *param_list;
}

%token <integer> T_INT_LITERAL
%token <db> T_DOUBLE_LITERAL

%token  <identifier>T_FUNCTION T_GLOBAL T_FOR T_IF T_ELSE T_ADD T_SUB T_MUL T_DIV T_ASSIGN
        T_EQ T_NE T_GT T_GE T_LT T_LE T_LP T_RP T_LC T_RC T_SEMICOLON T_IDENTIFIER
        T_BREAK T_CONTINUE T_RETURN T_COMMA T_STRING_LITERAL
        T_INCLUDE

%type <param_list> param_list

%type <expression_list> call_param_list

%type <function>function_definition
        
%type <expression> equality_expression relational_expression additive_expression multiplicative_expression primary_expression expression option_expression

%type <statement_list> statement_block statement_list

%type <statement> all_statement expression_statement return_statement continue_statement break_statement
                for_statement if_statement global_variable_declaration_statement
                cannot_top_statement can_top_statement include_statement

%%
// 运行单元
// 开始 函数定义 或 置顶的语句
translation_unit: function_definition
    | can_top_statement {
        set_global_statement_list($1);
    }
    | translation_unit can_top_statement
    {
        set_global_statement_list($2);
    }
    | translation_unit cannot_top_statement{
        set_global_statement_list($2);
    }
    | translation_unit function_definition
    ;

// 函数定义
function_definition: T_FUNCTION T_IDENTIFIER T_LP param_list T_RP statement_block
    {
        create_function($2 ,$4 ,$6);
    }
    | T_FUNCTION T_IDENTIFIER T_LP T_RP statement_block
    {
        create_function($2 ,NULL ,$5);
    }
    ;

// 能置顶语句
can_top_statement: expression_statement
    | global_variable_declaration_statement
    | for_statement
    | if_statement
    | return_statement
    | include_statement
    ;

// 不能置顶语句
cannot_top_statement: break_statement
    | continue_statement
    ;
// 所有的语句
all_statement: can_top_statement
    | cannot_top_statement
    ;

// 包含表达式
include_statement: T_INCLUDE T_STRING_LITERAL T_SEMICOLON
    {
        $$ = create_include_statment($2);
    }
    ;
// 表达式语句
// 例子: 1+2+3;(虽然无用)
expression_statement: expression T_SEMICOLON
    {
        $$ = create_expression_statement($1);
    }
    ;

// for语句
for_statement: T_FOR T_LP option_expression T_SEMICOLON option_expression T_SEMICOLON option_expression T_RP statement_block
    {
        $$ = create_for_statement($3 ,$5 ,$7 ,$9);
    }
    ;

// break语句
break_statement: T_BREAK T_SEMICOLON
    {
        $$ = create_break_statement();
    }
    ;

// if语句
if_statement: T_IF T_LP expression T_RP statement_block
    {
        $$ = create_if_statement($3 ,$5 ,NULL);
    }
    | T_IF T_LP expression T_RP statement_block T_ELSE statement_block
    {
        $$ = create_if_statement($3 ,$5 ,$7);
    }
    ;

// return语句
return_statement: T_RETURN option_expression T_SEMICOLON
    {
        $$ = create_return_statement($2);
    }
    ;

// 全局变量定义语句
// 例子: gloabl var1 = 4; | global var1;
global_variable_declaration_statement: T_GLOBAL T_IDENTIFIER T_SEMICOLON
    {
        $$ = create_global_variable_statement($2, NULL);
    }
    |T_GLOBAL T_IDENTIFIER T_ASSIGN expression T_SEMICOLON
    {
        $$ = create_global_variable_statement($2, $4);
    }
    ;

// 语句列表
statement_list:  all_statement
    {
        $$ = create_statement_list($1);
    }
    | statement_list all_statement
    {
        $$ = insert_statement_list($1 ,$2);
    }
    ;

// 语句块
statement_block: T_LC  T_RC
    {
        $$ = NULL;
    }
    | T_LC statement_list T_RC
    {
        $$ = $2;
    }
    ;

// continue语句
continue_statement: T_CONTINUE T_SEMICOLON
    {
        $$ = create_continue_statement();
    }
    ;

// 所有表达式
expression: equality_expression
    | T_IDENTIFIER T_ASSIGN expression
    {
        $$ = create_assign_expression($1 ,$3);
    }
    ;

// 等值表达式
equality_expression: relational_expression
    | equality_expression T_EQ relational_expression
    {
        $$ = create_binary_expression(expression_action_eq ,$1,$3);
    }
    | equality_expression T_NE relational_expression
    {
        $$ = create_binary_expression(expression_action_ne ,$1,$3);
    }
    ;

// 关联表达式（加法）
relational_expression: additive_expression
    | relational_expression T_LT additive_expression
    {
        $$ = create_binary_expression(expression_action_lt ,$1,$3);
    }
    | relational_expression T_GT additive_expression
    {
        $$ = create_binary_expression(expression_action_gt ,$1,$3);
    }
    | relational_expression T_LE additive_expression
    {
        $$ = create_binary_expression(expression_action_le ,$1,$3);
    }
    | relational_expression T_GE additive_expression
    {
        $$ = create_binary_expression(expression_action_ge ,$1,$3);
    }
    ;

// 加法表达式
additive_expression: multiplicative_expression
    | additive_expression T_ADD multiplicative_expression
    {
        $$ = create_binary_expression(expression_action_add ,$1,$3);
    }
    | additive_expression T_SUB multiplicative_expression
    {
        $$ = create_binary_expression(expression_action_sub ,$1,$3);
    }
    ;

// 乘除表达式
multiplicative_expression: primary_expression
    | multiplicative_expression T_DIV primary_expression
    {
        $$ = create_binary_expression(expression_action_div ,$1,$3);
    }
    | multiplicative_expression T_MUL primary_expression
    {
        $$ = create_binary_expression(expression_action_mul ,$1,$3);
    }
    ;

// 基础表达式
primary_expression:T_SUB primary_expression
    {
        $$ = $2;
    }
    | T_LP expression T_RP
    {
        $$ = $2;
    }
    | T_IDENTIFIER
    {
        $$ = create_identifier_expression($1);
    }
    | T_STRING_LITERAL
    {
        $$ = create_string_expression($1);
    }
    | T_INT_LITERAL
    {
        $$ = create_integer_expression($1);
    }
    | T_DOUBLE_LITERAL
    {
        $$ = create_double_expression($1);
    }
    | T_IDENTIFIER T_LP T_RP
    {
        $$ = create_call_function_expression($1 ,NULL);
    }
    | T_IDENTIFIER T_LP call_param_list T_RP
    {
        $$ = create_call_function_expression($1 ,$3);
    }
    ;

// 可选表达式
option_expression: expression
    | {$$=NULL;}
    ;

// 参数列表
param_list: T_IDENTIFIER
    {
        $$ = create_param_list($1);
    }
    | param_list T_COMMA T_IDENTIFIER
    {
        $$ = insert_param_list($1 ,$3);
    }
    ;

// 调用参数列表
call_param_list: expression
    {
        $$ = create_call_param_list($1);
    }
    | call_param_list T_COMMA expression
    {
        $$ = insert_call_param_list($1 ,$3);
    }
    ;