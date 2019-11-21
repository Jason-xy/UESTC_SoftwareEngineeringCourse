#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, num2;
    scanf("%d", &num);
    do {
        num2 = num * num;
        printf("%d\n", num2);
        num
            -= 2;
    } while (num >= 0);
    return 0;
}
