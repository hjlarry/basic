/*
确定分别由unsigned、signed限定的char、long、short、int的取值范围
*/
#include <stdio.h>
#include <limits.h>

// 打印头文件的方式
// int main(){
//     printf("signed char: %d -- %d \n", CHAR_MIN, CHAR_MAX);
//     printf("unsigned char: %u \n",  UCHAR_MAX);

//     printf("signed short: %d -- %d \n", SHRT_MIN, SHRT_MAX);
//     printf("unsigned short: %u \n",  USHRT_MAX);

//     printf("signed int: %d -- %d \n", INT_MIN, INT_MAX);
//     printf("unsigned int: %u \n",  UINT_MAX);

//     printf("signed long: %ld -- %ld \n", LONG_MIN, LONG_MAX);
//     printf("unsigned long: %lu \n",  ULONG_MAX);
// }

// 位运算的方式
/*
(char)((unsigned char) ~ 0 >> 1) 的意思：
~0 把数字0的二进制位全部转换为1
(unsigned char) ~ 0  再将结果转换为unsigned char类型
(unsigned char) ~ 0 >> 1  把它右移一位移除掉符号位
最后转换为char类型
*/
int main(){
    printf("signed char: %d -- %d \n", -(char)((unsigned char) ~ 0 >> 1), (char)((unsigned char) ~ 0 >> 1));
    printf("unsigned char: %u \n",  (unsigned char) ~ 0);

    printf("signed short: %d -- %d \n", -(short)((unsigned short) ~ 0 >> 1), (short)((unsigned short) ~ 0 >> 1));
    printf("unsigned short: %u \n",  (unsigned short) ~ 0);

    printf("signed int: %d -- %d \n", -(int)((unsigned int) ~ 0 >> 1), (int)((unsigned int) ~ 0 >> 1));
    printf("unsigned int: %u \n",  (unsigned int) ~ 0);

    printf("signed long: %ld -- %ld \n", -(long)((unsigned long) ~ 0 >> 1), (long)((unsigned long) ~ 0 >> 1));
    printf("unsigned long: %lu \n",  (unsigned long) ~ 0);
}