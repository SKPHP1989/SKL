%{
#include "skl_core.h"
#include "skl_compiler.h"
#include "skl_language_parser.h"
void yyerror(char *);

int yywrap(void)
{
    return 1;
}

void yyerror(char *s) {
    printf("[Error] %s:%s(%d)\n",global_scanner_filename, s, global_scanner_line);
}
%}

%start COMMENT

%%

<INITIAL>"function"  return T_FUNCTION;
<INITIAL>"global"    return T_GLOBAL;
<INITIAL>"for"       return T_FOR;
<INITIAL>"if"        return T_IF;
<INITIAL>"else"        return T_ELSE;
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
<INITIAL>"break"     return T_BREAK;
<INITIAL>"continue"  return T_CONTINUE;
<INITIAL>"return"    return T_RETURN;
<INITIAL>"include"   return T_INCLUDE;
<INITIAL>","         return T_COMMA;

<INITIAL>[A-Za-z_][A-Za-z_0-9]*     {
    yylval.identifier = malloc_string(yytext);
    return T_IDENTIFIER;
}

<INITIAL>([1-9][0-9]*)|"0"          {
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

<INITIAL>[ \t\r]                      ;
<INITIAL>"\n"                       {
    global_scanner_line++;
}
<INITIAL>("#"|"//")[^\n]*           {
    BEGIN COMMENT;
}

<INITIAL>.                          {
    global_scanner_line++;
    yyerror(yytext);
}

<INITIAL>L?\"(\\.|[^\\"])*\" {
    yylval.identifier = malloc_string_trim(yytext);
    return T_STRING_LITERAL;
}

<COMMENT>\n                         {
    global_scanner_line++;
    BEGIN INITIAL;
}

<COMMENT>.                          ;

%%