#include <stdio.h>

int main(void)
{
    int day, row, first, total;

    printf("Enter number of days in month:");
    scanf("%d", &total);
    printf("Enter starting day of the week(1=Sun,7=Sat):");
    scanf("%d", &first);

    printf("一	二	三	四	五	六	日	");
    for (int i = 1; i < first; i++)
        printf("	");
    for (day = 1; day <= 8 - first; day++)
        printf("%d	", day);
    printf("\n");
    for (int i = 1; i <= 5; i++) {
        for (int k = 1; k <= 7; k++, day++) {
            if (day <= total)
                printf("%d	", day);
            else
                break;
        }
        printf("\n");
    }
    return 0;
}
