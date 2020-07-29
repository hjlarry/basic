#include <stdio.h>

/*

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