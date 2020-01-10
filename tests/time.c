//
// Created by lij25 on 2020/1/9.
//

#include <stdio.h>

#include <time.h>

int main ()

{

    time_t t

    struct tm * lt;    time (&t);//获取Unix时间戳。

    lt = localtime (&t);//转为时间结构。

    printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果

    return 0;}