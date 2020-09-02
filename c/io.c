#include <stdio.h>
#include <stdlib.h>

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

// int main()
// {
//     printf("hello \t world %2.2f\n", 12345.12345678);
// }

/*
三、 格式化输入
int scanf(*format, ...)
该函数从标准输入中读取字符序列，按format的格式对字符序列进行解析，并把结果保存到其余的参数中。
当它扫描完或碰到部分输入无法解析的情况，则函数终止，返回已匹配的个数。到达文件末尾则返回EOF

int sscanf(char *string, char *format, arg1, arg2, ...)
这个函数是扫描字符串string，匹配的结果分别保存到arg1、arg2等参数中
*/

// int main()
// {
//     double sum, v;
//     sum = 0;
//     while (scanf("%lf", &v) == 1)
//         printf("\t%.2f\n", sum += v);
// }

// int main()
// {
//     int day, year;
//     char monthname[20];
//     sscanf("25 Dec 1985", "%d %s %d", &day, monthname, &year);
//     printf("%d %s %d \n", year, monthname, day);
// }

/*
四、 文件访问
访问文件需要通过操作系统提供的文件指针，该指针指向一个包含文件信息的结构，这些信息有：
缓冲区的位置、缓冲区中当前字符的位置、文件的读或写状态、是否出错或是否到达文件结尾等。
在stdio.h中已经定义了这个结构FILE，可以声明或使用函数返回这样一个指针:
FILE *fp;
FILE *fopen(char *name, char *mode);

有了文件指针，对文件的读写可以用:
int getc(FILE *fp);
int putc(int c, FILE *fp);
格式化输入输出还可以用:
int fscanf(FILE *fp, char *format, ...)
int fprintf(FILE *fp, char *format, ...)
*/

// 一个类似cat的程序，支持通过名字访问多个文件
// ./a.out a.txt b.txt
// int main(int argc, char *argv[])
// {
//     FILE *fp;
//     void filecopy(FILE *, FILE *);

//     if (argc == 1)
//         filecopy(stdin, stdout);
//     else
//         while (--argc > 0)
//             if ((fp = fopen(*++argv, "r")) == NULL)
//             {
//                 printf("can`t open %s \n", *argv);
//                 return 1;
//             }
//             else
//             {
//                 filecopy(fp, stdout);
//                 fclose(fp);
//             }
// }

// void filecopy(FILE *ifp, FILE *ofp)
// {
//     int c;
//     while ((c = getc(ifp)) != EOF)
//         putc(c, ofp);
// }

/*
五、 错误处理
主要是通过在stderr流中写入出错信息。
标准库的exit()函数可以在调用时，终止调用函数的执行。
*/

// 改写上例程序，添加错误处理
int main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0]; // 记录程序名称，供错误处理使用

    if (argc == 1)
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "%s: can`t open %s \n", prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
    if (ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout \n", prog);
        exit(2);
    }
    exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}