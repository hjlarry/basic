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

/*
四、 地址运算
将指针、数组和地址的算术运算集成在一起是C语言的一大优点。
指针与整数不能相互转换，但0是例外，可以用来和指针比较。程序中经常用符号常量NULL代替0，更清晰的说明它是指针。
有效的指针运算包括：
* 相同类型指针之间的赋值运算
* 指针同整数之间的加法、减法运算
* 指向相同数组中元素的两个指针之间的减法或比较运算
* 将指针赋值给0或指针与0之间的比较运算
其他形式的指针运算都是非法的。
*/

#define ALLOCSIZE 1000           // 可用空间大小
static char allocbuf[ALLOCSIZE]; // 分配区域
static char *allocp = allocbuf;  // 下一个空闲的位置

// 返回指向n个字符的指针
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) // 判断有空闲空间
    {
        allocp += n;
        return allocp - n; // 返回分配前的指针地址
    }
    else // 空闲空间不够
        return 0;
}

// 释放p指向的存储区域
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    {
        allocp = p;
    }
}

// 另一种字符串长度的写法
int str_len2(char *s)
{
    char *p = s;
    while (*p != '\0')
    {
        p++;
    }
    return p - s;
}

/*
五、指针和字符串
printf("hello world");
当我们向函数中传递一个字符串常量，函数printf本质上是接收一个指向字符数组第一个字符的指针。

char amessage[] = "hello world"; // 定义了一个数组，它能存放双引号+'\0'，可修改数组中的单个字符
char *pmessage = "hello world"; // 定义了一个指针指向字符串常量，只能修改指针指向其他地址，但如果修改某个字符会提示未定义
*/

// 实现字符串拷贝的功能，不能用s=t，因为这只是拷贝了一个指针
// 版本一、数组下标实现
void strcpy1(char *s, char *t)
{
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

// 版本二、使用指针实现
void strcpy2(char *s, char *t)
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

// 版本三、自增放在循环中
void strcpy3(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}

// 版本四、和'\0'的比较是多于的，只需判断表达式的值是否为0即可，但编译器会报个警告
void strcpy4(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

// 字符串比较函数，小于、等于、大于t分别返回负整数、0、正整数
// 版本一、数组实现
int strcmp1(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

// 版本二、指针实现
int strcmp2(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}