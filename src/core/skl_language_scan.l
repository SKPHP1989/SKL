%{
#include "skl_compiler.h"
#include "skl_language_parser.h"
void yyerror(char *);

int yywarp(void){
    return 1;
}
%}

%start COMMENT

%%

<INITIAL>"function"  return T_FUNCTION;
<INITIAL>"global"    return T_GLOBAL;
<INITIAL>"for"       return T_FOR;
<INITIAL>"if"        return T_IF;
<INITIAL>"elif"      return T_ELIF;
<INITIAL>"else"      return T_ELSE;
<INITIAL>"+"         return T_ADD;
<INITIAL>"-"         return T_SUB;
<INITIAL>"*"         return T_MUL;
<INITIAL>"/"         return T_DIV;
<INITIAL>"="         return T_ASSIGN;
<INITIAL>"=="        return T_EQ;
<INITIAL>"!="        return T_NE;
<INITIAL>">"         return T_GT;
<INITIAL>">="        return T_GE;
<INITIAL>"<"         return T_LT;
<INITIAL>"<="        return T_LE;
<INITIAL>"("         return T_LP;
<INITIAL>")"         return T_RP;
<INITIAL>"{"         return T_LC;
<INITIAL>"}"         return T_RC;
<INITIAL>";"         return T_SEMICOLON;
<INITIAL>"<<"        return T_LEFT;
<INITIAL>">>"        return T_RIGHT;
<INITIAL>"break"     return T_BREAK;
<INITIAL>"continue"  return T_CONTINUE;
<INITIAL>"return"    return T_RETURN;
<INITIAL>","         return T_COMMA;

<INITIAL>[A-Za-z_[A-Za-z_0-9]*  {
    yylval.identifier = string_malloc(yytext);
    return T_IDENTIFIER;
}


<INITIAL>[1-9]([0-9]*)|"0"  {
    int temp;
    sscanf(yytext ,"%d" ,&temp);
    yylval.integer = temp;
    return T_INT_LITERAL;
}

<INITIAL>[0-9]+\.[0-9]+             {
    double temp;
    sscanf(yytext, "%lf", &temp);
    yylval.db = temp;
    return T_DOUBLE_LITERAL;
}

<INITIAL>[ \t]    ;

<INITIAL>("#"|"//")[^\n]*           {
    BEGIN COMMENT;
}

<INITIAL>.                          {
    yyerror(yytext);
}

<COMMENT>\n                         {
    BEGIN INITIAL;
}

<COMMENT>.                          ;

%%