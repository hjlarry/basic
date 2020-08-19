/*
编写一个递归版本的reverse(s)函数
*/
#include <string.h>
#include <stdio.h>

void _reverse(char s[], int low, int high)
{
    int j;
    char tmp;
    j = high - (low + 1);
    if (low < j)
    {
        tmp = s[low];
        s[low] = s[j];
        s[j] = tmp;
        _reverse(s, ++low, high);
    }
}

void reverse(char s[])
{
    _reverse(s, 0, strlen(s));
}

int main()
{
    char s[] = "hello world!";
    reverse(s);
    printf("%s", s);
}