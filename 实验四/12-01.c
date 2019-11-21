#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j, k = 0;
    char message[100] = { 0 };
    while (1) {
        message[k++] = getchar();
        if (message[k - 1] == '\n')
            break;
    }
    printf("Reversal is: ");
    for (k; k >= 0; k--)
        printf("%c", message[k]);
    return 0;
}
