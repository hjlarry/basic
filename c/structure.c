/*
一、 struct概念
下例中是一个struct的声明，其中'point'被称为structure tag，'x'和'y'被称为members
tag被用来定义structure的实例
*/
#include <stdio.h>
struct point
{
    int x;
    int y;
};
// 定义了一个变量pt
struct point pt;
// 支持嵌套structure
struct rect
{
    struct point pt1;
    struct point pt2;
};
struct rect screen;
// 支持调用成员变量
// int main()
// {
//     screen.pt1.y = 300;
//     printf("%d, %d", pt.x, screen.pt1.y);
// }
/*
二、 struct和方法
可以传入整个结构体，也可以传入其指针
*/
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int main()
{
    // 指针的写法  (*pp).x 括号必须，有些麻烦，因此有了pp->x的简写。
    struct point origin, *pp;
    pp = &origin;
    origin.x = 100;
    origin.y = 200;
    printf("origin is %d, %d \n", origin.x, origin.y);
    printf("origin is %d, %d \n", (*pp).x, (*pp).y);
    printf("origin is %d, %d \n", pp->x, pp->y);

    struct rect r, *rp = &r;
    r.pt1 = *pp;
    // 以下四种写法等价
    printf("rect: %d \n", r.pt1.x);
    printf("rect: %d \n", rp->pt1.x);
    printf("rect: %d \n", (r.pt1).x);
    printf("rect: %d \n", (rp->pt1).x);
}