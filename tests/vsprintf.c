Code highlighting produced by Actipro CodeHighlighter (freeware)http://www.CodeHighlighter.com/-->#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define FPRINT_OUT_FILE_PATH "/dev/pts/2"

int My_fprintf(const   char   *form ,...)
{
    va_list   arg;
    int   done;
    char pbString[256];

    va_start(arg,form);
    vsprintf(pbString,form,arg);
    done = fprintf(console_printf_f,pbString);
    //done = printf(pbString);
    va_end(arg);
    return   done;
}

int main()
{
    int i;
    fprintf(stderr,"hello fprintf %d %s \n",32 ,"ni hao ");
    return 0;
}