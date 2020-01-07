//
// Created by lij25 on 2020/1/6.
//
#include "skl_exception.h"

void error_exception(char *format, ...) {
    va_list args;
    fprintf(error_fd, "[%s] ", EXCEPTION_ERROR);
    va_start(args, format);
    fprintf(error_fd, format, args);
    va_end(args);
    fprintf(error_fd, EOL);
    exit(RET_FAIL);
}