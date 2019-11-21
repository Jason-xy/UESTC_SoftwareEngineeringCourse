#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour, min;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);
    if (hour > 12)
        printf("Equivalent 12 - hour time: %.2d:%.2d PM", hour - 12, min);
    if (hour == 12)
        printf("Equivalent 12 - hour time: %.2d:%.2d PM", hour, min);
    if (hour < 12 && hour > 0)
        printf("Equivalent 12 - hour time: %.2d:%.2d AM", hour, min);
    if (hour < 1)
        printf("Equivalent 12 - hour time: %.2d:%.2d AM", hour + 12, min);
    return 0;
}
