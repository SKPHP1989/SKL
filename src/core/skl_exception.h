//
// Created by lij25 on 2020/1/6.
//

#ifndef SKL_EXCEPTION_H
#define SKL_EXCEPTION_H

#include "skl_core.h"

#define error_fd    stderr

enum exception_level_e {
    exception_level_info = 1,
    exception_level_warning,
    exception_level_error,
    exception_level_fatal
};
#define EXCEPTION_INFO "Info"
#define EXCEPTION_WARNING "Warning"
#define EXCEPTION_ERROR "Error"
#define EXCEPTION_FATAL "Fatal"

void error_exception(char *format, ...);

#endif //SKL_SKL_EXCEPTION_H
