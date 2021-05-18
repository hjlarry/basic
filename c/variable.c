/*
一、 变量
变量（variable）与对象（object）联系在一起。
对象是执行期间的存储区域，其内容表示值（value），以特定类型（type）进行解释。变量则是对象外在身份，用以描述对象基本信息，诸如内存地址、数据类型，以及作用域等。对象可通过类型转换或多态方式拥有不同身份。
我们可以定义（define）或声明（declare）一个变量。定义有明确内存分配行为，依照类型决定大小，或赋予初始值；声明则向编译器说明目标信息，如名字、类型和参数等。但不一定会为其分配内存，因为它或许已在某处定义过，声明只是告知该如何使用而已。显然，定义是声明的一种，反之则不然。
*/

// #include <assert.h>
// #include <stdio.h>

// int main()
// {
//     // 可以在一行中定义多个变量，但其类型可能不同
//     char *p, c;
//     static_assert(sizeof(p) == 8, "指针类型长度应该为8");
//     static_assert(sizeof(c) == 1, "字符类型长度应该为1");
//     int x, y[3], z[15][3]; // int, int[3], int[15][3]

//     // 并不强制要求变量初始化，但其结果也是不可预知的
//     int *q;
//     // printf("%d\n", *q); // Segmentation fault

//     // 变量总是按值传递，赋值传参时就要去考虑是复制目标对象好还是复制其指针好
//     int xx = 1;
//     int yy = xx;
//     assert(&xx != &yy);
// }

/*
二、 全局变量
按是否有初始化值，分配在.data段或.bss段
默认可被全局访问，添加static修饰符可限定其在当前模块内使用
修饰符只影响其作用域，而不影响其内存分配的方式，应该尽量减少可被外部访问的全局变量
*/
#include <stdio.h>
int x = 0x11;        // .data
static int y = 0x22; // .data
int z;               // .bss   (zero-value)

int main()
{
    printf("%d, %d, %d\n", x, y, z);
}

/*
三、 局部变量
默认局部变量的生命周期仅限当前栈帧，或某个更小的作用域
如果添加static修饰，存储位置变为.data或.bss，并持有最后一次的值
*/
int test()
{
    int xx = 0x11;
    static int yy = 0x22;
    ++xx;
    ++yy;
    return 0;
}
/*
~/basic/c(master*) » objdump -dS -M intel ./a.out | grep -A 20 "<test>"
0000000000401150 <test>:
  401150:       55                      push   rbp
  401151:       48 89 e5                mov    rbp,rsp
  401154:       c7 45 fc 11 00 00 00    mov    DWORD PTR [rbp-0x4],0x11
  40115b:       83 45 fc 01             add    DWORD PTR [rbp-0x4],0x1
  40115f:       8b 05 d3 2e 00 00       mov    eax,DWORD PTR [rip+0x2ed3]        # 404038 <yy.2366>
  401165:       83 c0 01                add    eax,0x1
  401168:       89 05 ca 2e 00 00       mov    DWORD PTR [rip+0x2eca],eax        # 404038 <yy.2366>
  40116e:       b8 00 00 00 00          mov    eax,0x0
  401173:       5d                      pop    rbp
  401174:       c3                      ret    
  401175:       66 2e 0f 1f 84 00 00    nop    WORD PTR cs:[rax+rax*1+0x0]
  40117c:       00 00 00 
  40117f:       90                      nop
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

// #include <stdio.h>

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
// #define MAXLINE 1000 /* maximum input line length */

// 定义变量
// int max;               /*maximum length seen so far */
// char line[MAXLINE];    /* current input line */
// char longest[MAXLINE]; /* longest line saved here */

// int get_line();
// void copy();
// /* print the longest input line */
// int main()
// {
//     int len; /* current line length */
//     // 声明变量
//     extern int max;
//     extern char longest[];
//     max = 0;
//     while ((len = yyyyyyyy()) > 0)
//         if (len > max)
//         {
//             max = len;
//             copy();
//         }
//     if (max > 0) /*therewasaline*/
//         printf("%s", longest);
//     return 0;
// }

// int get_line()
// {
//     int c, i;
//     extern char line[];
//     for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
//         line[i] = c;
//     if (c == '\n')
//     {
//         line[i] = c;
//         ++i;
//     }
//     line[i] = '\0';
//     return i;
// }

// void copy()
// {
//     int i;
//     extern char line[], longest[];
//     i = 0;
//     while ((longest[i] = line[i]) != '\0')
//         ++i;
// }

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