#include <stdio.h>
int main()
{
    int a = 10;
    int *p = &a;
    *p = 50;
    printf("%d", p);
    return 0;
}