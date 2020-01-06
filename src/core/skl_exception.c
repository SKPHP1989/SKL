//
// Created by lij25 on 2020/1/6.
//
#include "skl_exception.h"

void error_exception(char *format, ...) {
    int i = 0;
    int x = 0;
    char *pstr = NULL;
    va_list arg;     //定义va_list类型变量arg
    va_start(arg, str); //arg初始化，将arg指向第一个可选参数
    assert(str);     //保证str不为空
    while (*str) {
        if (*str == '%') {
            str++;
            switch (*str) {
                case 's': {
                    pstr = va_arg(arg,
                    char*);  //va_arg的第二个参数是你要返
                    //回的参数的类型，此处是char *
                    while (*pstr) {
                        putchar(*pstr);
                        pstr++;
                    }
                    break;
                }
                case 'c': {
                    x = va_arg(arg,
                    char); //返回参数列表中的当前参数,并使a
                    //rg指向参数列表中的下一个参数
                    putchar(x);
                    x++;
                    break;
                }
                default: {
                    putchar(*(str - 1));
                    putchar(*str);
                    break;
                }

            }
            str++;
        } else {
            putchar(*str);
            str++;
        }
    }
    va_end(arg);   //把arg指针清为NULL
}