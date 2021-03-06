#ifndef SKL_CORE_H
#define SKL_CORE_H
// unix system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include<sys/time.h>
// system
#include "skl_hash.h"
#include "skl_memory.h"
#include "skl_exception.h"
#include "skl_util.h"
#include "skl_value.h"
#include "skl_variable.h"
#include "skl_function.h"
#include "skl_compiler.h"


#define RET_SUCCESS 0
#define RET_FAIL -1

#ifndef NULL
#define NULL ((void *)0)
#endif

#define EOL "\n"
#define is_empty(p) (p==NULL)
#define is_not_empty(p) (p!=NULL)

#define FILE_OPT_READ "r"

#define BOOL_TURE 1
#define BOOL_FALSE 0
#endif /* SKL_H */