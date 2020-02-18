TARGET = skl
CC = gcc
BIN_PATH = ./bin/
OBJ_PATH = ./objs/
SRC_CORE_PATH = ./src/core/

INCLUDES = \
	-I$(SRC_CORE_PATH)

OBJS = \
	$(OBJ_PATH)skl.o \
	$(OBJ_PATH)skl_language_scanner.o\
	$(OBJ_PATH)skl_language_parser.o \
	$(OBJ_PATH)skl_compiler.o \
	$(OBJ_PATH)skl_hash.o \
	$(OBJ_PATH)skl_variable.o \
	$(OBJ_PATH)skl_execute.o \
	$(OBJ_PATH)skl_execute_operate.o \
	$(OBJ_PATH)skl_execute_function.o \
	$(OBJ_PATH)skl_execute_include.o \
	$(OBJ_PATH)skl_execute_return.o \
	$(OBJ_PATH)skl_execute_expression.o \
	$(OBJ_PATH)skl_execute_if.o \
	$(OBJ_PATH)skl_execute_for.o \
	$(OBJ_PATH)skl_execute_debug.o \
	$(OBJ_PATH)skl_memory.o \
	$(OBJ_PATH)skl_exception.o \
	$(OBJ_PATH)skl_util.o \
	$(OBJ_PATH)skl_function.o

CC_OBJ_FLAGS = -c -g -pedantic -DDEBUG

$(BIN_PATH)$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $@ -lm

clean:
	rm -f $(OBJS)
	rm -f $(BIN_PATH)skl

build-lang:
	cd $(SRC_CORE_PATH);bison --yacc -dv \
	--defines=skl_language_parser.h \
	--output=skl_language_parser.c \
	skl_language_parser.y;
	cd $(SRC_CORE_PATH);flex --outfile=skl_language_scanner.c \
	skl_language_scanner.l;

clean-lang:
	rm -f $(SRC_CORE_PATH)skl_language_scanner.c \
	$(SRC_CORE_PATH)skl_language_parser.h \
	$(SRC_CORE_PATH)skl_language_parser.output \
	$(SRC_CORE_PATH)skl_language_parser.c

test:
	$(BIN_PATH)/skl scripts/index.skl
	$(BIN_PATH)/skl scripts/time.skl
	
$(OBJ_PATH)skl_language_parser.o:$(SRC_CORE_PATH)skl_language_parser.c
	pwd;
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_language_parser.o

$(OBJ_PATH)skl_language_scanner.o:$(SRC_CORE_PATH)skl_language_scanner.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_language_scanner.o

$(OBJ_PATH)skl.o:$(SRC_CORE_PATH)skl.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl.o

$(OBJ_PATH)skl_compiler.o:$(SRC_CORE_PATH)skl_compiler.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_compiler.o

$(OBJ_PATH)skl_hash.o:$(SRC_CORE_PATH)skl_hash.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_hash.o

$(OBJ_PATH)skl_variable.o:$(SRC_CORE_PATH)skl_variable.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_variable.o

$(OBJ_PATH)skl_execute.o:$(SRC_CORE_PATH)skl_execute.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_execute.o

$(OBJ_PATH)skl_execute_operate.o:$(SRC_CORE_PATH)skl_execute_operate.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_execute_operate.o

$(OBJ_PATH)skl_execute_function.o:$(SRC_CORE_PATH)skl_execute_function.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_execute_function.o

$(OBJ_PATH)skl_execute_include.o:$(SRC_CORE_PATH)skl_execute_include.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_execute_include.o

$(OBJ_PATH)skl_execute_return.o:$(SRC_CORE_PATH)skl_execute_return.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_execute_return.o

$(OBJ_PATH)skl_execute_expression.o:$(SRC_CORE_PATH)skl_execute_expression.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_execute_expression.o
	
$(OBJ_PATH)skl_execute_if.o:$(SRC_CORE_PATH)skl_execute_if.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_execute_if.o
	
$(OBJ_PATH)skl_execute_for.o:$(SRC_CORE_PATH)skl_execute_for.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_execute_for.o

$(OBJ_PATH)skl_execute_debug.o:$(SRC_CORE_PATH)skl_execute_debug.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_execute_debug.o

$(OBJ_PATH)skl_memory.o:$(SRC_CORE_PATH)skl_memory.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_memory.o

$(OBJ_PATH)skl_exception.o:$(SRC_CORE_PATH)skl_exception.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_exception.o

$(OBJ_PATH)skl_util.o:$(SRC_CORE_PATH)skl_util.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_util.o

$(OBJ_PATH)skl_function.o:$(SRC_CORE_PATH)skl_function.c
	$(CC) $(CC_OBJ_FLAGS) $< -o $(OBJ_PATH)skl_function.o