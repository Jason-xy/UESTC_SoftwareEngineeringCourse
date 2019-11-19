#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float loan, monthly, rate, b, c, d;
    printf("Enter amout of loan:");
    scanf("%f", &loan);
    printf("Enter interest rate:");
    scanf("%f", &rate);
    printf("Enter monthly payment:");
    scanf("%f", &monthly);
    b = loan - monthly + loan * rate / 1200;
    c = b - monthly + b * rate / 1200;
    d = c - monthly + c * rate / 1200;
    printf("Balance ramaining after first payment: $%.2f\n", b);
    printf("Balance ramaining after second payment: $%.2f\n", c);
    printf("Balance ramaining after third payment: $%.2f\n", d);
    return 0;
}
