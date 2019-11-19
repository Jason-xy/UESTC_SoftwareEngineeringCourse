#include <math.h>
#include <stdio.h>

float he(float x, float y)
{
    return x + y;
}

float cha(float x, float y)
{
    return x - y;
}

float ji(float x, float y)
{
    return x * y;
}

float shang(float x, float y)
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
                fin = he(bet, num);
            }
                continue;
            case '-': {
                bet = fin;
                scanf("%f", &num);
                fin = cha(bet, num);
            }
                continue;
            case '*': {
                bet = fin;
                scanf("%f", &num);
                fin = ji(bet, num);
            }
                continue;
            case '/': {
                bet = fin;
                scanf("%f", &num);
                if (num != 0) {
                    fin = shang(bet, num);
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
