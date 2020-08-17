#include <stdio.h>

#define MAXVAL 100 // 栈的最大深度

int sp = 0; // 下一个空闲栈的位置
double val[MAXVAL];

void push(double f)
{

    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full, can not push %f \n", f);
}

double pop()
{
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack is empty!");
    return 0.0;
}

// 不弹出元素的情况下打印栈顶元素
void print_stack_top()
{
    int i = sp - 1;
    if (sp > 0)
        printf("%f", val[i]);
    else
        printf("error: stack is empty!");
}

// 复制栈顶元素
void copy()
{
    double op = pop();
    push(op);
    push(op);
}

// 交换栈顶两个元素的值
void swap()
{
    double op1, op2;
    op1 = pop();
    op2 = pop();
    push(op1);
    push(op2);
}

// 清空栈
void clear()
{
    sp = 0;
}