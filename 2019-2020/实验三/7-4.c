#include <stdio.h>

int main(void)
{
    char c;
    int a = 0;

    while (1) {
        c = getchar();
        if (c != 10) {
            switch (c) {
            case 'A':
            case 'B':
            case 'C':
                a = 2;
                printf("%d", a);
                continue;
            case 'D':
            case 'E':
            case 'F':
                a = 3;
                printf("%d", a);
                continue;
            case 'G':
            case 'H':
            case 'I':
                a = 4;
                printf("%d", a);
                continue;
            case 'J':
            case 'K':
            case 'L':
                a = 5;
                printf("%d", a);
                continue;
            case 'M':
            case 'N':
            case 'O':
                a = 6;
                printf("%d", a);
                continue;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                a = 7;
                printf("%d", a);
                continue;
            case 'T':
            case 'U':
            case 'V':
                a = 8;
                printf("%d", a);
                continue;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                a = 9;
                printf("%d", a);
                continue;
            default:
                printf("%c", c);
                continue;
            }
        } else
            break;
    }
    return 0;
}
