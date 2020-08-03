/*
while和for：
for(expr1;expr2;expr3){
    statement;
}
相当于：
expr1;
while(expr2){
    statement;
    expr3;
}
其中的expr1、expr2、expr3都是可以省略的
*/
#include <ctype.h>
#include <stdio.h>

int atoi(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    printf("what i? %d \n", i); // i==0
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') // skip sign
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

int main()
{
    printf("result: %d", atoi("-135 7"));
}

/*
do ... while

do 
    statement
while (expression);
它会保证statement至少执行一次；
*/
// 将数字转换为string
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) // 记录正负号
        n = -n;         // 如果是负的，先让n是正的
    i = 0;
    do
    { // 将数字转为char， 相反的顺序， 987 -> '7', '8', '9'
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}