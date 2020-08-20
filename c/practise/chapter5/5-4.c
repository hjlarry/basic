/*
编写函数strend(s, t)，如果字符串t出现在字符串s的尾部，则返回1，否则返回0
*/
#include <stdio.h>

int strend(char *s, char *t)
{
    int i = 0;
    while (*s)
        s++;
    while (*t)
    {
        t++;
        i++;
    }
    for (; i >= 0; i--)
    {
        if (*s != *t)
            return 0;
        s--;
        t--;
    }
    return 1;
}

int main()
{
    char *s1 = "ancdefg";
    char *s2 = "abccbc";
    char *s3 = "efgabc";
    char *s4 = "efgabcefg";
    char *t = "abc";
    printf("%d \n", strend(s1, t));
    printf("%d \n", strend(s2, t));
    printf("%d \n", strend(s3, t));
    printf("%d \n", strend(s4, t));
}