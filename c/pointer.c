/*
一、指针定义
指针是用来指向特定类型对象的内存地址的容器。(特殊情况，指向void类型的指针可以指向任意类型)
运算符 & 是取某个变量或者数组的内存地址，不能用于取表达式、常量或者register类型变量的地址。
运算符 * 是间接寻址或间接引用运算符，作用于指针时它能访问指针指向的对象。
*/

int x = 1, y = 2, z[10];
int *ip; // ip is a pointer to int

ip = &x;    // ip = 1
y = *ip;    // y = 1
*ip = 0;    // x = 0
ip = &z[0]; // ip now points to z[0]

++*ip;
(*ip)++; // 不用括号则先算ip++再用*指向

/*
二、 指针和函数参数
因为函数的参数都是引用传递，所以如下的swap写法是错误的，应该使用指针的写法
*/
// 错误写法
void swap(int x, int y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

// 正确写法
void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}