#! /bin/bash
# 参数
echo "Compiler start;"

echo "Set compiler initialize;"

SKL_CURRENT_PATH=$(cd $(dirname "${BASH_SOURCE[0]}") && pwd)
SKL_SRC_PATH="${SKL_CURRENT_PATH}/src/"
SKL_SRC_CORE_PATH="${SKL_CURRENT_PATH}/src/core/"
SKL_OBJS_PATH="${SKL_CURRENT_PATH}/objs/"
SKL_BIN_PATH="${SKL_CURRENT_PATH}/bin/"

echo "Morphology and grammar initialize;"
# 词法和语法
cd ${SKL_SRC_CORE_PATH}
bison --yacc -dv --defines=skl_language_parser.h --output=skl_language_parser.c skl_language_parser.y
flex --outfile=skl_language_scanner.c skl_language_scanner.l

echo "Comilper build start:"
# 构建
gcc -c -g skl_language_parser.c -o ${SKL_OBJS_PATH}skl_language_parser.o
gcc -c -g skl_language_scanner.c -o ${SKL_OBJS_PATH}skl_language_scanner.o
gcc -c -g skl.c -o ${SKL_OBJS_PATH}skl.o
gcc -c -g skl_compiler.c -o ${SKL_OBJS_PATH}skl_compiler.o
gcc -c -g skl_hash.c -o ${SKL_OBJS_PATH}skl_hash.o
gcc -c -g skl_variable.c -o ${SKL_OBJS_PATH}skl_variable.o
gcc -c -g skl_execute.c -o ${SKL_OBJS_PATH}skl_execute.o
gcc -c -g skl_execute_operate.c -o ${SKL_OBJS_PATH}skl_execute_operate.o
gcc -c -g skl_execute_function.c -o ${SKL_OBJS_PATH}skl_execute_function.o
gcc -c -g skl_execute_include.c -o ${SKL_OBJS_PATH}skl_execute_include.o
gcc -c -g skl_execute_return.c -o ${SKL_OBJS_PATH}skl_execute_return.o
gcc -c -g skl_execute_expression.c -o ${SKL_OBJS_PATH}skl_execute_expression.o
gcc -c -g skl_execute_debug.c -o ${SKL_OBJS_PATH}skl_execute_debug.o
gcc -c -g skl_memory.c -o ${SKL_OBJS_PATH}skl_memory.o
gcc -c -g skl_exception.c -o ${SKL_OBJS_PATH}skl_exception.o
gcc -c -g skl_util.c -o ${SKL_OBJS_PATH}skl_util.o
gcc -c -g skl_function.c -o ${SKL_OBJS_PATH}skl_function.o

# 编译
cd ${SKL_CURRENT_PATH}
gcc ${SKL_OBJS_PATH}skl.o \
    ${SKL_OBJS_PATH}skl_language_scanner.o\
    ${SKL_OBJS_PATH}skl_language_parser.o \
    ${SKL_OBJS_PATH}skl_compiler.o \
    ${SKL_OBJS_PATH}skl_hash.o \
    ${SKL_OBJS_PATH}skl_variable.o \
    ${SKL_OBJS_PATH}skl_execute.o \
    ${SKL_OBJS_PATH}skl_execute_operate.o \
    ${SKL_OBJS_PATH}skl_execute_function.o \
    ${SKL_OBJS_PATH}skl_execute_include.o \
    ${SKL_OBJS_PATH}skl_execute_return.o \
    ${SKL_OBJS_PATH}skl_execute_expression.o \
    ${SKL_OBJS_PATH}skl_execute_debug.o \
    ${SKL_OBJS_PATH}skl_memory.o \
    ${SKL_OBJS_PATH}skl_exception.o \
    ${SKL_OBJS_PATH}skl_util.o \
    ${SKL_OBJS_PATH}skl_function.o \
    -o ${SKL_BIN_PATH}skl -lm

echo "Compiler build over;"