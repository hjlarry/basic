/*
一、 变量
定义变量是指变量在什么地方创建和分配内存的，而extern声明变量只是告诉编译器这个变量在其他地方被定义了
*/

/*
二、 外部变量
C语言程序可以看做由一系列外部对象构成的，外部变量就是定义在函数之外的对象，它可以被多个函数使用。
函数内没法定义别的函数，因此函数也是外部的。
外部变量相比函数内的自由变量有更长的生命周期和作用域。它的作用域从定义变量的位置开始到本源文件结束。

extern是一个外部变量声明的关键字，使用它就可以自此声明起至本源文件结束都能合法的使用某个外部变量。
通常都会把变量定义在源文件的头部几行，因此extern关键字一般是可以省略的。
要访问不同源文件中的外部变量，extern声明是必须的（书上这么写，但实际测试下来并不需要，不写也能找到其他外部变量）
对于数组，定义时需要制定长度，声明则不需要。
*/

#include <stdio.h>

// 这个版本不使用外部变量完成
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

// 这个版本不如正常的写法，外部变量太多易导致无意中修改而不好维护，也使函数不具有通用性。
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
一般的外部变量，其他文件都能访问到。但如果加了static关键字的外部变量，则只能在当前文件中访问到
也可以作用于函数，让函数不被其他文件访问
还可以作用于函数内部，这样该变量将不分配在栈上，不会函数执行结束就消失

五、 register variables
有一些频繁使用的变量，加上register关键字去定义，就是建议编译器把这个变量放在寄存器中，至于编译器是否真的把它放在寄存器，是不确定的
寄存器变量的地址是不可访问的

六、 程序块
块中定义的变量只在块中有效，如
if (n>0){
    int i;  // 只在if语句中有效
    for(i=0;i<n;i++)
        ...
}

七、 初始化
默认情况下，外部变量与静态变量将被初始化为0；而局部变量如果不显式初始化，将是一个不正确的值
外部变量与静态变量的初始化表达式必须是常量表达式，而局部变量可以是函数等
使用const限定符则指定变量的值不能修改，对于数组而言，它可以限定数组中所有元素的值不能修改

八、预处理
1. 文件包含
相当于把该文件中的内容复制到当前文件中去。
#include <file> 用于引用系统头文件，在系统目录的标准列表中搜索名为file的文件
#include "file" 用于引用用户头文件，在包含当前文件的目录中搜索名为file的文件

2. 宏替换
就是定义一个宏，编译器预处理的时候会把它展开，可以是包含参数的，例如:
#define forever for(;;)
带参数的：
#define max(A,B)  ((A) > (B) ? (A) : (B))
需要替换后带引号需前面加#:
#define dprint(expr)  printf(#expr " =%g\n", expr)

3. 通过条件语句控制预处理本身，例如通过判断系统确定应当包含不同的头文件
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
还有专门用来测试某个名字是否已经定义的 #ifdef与 #ifndef，下面的例如用来保证hdr.h的内容只被包含一次
#ifndef HDR
#define HDR
// hdr.h 的内容  
#endif
*/