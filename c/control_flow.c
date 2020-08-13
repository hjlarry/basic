/*
一、语句与程序块
在表达式之后加一个分号，它们就变成了语句
用一对花括号把一组声明和语句括在一起就构成了一个复合语句，也叫做程序块
*/

/*
二、 if else
因为else可以省略，我们要小心一些歧义的写法，例如:
if (a > b)
    if (n > 0)
        z = a
else
    z = b
这样写实际上是把else当做if(n>0)的分支来处理了，编译器并不处理缩进，所以应当用花括号括起来
*/

/*
三、 switch
switch语句中，case只是起一个标号的作用，某个分支执行完后，程序还会进入下一个分支继续执行，除非显式的跳转
所以经常看到每个分支以一个break结束，最后的default分支的break其实并无必要
*/

/*
四、 while和for
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

如果语句需要执行简单的初始化和变量递增，使用for语句结构更清晰一些。
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
五、 do ... while

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

/*
六、 break continue goto
continue只用于for、while或do...while，对于switch，某个循环包含了swtich的话，使用continue将直接进入下一个循环
当有多重循环嵌套时，使用goto是能跳到最外层的，但break不行，但大多数情况下goto会更加难以理解和维护
*/