#include "list.h" // �벻Ҫɾ���������鲻ͨ��
#include <stdio.h>
#include <stdlib.h>

void del_x2y(SeqList* L, ElemType x, ElemType y)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i <= L->last; i++) {
        if (L->elem[i] >= x && L->elem[i] <= y)
            j++;
        else
            L->elem[k++] = L->elem[i];
    }
    L->last = L->last - j;
}
