#include <stdio.h>
#include <stdlib.h> //提供atof函数
#include "calc.h"

#define MAXOP 100 //操作数或运算符的最大长度

// 逆波兰计算器
/*
编译： cc main.c stack.c getop.c getch.c calc.h
使用：  ./a.out
1 2 - 4 5 + *
该程序从用户输入中一个个读取字符，如果是数字则压入一个栈，如果是符号则出栈
*/
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor \n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknow cmd \n");
            break;
        }
    }
    return 0;
}