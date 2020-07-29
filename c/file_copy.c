#include <stdio.h>

// 第一个版本
// int main()
// {
//     // 因为要把EOF赋值给变量c，c不能是char类型，EOF是-1
//     int c;
//     // getchar从输入流中读取下一个字符并返回
//     c = getchar();
//     while (c != EOF)
//     {
//         // putchar读取变量c的内容，每次输出一个字符
//         putchar(c);
//         putchar('\n');
//         c = getchar();
//     }
// }

// 第二个版本
// `c = getchar()`是一个表达式，它的值就是表达式右边的结果
int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        putchar('\n');
    }
}