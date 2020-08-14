/*
编写函数itob(n, s, b)，将整数n转换为以b为底的数，并将结果以字符串的形式保存在s中。
如itob(n, s, 16)就是把整数n转换为16进制保存在s中
*/
#include <stdio.h>

void reverse(char s[])
{
    int i, j;
    char tmp;
    i = 0;
    while (s[i] != '\0')
        ++i;
    --i;
    if (s[i] == '\n')
        --i;
    j = 0;
    while (j < i)
    {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
        --i;
        ++j;
    }
}

void itob(int n, char s[], int b)
{
    int i, j, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[1000];

    int i = 0;
    int b = 2;
    itob(i, s, b);
    printf("%d into string base %d is: %s\n", i, b, s);

    i = 256;
    b = 16;
    itob(i, s, b);
    printf("%d into string base %d is: %s\n", i, b, s);

    i = -256;
    b = 16;
    itob(i, s, b);
    printf("%d into string base %d is: %s\n", i, b, s);

    i = 1023;
    b = 8;
    itob(i, s, b);
    printf("%d into string base %d is: %s\n", i, b, s);
}