#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, k;
    scanf("%d%d", &m, &n);
    while (n != 0) {
        k = m % n;
        m = n, n = k;
    }
    printf("%d", m);
    return 0;
}
