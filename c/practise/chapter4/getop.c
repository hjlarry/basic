#include <ctype.h>
#include <stdio.h>
#include "calc.h"

// 获取下一个运算符或数值操作数
int getop(char s[])
{
    int i, c;
    static int lastc = 0;

    if (lastc == 0)
    {
        c = getch();
    }
    else
    {
        c = lastc;
        lastc = 0;
    }
    // getch是获取下一个字符
    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();
    s[1] = '\0';
    i = 0;
    if (islower(c))
    {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            // ungetch(c);
            lastc = c;
        return NAME;
    }
    if (!isdigit(c) && c != '.') // 说明下一个字符不是数
        return c;
    if (isdigit(c)) // 收集整数部分
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') // 收集小数部分
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    // 因为是一个个字符读入来合并成一个数字的，就需要预读才能判断有没有结束
    // 那么不需要的数就得放回缓冲区
    if (c != EOF)
        // ungetch(c);
        lastc = c;
    return NUMBER;
}