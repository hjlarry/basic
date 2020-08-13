/*
编写函数escape(s, t) ，将字符串t复制到字符串s中， 并在复制过程中将换行符、制表符等不可见字符分别转换为相应的可见转义字符序列
再编写一个相反功能的
*/
#include <stdio.h>

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++, j++)
    {
        switch (s[i])
        {
        case '\n':
            t[j++] = '\\';
            t[j] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j] = 't';
            break;
        default:
            t[j] = s[i];
            break;
        }
    }
    t[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++, j++)
    {
        if (s[i] != '\\')
        {
            t[j] = s[i];
        }
        else
        {
            switch (s[++i])
            {
            case 'n':
                t[j] = '\n';
                break;
            case 't':
                t[j] = '\t';
                break;
            }
        }
    }
    t[j] = '\0';
}

int main()
{
    char s[] = "abc\tdef\tghi\njkl\tmno\tpqr\n";
    char t[1000];
    char k[1000];
    escape(s, t);
    printf("%s\n", t);
    unescape(t, k);
    printf("%s\n", k);
}