/*  
基础数据类型:
基础数据类型只有： char、int、float、double
在基础类型上可以加限定词short、long、unsigned(大于等于0)、signed，例如: 
short int sh;  这里的int可以省略，所以我们一般写short sh; 
*/

/*  
常量： 
123456789L，尾部的L或l表示long，当整数太长int装不下时也会转化为long
1234U，尾部的U或u表示unsigned，也可以1234ul表示unsigned long
字符char常量就是int，例'x'， 对应ASCII字符集中的值，也是支持进行数学运算的
'\n'看起来像两个字符，实际上也是一个，也就是说单引号内都是一个byte大小的整数，printf时'%c'通过查对应的ASCII表显示其值
常量的表达式往往是在编译期就计算出来的，例如int days[1+3+31+31];
字符串常量就是字符数组，在内存上存储字符串时，会存储双引号之间的每一个字符，并在末尾多加一个字符'\0'，实际计算字符串长度时也会不去计算'\0'
*/
#include <stdio.h>

int strlen(char s[])
{
    int i;
    while (s[i] != '\0')
        ++i;
    return i;
}

// 还有一种常量是枚举，默认第一个值是0，之后的值不断加1，例如:
enum abool
{
    NO,
    YES
};
enum months
{
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY
};