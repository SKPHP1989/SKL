//
// Created by lij25 on 2020/1/6.
//

#include "skl_core.h"
#include "skl_exception.h"

/**
 * 错误异常
 * @param format
 * @param ...
 */
void error_exception(char *format, ...) {
    va_list args;
    char *time_format = get_current_timestamp();
    fprintf(error_fd, "[%s] [%s]", EXCEPTION_ERROR, time_format);
    va_start(args, format);
    vfprintf(error_fd, format, args);
    va_end(args);
    fprintf(error_fd, EOL);
    memory_free(time_format);
    exit(RET_FAIL);
}