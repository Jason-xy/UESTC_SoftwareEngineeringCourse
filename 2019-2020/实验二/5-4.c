#include <stdio.h>
#include <stdlib.h>

int main()
{
    int speed;
    scanf("%d", &speed);
    if (speed < 1)
        printf("Calm");
    if (speed >= 1 && speed <= 3)
        printf("Light air");
    if (speed >= 4 && speed <= 27)
        printf("Breeze");
    if (speed >= 28 && speed <= 47)
        printf("Gale");
    if (speed >= 48 && speed <= 63)
        printf("Storm");
    if (speed >= 64)
        printf("Hurricane");
    return 0;
}
