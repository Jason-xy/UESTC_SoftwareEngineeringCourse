#include <stdio.h>
#include <stdlib.h>
#define RATE 0.05

int main()
{
    float a;
    printf("Enter an amount:");
    scanf("%f", &a);
    a = a * (1 + RATE);
    printf("with tax added: $%.2f", a);
    return 0;
}
