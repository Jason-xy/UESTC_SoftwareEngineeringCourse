#include "lab51.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_PARTS 100
#define NAME_LEN 25

void insert(struct part inv[], int* np)
{
    int part_number;

    if (*np == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }
    printf("Enter part number:");
    scanf("%d", &part_number);

    if (find_part(part_number, inv, *np) >= 0) {
        printf("Part already exist.\n");
        return;
    }

    inv[*np].number = part_number;
    printf("Enter part name:");
    read_line(inv[*np].name, NAME_LEN);
    printf("Enter quantity on hand:");
    scanf("%d", &inv[*np].on_hand);
    (*np)++;
}

