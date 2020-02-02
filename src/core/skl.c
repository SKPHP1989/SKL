#include "skl.h"

/**
 * 
 * @param argc
 * @param argv
 * @return 
 */
void main(int argc, char *argv[]) {
    FILE *input;
    char *filename;
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc != 2) {
        error_exception("Usage:%s filename!", argv[0]);
    }
    filename = argv[1];
    input = fopen(filename, FILE_OPT_READ);
    if (is_empty(input)) {
        error_exception("Filename:%s not found!", filename);
    }
    yyin = input;
    init_compiler(filename);
    if (yyparse()) {
        error_exception("System parse failed!");
    }
    execute();
    fclose(input);
}