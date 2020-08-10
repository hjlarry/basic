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
