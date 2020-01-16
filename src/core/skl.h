#ifndef SKL_H
#define SKL_H
#include "skl_core.h"

extern int yyparse(void);

extern void init_compiler();

extern void execute();

extern FILE *yyin;

#define SKL_VERSION         "0.0.1"
#define SKL_VERSION_NUM     20191230


#endif /* SKL_H */