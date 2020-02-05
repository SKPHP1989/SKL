//
// Created by lij25 on 2020/1/9.
//
#include "skl_core.h"
#include "skl_util.h"

/**
 * 获取当前时间
 * @return
 */
char *get_current_timestamp() {
    int size = 20;
    char *time_format = (char *) memory_alloc(size);
    time_t t;
    struct tm *lt;
    time(&t); //获取Unix时间戳。
    lt = localtime(&t); //转为时间结构。
    sprintf(time_format, "%04d-%02d-%02d %02d:%02d:%02d", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour,
            lt->tm_min, lt->tm_sec);
    return time_format;
}

/**
 * 字符串拼接
 * @param one
 * @param two
 * @return 
 */
char *string_splice(char *one, char *two) {
    char *string;
    string = (char *) memory_alloc(sizeof (one) + sizeof (two));
    string = strcat(one, two);
    return string;
}

/**
 * 字符串申请
 * @param s
 * @return
 */
char *malloc_string(char *s) {
    char *string = (char *) memory_alloc(sizeof (s));
    strcpy(string, s);
    return string;
}

/**
 * 字符串申请
 * @param s
 * @return
 */
char *malloc_string_trim(char *s) {
    return substring(s, 1, strlen(s) - 2);
}

/**
 * 
 * @param ch
 * @param pos
 * @param length
 * @return 
 */
char* substring(char* ch, int pos, int length) {
    char* pch = ch;
    char* subch = (char *) memory_alloc(length + 1);
    int i;
    pch = pch + pos;
    for (i = 0; i < length; i++) {
        subch[i] = *(pch++);
    }
    subch[length] = '\0';
    return subch;
}

char * get_executable_path() {
    char buf[256];
    getcwd(buf, sizeof (buf));
    int len = strlen(buf);
    char *realpath = (char*) memory_alloc(len + 2);
    buf[len] = '/';
    buf[len+1] = '\0';
    strcpy(realpath, buf);
    return realpath;
}

/**
 * 
 * @param filename
 * @param current_path
 * @return 
 */
char *get_realpath(char *filename, char *current_path) {
    char *realpath;
    int fn_len = strlen(filename);
    if (*filename == '/') {
        realpath = (char *) memory_alloc(fn_len + 1);
        strcpy(realpath, filename);
    } else {
        if ((*filename + 1) == '/') {
            realpath = string_splice(current_path, substring(filename, 3, fn_len - 2));
        } else {
            realpath = string_splice(current_path, filename);
        }
    }
    return realpath;
}