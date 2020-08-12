/*
重新编写lower，使用条件表达式替代if else
*/

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}