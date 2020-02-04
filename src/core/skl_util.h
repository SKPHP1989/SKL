//
// Created by lij25 on 2020/1/9.
//

#ifndef SKL_UTIL_H
#define SKL_UTIL_H

char *get_current_timestamp();

char *string_splice(char *one, char *two);

char *malloc_string_trim(char *s);

char* substring(char* ch, int pos, int length);

char *get_realpath(char *filename, char *current_path);

char * get_executable_path();
#endif //SKL_SKL_UTIL_H
