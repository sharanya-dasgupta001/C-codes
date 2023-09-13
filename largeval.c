#include "common.h"

static int f(int n)
{
    int a[n], i;

    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
        a[i] = i;
    }
    return 0;
}
    
int main(int ac, char *av[])
{
    int i;
    long long int a[1000000];

    for (i = 0; i < 10; i++)
        a[i] = i;
    f(100000);
    printf("%d\n", i);
    return 0;
}

