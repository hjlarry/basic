/*
cc 5-7.c
./a.out < input.txt
以下是书中提供的函数。
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 // 进行排序的最大文本行
#define MAXLEN 1000   // 每行文本的最大长度

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

// 对输入的文本行排序
int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
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

// 读取输入行
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; //删除换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
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

void swap(char *v[], int i, int j)
{
    char *tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
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