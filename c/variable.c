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

/*
二、 全局变量的写法
定义变量是指变量在什么地方创建和分配内存的，而extern声明变量只是告诉编译器这个变量在其他地方被定义了
通常都会把变量定义在源文件的头部几行，因此extern关键字一般是可以省略的
但如果是多个源文件，变量a定义在file1，现在要在file2中使用它，那file2中使用前是要extern声明的，函数也是同样道理
*/

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

/*
三、 头文件
帮助我们把某些变量或函数的声明都放在一起，避免在多个文件中重复的使用extern声明。

四、 static variables
一般的全局变量，其他文件都能访问到。但如果加了static关键字的全局变量，则只能在当前文件中访问到

五、 register variables
有一些频繁使用的变量，加上register关键字去定义，就是建议编译器把这个变量放在寄存器中，至于编译器是否真的把它放在寄存器，是不确定的

六、C预处理机制
1. 引用文件，相当于把该文件中的内容复制到当前文件中去。
#include <file> 用于引用系统头文件，在系统目录的标准列表中搜索名为file的文件
#include "file" 用于引用用户头文件，在包含当前文件的目录中搜索名为file的文件

2. 宏替换
就是定义一个宏，编译器预处理的时候会把它展开，可以是包含参数的，例如:
#define forever for(;;)
#define max(A,B)  ((A) > (B) ? (A) : (B))

3. 条件定义宏，例如通过判断系统确定应当包含不同的头文件
#if SYSTEM == SYSV
    #define HDR "sysv.h"   
#elif SYSTEM == BSD       
    #define HDR "bsd.h"  
#elif SYSTEM == MSDOS       
    #define HDR "msdos.h"  
#else       
    #define HDR "default.h"  
#endif   
#include HDR
*/