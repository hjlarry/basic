#include <stdio.h>

// 从字符串s中删除所有的字符c
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/*
重写squeeze(s1,s2)，将字符串s1中任何与字符串s2中匹配的字符都删除
*/

void squeeze2(char s1[], char s2[])
{
    int i, j, k;
    for (k = 0; s2[k] != '\0'; k++)
    {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}

int main()
{
    char s1[] = "abcdefabcghi";
    char s2[] = "aaabc";
    squeeze2(s1, s2);
    printf("%s\n", s1);
}