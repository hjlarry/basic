/*
编写一个递归版本的itoa函数，把整数装换为字符串。
*/
#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char s[])
{
    static int i;
    if (n / 10)
        itoa(n / 10, s);
    else
    {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

int main()
{
    char s[100];
    itoa(1234, s);
    printf("%s", s);
}