#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
{
    Node *min, *max, *p, *s;
    min = max = NULL;
    for (p = L->next; p->next->data <= (mink + 1) && p; p = p->next)
        ;
    min = p;
    for (p = p->next; p->data < maxk && p;) {
        s = p;
        p = p->next;
        free(s);
    }
    max = p;
    min->next = max;
}
