/*
一、指针定义
指针是用来指向特定类型对象的内存地址的容器。(特殊情况，指向void类型的指针可以指向任意类型)
运算符 & 是取某个变量或者数组的内存地址，不能用于取表达式、常量或者register类型变量的地址。
运算符 * 是间接寻址或间接引用运算符，作用于指针时它能访问指针指向的对象。
*/
void point_define()
{
    int x = 1, y = 2, z[10];
    int *ip; // ip is a pointer to int

    ip = &x;    // ip = 1
    y = *ip;    // y = 1
    *ip = 0;    // x = 0
    ip = &z[0]; // ip now points to z[0]

    ++*ip;
    (*ip)++; // 不用括号则先算ip++再用*指向
}

/*
二、 指针和函数参数
因为函数的参数都是值传递，所以如下的swap写法是错误的，应该使用指针的写法
*/
// 错误写法
void swap_wrong(int x, int y)
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

/*
三、 指针和数组
通过数组下标所能完成的任何操作都能通过指针实现。
*/

#include <stdio.h>
int main()
{
    int a[10];
    int *point_a;
    point_a = &a[0]; // 指针指向数组第一个元素
    int x;
    x = *point_a; // 把该元素的值复制给x

    // 无论数组的元素类型或数组长度是怎样的，指针加i就意味着当前指向的元素加上第i个元素
    a[2] = 98;
    x = *(point_a + 2); // 把数组的第二个元素复制给x
    printf("x: %d \n", x);

    // &a[i] 和 a+i 的含义是相同的， a+i是a之后第i个元素的地址
    printf("pa: %p \n", &a[3]);
    printf("pb: %p \n", a + 3);
}

// 数组和指针的不同之处在于，指针是一个变量，pa=a和pa++都是合法的；数组名不是变量，a=pa和a++都是非法的
// 使用指针的写法，使用数组的写法在type.c中
int str_len(char *s)
{
    int i = 0;
    while (*s != '\0')
    {
        i++;
        s++;
    }
    return i;
}
// 函数定义中 char s[]和 char *s是等价的，我们更愿意用指针的形式，它更直观的表明传入了一个指针参数，数组名传入函数实际上就是传入数组第一个元素的地址。
// 也可以向函数传入子数组，例如  f(&a[2])  就是传入了子数组的地址，传入之后也可以在f内部使用p[-1]这样的表达式，只要没有越界就行。