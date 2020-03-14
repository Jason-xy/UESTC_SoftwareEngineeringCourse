#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

void lnk_merge(LinkList A, LinkList B, LinkList C)
{
    Node *pa, *pb, *pc;
    for (pa = A->next, pb = B->next, pc = C; pa || pb;) {
        if (pa) {
            pc->next = pa;
            pa = pa->next;
            pc = pc->next;
        }
        if (pb) {
            pc->next = pb;
            pb = pb->next;
            pc = pc->next;
        }
    }
}
