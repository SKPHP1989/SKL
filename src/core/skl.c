#include "skl.h"

extern int yyparse(void);

extern void init_compiler();

extern void execute();

extern FILE *yyin;

int main(int argc, char *argv[]) {
    FILE *fp;
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc != 2) {
        fprintf(stderr, "usage:%s filename", argv[0]);
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "%s not found.\n", argv[1]);
        exit(1);
    }
    yyin = fp;
    init_compiler();
    if (yyparse()) {
        fprintf(stderr, "Error ! Error ! Error !\n");
        exit(1);
    }
    execute();
    return 0;
}