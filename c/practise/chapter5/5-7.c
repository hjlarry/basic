/*
cc 5-7.c
./a.out < input.txt
以下是书中提供的函数。

题目要求：重写readlines，将输入的文本存储到main中的数组，而不是alloc的存储空间。看看函数的运行速度比改写前快多少？
*/

// 5-11节修改，指向函数的指针，可以通过-n参数，指定排序使用strcmp还是自己写的numcmp
// ./a.out -n < input.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000 // 进行排序的最大文本行
#define MAXLEN 1000   // 每行文本的最大长度

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *line_storage, int maxlines);
void writelines(char *lineptr[], int nlines);
void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

// 对输入的文本行排序
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    char line_storage[MAXLINES];
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, line_storage, MAXLINES)) >= 0)
    {
        q_sort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? strcmp : numcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("too big to sort! \n");
        return 1;
    }
}

int get_line(char *, int);
char *alloc(int);

// 读取输入行，原方案：使用alloc
// int readlines(char *lineptr[], int maxlines)
// {
//     int len, nlines;
//     char *p, line[MAXLEN];
//     nlines = 0;
//     while ((len = get_line(line, MAXLEN)) > 0)
//     {
//         if (nlines >= maxlines || (p = alloc(len)) == NULL)
//             return -1;
//         else
//         {
//             line[len - 1] = '\0'; //删除换行符
//             strcpy(p, line);
//             lineptr[nlines++] = p;
//         }
//     }
//     return nlines;
// }
// 读取输入行，使用5-7要求的方案
int readlines(char *lineptr[], char *line_storage, int maxlines)
{
    int len, nlines;
    char *p, *linestop, line[MAXLEN];
    p = line_storage;
    linestop = p + maxlines;
    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else
        {
            line[len - 1] = '\0'; //删除换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

// 打印输出
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
    {
        printf("%s \n", lineptr[i]);
    }
}

void swap(void *v[], int i, int j)
{
    void *tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/*
q_sort的参数，使用通用指针void *，这样能接收任意类型的数据，但调用时需强制转换为 void *类型
int (*comp)(void *, void *)表明comp是一个指向函数的指针，该函数具有两个void *类型的参数，其返回值类型为int
(*comp)(v[i], v[left])就是对函数的调用
*/
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    q_sort(v, left, last - 1, comp);
    q_sort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

// get_line和alloc是前面几章用到的辅助函数
int get_line(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;

    if (c == '\n')
    {
        *s++ = c;
    }
    *s = '\0';
    return s - t;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        return 0;
    }
}