#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str_compare(const char* ptr1, const char* ptr2)
{
    char *p1, *p2;
    p1 = ptr1;
    p2 = ptr2;
    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 == *p2 || *p1 - *p2 == 32 || *p1 - *p2 == -32) {
            p1++, p2++;
            continue;
        }
        if ((*p1 - *p2 < 0 && *p1 - *p2 > -25) || *p1 - *p2 < -32 || (*p1 >= 48 && *p1 <= 57 && *p1 - *p2 < 0))
            return -1;
        else
            return 1;
    }
    return 0;
}
int main(void)
{
    char s1[100],s2[100];
    strcpy(s1,"314Et2UdfTQ0");
    strcpy(s2,"314Et2UdfTQ0");
    printf("%d",str_compare(s1,s2));
    return 0;
}