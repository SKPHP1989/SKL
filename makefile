TARGET: skl
CORE_PATH = ./src/core

OBJS = \
    skl_language_scanner.o \
    skl_language_parser.o \
    skl.o \
    skl_compiler.o \
    skl_memory.o \
    skl_variable.o \
    skl_hash.o \
    skl_function.o \
    skl_execute.o

GCC_FLAGS = -c -g -Wall -Wswitch-enum

skl_language_scanner.o: CORE_PATH/skl_language_scanner.l
	flex skl_language_scanner.l

skl_language_parser.o: CORE_PATH/skl_language_parser.y
	bison --yacc