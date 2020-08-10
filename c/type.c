/*  
一、 基础数据类型:
基础数据类型只有： char、int、float、double
在基础类型上可以加限定词short、long、unsigned(大于等于0)、signed，例如: 
short int sh;  这里的int可以省略，所以我们一般写short sh; 
*/

/*  
二、常量： 
123456789L，尾部的L或l表示long，当整数太长int装不下时也会转化为long
1234U，尾部的U或u表示unsigned，也可以1234ul表示unsigned long
数字带前缀0表示八进制(其他语言可能是0o前缀)，0x表示十六进制
字符char常量就是int，例'x'， 对应ASCII字符集中的值，也是支持进行数学运算的
'\n'看起来像两个字符，实际上也是一个，也就是说单引号内都是一个byte大小的整数，printf时'%c'通过查对应的ASCII表显示其值
'\0'对应的整数值就是0，表示的是空字符，而'0'对应的整数值是48
我们可以用'\ooo'表示任意的字节大小的位模式，ooo就代表1~3个八进制数字；这种位模式也可以用'\xhh'表示，hh就是一个或多个十六进制数字
常量的表达式往往是在编译期就计算出来的，例如int days[1+3+31+31];
字符串常量就是字符数组，在内存上存储字符串时，会存储双引号之间的每一个字符，并在末尾多加一个字符'\0'，实际计算字符串长度时也会不去计算'\0'
*/
#include <stdio.h>
int y;
int main()
{
    int x;
    printf("%d", y);
}

// int strlen(char s[])
// {
//     int i;
//     while (s[i] != '\0')
//         ++i;
//     return i;
// }

// // 还有一种常量是枚举，默认第一个值是0，之后的值不断加1，例如:
// enum abool
// {
//     NO,
//     YES
// };
// enum months
// {
//     JAN = 1,
//     FEB,
//     MAR,
//     APR,
//     MAY
// };

/*
类型转化：

运算符两边的数字转换：
1. 如果任一类型为long double，则将另一个数字转为long double
2. 否则，若任一为double，则将另一个数字转为double
3. 否则，若任一为float，则将另一个数字转为float
4. 否则，将char和short转为int
5. 然后，若任一为long，则将另一个数字转为long
*/

// 将一个string类型的数字转化为整数类型 atoi("998") == 998
int atoi(char s[])
{
    int i, n;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

// char类型的大写转换为小写
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

// 使用 （type）n 进行强制类型转换
unsigned long int next = 1;
int rand(void)
{
    next = next * 110351245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}
void srand(unsigned int seed)
{
    next = seed;
}

/*
自增自减：
分为前缀自增 ++n 和后缀自增 n++，假设n=5，
x = ++n 则x为6，n为6
x = n++ 则x为5，n为6
*/
// 移除s中所有的c
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i]; // 相当于 s[j] = s[i] ; j++;
        }
    }
    s[j] = '\0';
}