#include <stdio.h>

#define MAXVAL 100  // 栈的最大深度

int sp = 0; // 下一个空闲栈的位置
double val[MAXVAL];

void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full, can not push %f \n", f);
}

double pop(){
    if (sp>0)
        return val[--sp];
    else 
        printf("error: stack is empty!");
        return 0.0;
}