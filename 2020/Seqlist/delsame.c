#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

void del_dupnum(SeqList* L)
{
    int pre = -21474, i = 0, j = 0, k = 0;
    for (i = 0; i <= L->last; i++) {
        if (L->elem[i] == pre)
            j++;
        else
            L->elem[k++] = L->elem[i];
        pre = L->elem[i];
    }
    L->last = L->last - j;
}
