//很奇怪只得了98分
#include <stdio.h>

int main(void)
{
    int times[10] = { 0 }, num;

    do {
        num = getchar();
        switch (num) {
        case '0':
            times[0] += 1;
            continue;
        case '1':
            times[1] += 1;
            continue;
        case '2':
            times[2] += 1;
            continue;
        case '3':
            times[3] += 1;
            continue;
        case '4':
            times[4] += 1;
            continue;
        case '5':
            times[5] += 1;
            continue;
        case '6':
            times[6] += 1;
            continue;
        case '7':
            times[7] += 1;
            continue;
        case '8':
            times[8] += 1;
            continue;
        case '9':
            times[9] += 1;
            continue;
        }
        break;
    } while (1);
    printf("Digit:\t	0	1	2	3	4	5	6	7	8	9	\nOccurrences:	");
    for (int i = 0; i < 10; i++) {
        printf("%d	", times[i]);
    }
    return 0;
}
