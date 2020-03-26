#include "dsstring.h" //请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

int str_compare(const char* ptr1, const char* ptr2)
{
    char *p1, *p2;
    p1 = ptr1, p2 = ptr2;
    while (*p1 != 0 && *p2 != 0) {
        if (*p1 == *p2 || *p1 - *p2 == 32 || *p1 - *p2 == -32) {
            p1++, p2++;
            continue;
        }
        if ((*p1 - *p2 < 0 && *p1 - *p2 > -25) || *p1 - *p2 < -32 || (*p1 >= 48 && *p1 <= 57 && *p1 - *p2 < 0))
            return -1;
        else
            return 1;
    }
    if (*p1 - *p2 < 0)
        return -1;
    else if (*p1 - *p2 > 0)
        return 1;
    else
        return 0;
}
