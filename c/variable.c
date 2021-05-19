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
// #include <stdio.h>
// int x = 0x11;        // .data
// static int y = 0x22; // .data
// int z;               // .bss   (zero-value)

// int main()
// {
//     printf("%d, %d, %d\n", x, y, z);
// }

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
四、 外部变量
使用对象前，需要先声明。那么使用extern声明在其他模块中定义的变量或函数就是外部变量。
模块向外提供函数或全局变量时，通常使用头文件进行声明。
*/

/*
五、 register variables
有一些频繁使用的变量，加上register关键字去定义，就是建议编译器把这个变量放在寄存器中，至于编译器是否真的把它放在寄存器，是不确定的
寄存器变量的地址是不可访问的
*/

/*
六、 作用域
作用域指符号和表达式在其中“可见”或“可被访问”的上下文。
对象标识符有效范围是由其声明位置决定的。

作用域有四种：
文件：声明在任何块和函数之外，拥有文件作用域，如全局变量、函数。
块：声明出现在块或参数列表内，则该标识符只在块内可见。如参数、局部变量等是在特定的块内有效的。
函数原型：声明出现在函数原型（非定义）中，仅在原型结束前可见。
函数：函数作用域是大括号之间的区域，标签是唯一有此作用的标识符，可goto到函数的任意位置。

为避免混淆，小块作用域的标识符建议使用短名（如：i、x、n 等），函数内跨域的用有实际意义的单词，全局则使用多个单词组合，避免多个模块（源文件）间冲突。
*/

// 作用域可以嵌套，内部标识符可以遮蔽外部同名标识符。
#include <stdio.h>
char *x = "abc";

int main(void)
{
    printf("%p, %s\n", x, x); // global.x : 0x402004, abc
    int x = 100;
    printf("%p, %d\n", &x, x); // local.x : 0x7ffea1aafd70, 100
    {
        float x = 1.0;
        printf("%p, %f\n", &x, x); // inner.x : 0x7ffea1aafd74, 1.000000
    }
    printf("%p, %d\n", &x, x); // local.x : 0x7ffea1aafd70, 100
}

/*

三、 头文件
帮助我们把某些变量或函数的声明都放在一起，避免在多个文件中重复的使用extern声明。

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