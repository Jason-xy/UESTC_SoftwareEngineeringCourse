#include "lab51.h"
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

#define MAX_PARTS 100

int main()
{
    struct part inventory[MAX_PARTS];
    int num_parts = 0;
    char code;
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch (code) {
        case 'i': {
            insert(inventory, &num_parts);
            break;
        }
        case 's': {
            search(inventory, num_parts);
            break;
        }
        case 'u': {
            update(inventory, num_parts);
            break;
        }
        case 'p': {
            print(inventory, num_parts);
            break;
        }
        case 'q':
            return 0;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
    return 0;
}
