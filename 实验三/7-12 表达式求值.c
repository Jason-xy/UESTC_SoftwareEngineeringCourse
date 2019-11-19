#include <math.h>
#include <stdio.h>

float add(float x, float y)
{
    return x + y;
}

float minus(float x, float y)
{
    return x - y;
}

float multiply(float x, float y)
{
    return x * y;
}

float divide(float x, float y)
{
    return x / y;
}

int main(void)
{
    char ch;
    float num = 0.0f, fin = 0.0f, bet;
    scanf("%f", &fin);
    while (1) {
        ch = getchar();
        if (ch != '\n') {
            switch (ch) {
            case '+': {
                bet = fin;
                scanf("%f", &num);
                fin = add(bet, num);
            }
                continue;
            case '-': {
                bet = fin;
                scanf("%f", &num);
                fin = minus(bet, num);
            }
                continue;
            case '*': {
                bet = fin;
                scanf("%f", &num);
                fin = multiply(bet, num);
            }
                continue;
            case '/': {
                bet = fin;
                scanf("%f", &num);
                if (num != 0) {
                    fin = divide(bet, num);
                } else {
                    printf("Value of expression: -nan");
                    return 0;
                }
            }
            }
            continue;
        } else
            break;
    }

    printf("%.1f", fin);
    return 0;
}
