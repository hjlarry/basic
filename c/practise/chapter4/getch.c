#include <stdio.h>
#define BUFFSIZE 100

char buf[BUFFSIZE]; // 用于ungetch的缓冲区
int bufp = 0;

int getch()
{
    // 缓冲区有就说明是压回的，先用
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}