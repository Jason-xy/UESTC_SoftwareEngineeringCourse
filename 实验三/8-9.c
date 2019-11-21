#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char map[10][10] = { 39 };
    int times[10][10] = { 0 }, x = 0, y = 0, letter = 65, direction, m, n;
    srand((unsigned)time(NULL));

    for (y = 0; y < 10; y++) {
        for (x = 0; x < 10; x++)
            map[x][y] = '.';
    }
    x = y = 0;
    while (letter <= 90) {
        map[x][y] = letter;
        times[x][y] = 1;
        letter++;
        m = x, n = y;
    begain:
        direction = (rand() % 4);
        switch (direction) {
        case 0:
            y -= 1;
            break;
        case 1:
            y += 1;
            break;
        case 2:
            x -= 1;
            break;
        case 3:
            x += 1;
            break;
        };

        if (x < 10 && x >= 0 && y < 10 && y >= 0 && times[x][y] == 0)
            continue;
        else {
            x = m, y = n;
            if (times[x - 1][y] == 1 && times[x + 1][y] == 1 && times[x][y - 1] == 1 && times[x][y + 1] == 1)
                break;
            else
                goto begain;
        }
    }
    x = y = 0;
    for (y = 0; y < 10; y++) {
        for (x = 0; x < 10; x++)
            printf("%c", map[x][y]);
        printf("\n");
    }
    return 0;
}
