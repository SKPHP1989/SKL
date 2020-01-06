bison --yacc -dv skl_language_parser.y

flex skl_language_scanner.l
gcc -c -g y.tab.c
gcc -c -g lex.yy.c
gcc -c -g skl.c
gcc -c -g skl_compiler.c
gcc -c -g skl_hash.c
gcc -c -g skl_variable.c
gcc -c -g skl_execute.c
gcc -c -g skl_memory.c
gcc skl.o \
    lex.yy.o\
    y.tab.o \
    skl_compiler.o \
    skl_hash.o \
    skl_variable.o \
    skl_execute.o \
    skl_memory.o \
    -o skl -lm
