/*
编写函数，把由十六进制数字组成的字符串转换为与之等价的整数型
*/

#include <stdio.h>

int htoi(char s[])
{
    int index, res;
    index = 0;
    res = 0;

    if (s[index] == '0')
    {
        index++;
        if (s[index] == 'x' || s[index] == 'X')
            index++;
    }

    while (1)
    {
        int v = 0;
        if (s[index] >= '0' && s[index] <= '9')
            v = s[index] - '0';
        else if (s[index] >= 'a' && s[index] <= 'f')
            v = s[index] - 'a' + 10;
        else if (s[index] >= 'A' && s[index] <= 'F')
            v = s[index] - 'A' + 10;
        else
            break;
        res = res * 16 + v;
        index++;
    }
    return res;
}

int main()
{
    printf("%d \n", htoi("0xabcd"));
    printf("%d \n", htoi("abcd"));
}