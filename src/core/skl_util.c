//
// Created by lij25 on 2020/1/9.
//
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