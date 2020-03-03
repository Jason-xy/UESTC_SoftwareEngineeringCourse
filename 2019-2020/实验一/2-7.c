#include <stdio.h>
#include <stdlib.h>

int main()
{
    int _20, _10, _5, _1, amount;

    printf("Enter a dollar amount:");
    scanf("%d", &amount);
    _20 = amount / 20;
    _10 = (amount - _20 * 20) / 10;
    _5 = (amount - _20 * 20 - _10 * 10) / 5;
    _1 = amount % 5;
    printf("$20 bills:%d\n$10 bills:%d\n$5 bills:%d\n$1 bills:%d\n", _20, _10, _5, _1);
    return 0;
}
