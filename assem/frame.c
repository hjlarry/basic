#include <stdio.h>

int __attribute__((noinline, optimize("-O0"))) add(long long x, long long y, long long z)
{
    return x + y + z;
}

int __attribute__((noinline)) main(int argc, char **argv)
{
    long long x, y, z, a;
    x = 0x11;
    y = 0x22;
    z = 0x33;
    a = add(x, y, z);

    printf("%lld\n", a);
}