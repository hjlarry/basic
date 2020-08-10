/*
在不使用&&和||的情况下，编写一个与如下循环等价的循环语句:
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
*/

// solution1
// int main()
// {
//     for (i = 0; i < lim - 1; ++i)
//     {
//         if (c = getchar() != '\n')
//         {
//             if (c != EOF)
//             {
//                 s[i] = c;
//             }
//         }
//     }
// }

// solution2
enum loop
{
    NO,
    YES
};
enum loop okloop = YES;
// int main()
// {
//     int i = 0;
//     while (okloop == YES)
//     {
//         if (i >= lim - 1)
//             okloop = NO;
//         else if ((c = getchar()) == '\n')
//             okloop = NO;
//         else if (c == EOF)
//             okloop = NO;
//         else
//         {
//             s[i] = c;
//             ++i;
//         }
//     }
// }
