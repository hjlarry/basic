#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
enum
{
    NAME,
    PARENS,
    BRACKETS
};
void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;           // 最后一个记号的类型
char token[MAXTOKEN];    // 最后一个记号字符串
char name[MAXTOKEN];     // 标记符名
char datatype[MAXTOKEN]; // 数据类型为char、int等
char out[1000];          // 输出串

/*
核心函数dcl和dirdcl根据声明符的语法对声明进行分析。
~/projects/basic/c/practise/chapter5(master*) » cc dcl.c getch.c
~/projects/basic/c/practise/chapter5(master*) » ./a.out < testdcl           
argv:  pointer to pointer to char
daytab:  pointer to array[13] of int
daytab:  array[13] of pointer to int
comp:  function returnning pointer to void
comp:  pointer to function returnning void
x:  function returnning pointer to array[] of pointer to function returnning char
x:  array[3] of pointer to function returnning pointer to array[5] of char
*/

int main()
{
    while (gettoken() != EOF)
    {
        strcpy(datatype, token); // 该行的第一个记号为数据类型
        out[0] = '\0';
        dcl(); // 分析剩余的部分
        if (tokentype != '\n')
            printf("synax error \n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

// 对一个声明符进行语法分析
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*';) // 统计字符*的个数
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

// 分析一个直接声明
void dirdcl(void)
{
    int type;
    if (tokentype == '(') // 形式为(dcl)
    {
        dcl();
        if (tokentype != ')')
            printf("error : missing ) \n");
    }
    else if (tokentype == NAME) // 变量名
    {
        strcpy(name, token);
    }
    else
    {
        printf("error: expected name or (dcl) \n");
    }

    while ((type = gettoken()) == PARENS || type == BRACKETS)
    {
        if (type == PARENS)
            strcat(out, " function returnning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

// 返回下一个标记
int gettoken(void)
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
    {
        return tokentype = c;
    }
}