#include <stdio.h>
#include <stdlib.h> //提供atof函数
#include <math.h>
#include <string.h>
#include "calc.h"

#define MAXOP 100 //操作数或运算符的最大长度

// 逆波兰计算器
/*
编译： cc main.c stack.c getop.c getch.c calc.h
使用：  ./a.out
1 2 - 4 5 + *
该程序从用户输入中一个个读取字符，如果是数字则压入一个栈，如果是符号则出栈
*/

/*
4-3、加入取模运算符，注意考虑负数的情况
取模使用fmod函数以支持浮点数，负数处理还有些问题
*/

/*
4-4、栈操作添加一些操作：
不弹出元素的情况下打印栈顶元素
复制栈顶元素
交换栈顶两个元素的值
清空栈
这部分修改在stack.c
*/

/*
4-5、给计算器添加sin、exp与pow等函数
这部分修改在main中添加了mathfunc，在getop中去识别sin、exp、pow
*/

/*
4-11、修改getop，使其不必使用ungetch函数
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
        case NAME:
            mathfunc(s);
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
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
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

void mathfunc(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("error: %s not supported \n", s);
}