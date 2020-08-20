/*
用指针方式实现strcat(s, t)，将t指向的字符串复制到s字符串的尾部
*/
#include <stdio.h>

void str_cat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}

int main()
{
    // 不能用char *s1这样的方式，因为需要修改字符串数组
    char s1[] = "abc";
    char s2[] = "defale";
    str_cat(s1, s2);
    printf("%s", s1);
}