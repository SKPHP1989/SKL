#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char buffer[1024];

    //获取当前的工作目录，注意：长度必须大于工作目录的长度加一
    char *p = getcwd(buffer, 40);
    char *dir = NULL;

    printf("buffer:%s  p:%s size:%d \n", buffer, p, strlen(buffer));
    //获取当前工作目录的名字
    dir = (char *) get_current_dir_name();
    printf("dir:%s \n", dir);

    char *twd = NULL;
    twd = getwd(buffer);
    printf("buffer:%s  twd:%s \n", buffer, twd);
    return 0;
}