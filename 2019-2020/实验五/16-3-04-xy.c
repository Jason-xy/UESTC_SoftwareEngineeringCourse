#include "lab51.h"
#include <stdio.h>
#include <stdlib.h>
void update(struct part inv[], int np)
{
    int i, number, change;

    printf("Enter part number:\n");
    scanf("%d", &number);
    i = find_part(number, inv, np);
    if (i >= 0) {
        printf("Enter change quantity on hand:\n");
        scanf("%d", &change);
        inv[i].on_hand += change;
    } else
        printf("Part not found.");
}

