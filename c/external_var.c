#include <stdio.h>

// 一、 正常写法
// #define MAXLINE 1000 /* maximum input line length */

// int getline(char line[], int maxline);
// void copy(char to[], char from[]);
// /* print the longest input line */
// int main()
// {
//     int len;               /* current line length */
//     int max;               /*maximum length seen so far */
//     char line[MAXLINE];    /* current input line */
//     char longest[MAXLINE]; /* longest line saved here */

//     max = 0;
//     while ((len = getline(line, MAXLINE)) > 0)
//         if (len > max)
//         {
//             max = len;
//             copy(longest, line);
//         }
//     if (max > 0) /*therewasaline*/
//         printf("%s", longest);
//     return 0;
// }

// /* getline: read a line into s, return length */
// int getline(char s[], int lim)
// {
//     int c, i;
//     for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
//         s[i] = c;
//     if (c == '\n')
//     {
//         s[i] = c;
//         ++i;
//     }
//     s[i] = '\0';
//     return i;
// }
// /* copy: copy 'from' into 'to'; assume to is big enough */
// void copy(char to[], char from[])
// {
//     int i;
//     i = 0;
//     while ((to[i] = from[i]) != '\0')
//         ++i;
// }

// 二、 全局变量的写法
// 定义变量是指变量在什么地方创建和分配内存的，而extern声明变量只是告诉编译器这个变量在其他地方被定义了
// 通常都会把变量定义在源文件的头部几行，因此extern关键字一般是可以省略的
// 但如果是多个源文件，变量a定义在file1，使用在file2，那file2是要有extern声明的，函数也是同样道理

// 这个版本不如正常的写法，全局变量太多易导致无意中修改而不好维护，也使函数不具有通用性。
#define MAXLINE 1000 /* maximum input line length */

// 定义变量
int max;               /*maximum length seen so far */
char line[MAXLINE];    /* current input line */
char longest[MAXLINE]; /* longest line saved here */

int get_line();
void copy();
/* print the longest input line */
int main()
{
    int len; /* current line length */
    // 声明变量
    extern int max;
    extern char longest[];
    max = 0;
    while ((len = yyyyyyyy()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0) /*therewasaline*/
        printf("%s", longest);
    return 0;
}

int get_line()
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy()
{
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}