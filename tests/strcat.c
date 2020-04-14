#include <stdio.h>
#include <string.h>

int main() {
    char src[50], dest[50],src2[20];

    strcpy(src, "This is source");
    
    strcpy(src2, "This is source2");
    strcpy(dest, "This is destination");

    strcat(dest, src);
    strcat(dest, src2);

    printf("最终的目标字符串： |%s|\n", dest);

    printf("src=%s dest=%s\n", src, dest);
    return (0);
}