#include <stdio.h>

int move = 0;

int code(int a)
{
    if (a >= 65 && a <= 90) {
        if (a + move > 90)
            return a = move + a - 26;
        else
            return a = move + a;
    } else if (a >= 97 && a <= 122) {
        if (a + move > 122)
            return a = move + a - 26;
        else
            return a = move + a;
    } else
        return (char)a;
}

int main(void)
{
    char message[100] = { 10 };
    int i = 0, k = 0;

    printf("Enter message to be encrypted:");
    while (1) {
        message[k++] = getchar();
        if (message[k - 1] == '\n')
            break;
    }
    printf("Enter shift amount (1-25):");
    scanf("%d", &move);
    printf("Encrypted message: ");
    while (1) {
        if (message[i] == 10)
            break;
        else
            message[i] = code((int)message[i]);
        printf("%c", message[i++]);
    }
    return 0;
}
