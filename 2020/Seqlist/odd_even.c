#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

void odd_even(SeqList* L)
{
    int i = 0, j = 0, k = 0, temp;
    for (i; i <= L->last; i++) {
        if (L->elem[i] % 2)
            ;
        else {
            j = i;
            for (; L->elem[i] % 2 && i <= L->last; i++) {
                temp = L->elem[j];
                L->elem[j] = L->elem[i];
                L->elem[i] = temp;
            }
        }
    }
}
