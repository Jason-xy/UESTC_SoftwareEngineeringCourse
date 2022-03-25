#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

void odd_even(SeqList* L)
{
    int i = 0, j = L->last;
    while (i < j) {
        //while (i < j && (L->elem[i] & 1) == 1) ++i;
        //while (i < j && (L->elem[j] & 1) == 0) --j;
        if (i < j && (L->elem[i] & 1) == 1) ++i;
        if (i < j && (L->elem[j] & 1) == 0) --j;
        if (((L->elem[i] & 1) == 1) || (L->elem[j] & 1) == 0) continue;
        if (i < j) {
            int tmp = L->elem[i];
            L->elem[i] = L->elem[j];
            L->elem[j] = tmp;
        }
    }
}
