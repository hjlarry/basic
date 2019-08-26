#include <stdio.h>

int __attribute__((noinline, optimize("-O2"))) add(int x, int y)
{
    return x + y;
}

int __attribute__((noinline)) main(int argc, char **argv)
{
    int x, y, z;
    x = 0x11;
    y = 0x22;
    z = add(x, y);

    printf("%d\n", z);
}