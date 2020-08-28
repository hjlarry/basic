#include <stdio.h>

/*
一、 标准输入输出
最简单的输入机制是用getchar()函数从标准输入(一般是键盘)中一次读取一个字符
操作系统在读取到一个流的结尾时，会返回一个信号值-1，所以EOF不是某个文件结尾的特殊字符
操作系统是通过比较文件的长度知道到达了文件的末尾，但对于标准输入，无法事先知道末尾，因为用户不断的手动输入，这时Ctrl+D表示发送EOF

输入重定向：prog < infile，通过<将键盘输入替换为文件输入，同理，输出重定向是>
管道: prog1 | prog2，将prog1的标准输出通过管道重定向至prog2的标准输入
*/

// 第一个版本，验证getchar和putchar函数
// int main()
// {
//     //因为要把EOF赋值给变量c，c不能是char类型，EOF是-1
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
// int main()
// {
//     int c;
//     while ((c = getchar()) != EOF)
//     {
//         putchar(c);
//         putchar('\n');
//     }
// }

// 通过getchar计算输入的行数、单词数、字符数
// #define IN 1  /* inside a word */
// #define OUT 0 /* outside a word */

// int main()
// {
//     int c, nl, nw, nc, state;
//     state = OUT;
//     nl = nw = nc = 0;
//     while ((c = getchar()) != EOF)
//     {
//         ++nc;
//         if (c == '\n')
//             ++nl;
//         if (c == ' ' || c == '\n' || c == '\t')
//             state = OUT;
//         else if (state == OUT)
//         {
//             state = IN;
//             ++nw;
//         }
//     }
//     printf("lines: %d,  word: %d, characters: %d\n", nl, nw, nc);
// }

/* 通过getchar计算输入的空格、数字及其他字符的数量
~/projects/basic/c(master*) » cat file_copy.c | ./a.out                             
digits =  9 4 0 0 0 0 0 0 0 1, white space = 392, other = 831
*/
// int main()
// {
//     int c, i, nwhite, nother;
//     int ndigit[10];
//     nwhite = nother = 0;
//     for (i = 0; i < 10; ++i)
//         ndigit[i] = 0;

//     while ((c = getchar()) != EOF)
//     {
//         if (c >= '0' && c <= '9')
//             ++ndigit[c - '0'];
//         else if (c == ' ' || c == '\n' || c == '\t')
//             ++nwhite;
//         else
//             ++nother;
//     }

//     printf("digits = ");
//     for (i = 0; i < 10; ++i)
//         printf(" %d", ndigit[i]);
//     printf(", white space = %d, other = %d\n",
//            nwhite, nother);
// }

/*
二、格式化输出printf

printf中的转义字符，都表示一个ASCII字符：
\n, 换行(LF)
\r, 回车(CR)
\t, tab
\b, backspace
\", 双引号
\\, 反斜杠 

%6d, 打印出整数，至少6个字符宽
%4f, 打印出浮点数，至少4个字符宽 
%4.2f, 打印出浮点数，至少4个字符宽且小数点后保留2位 

*/

int main()
{
    printf("hello \t world %2.2f\n", 12345.12345678);
}