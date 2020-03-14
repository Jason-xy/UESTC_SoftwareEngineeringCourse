#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

int lnk_search(LinkList L, int k, ElemType* p_ele)
{
    int i = 0, j = 0;
    Node* p = NULL;
    for (p = L; p; p = p->next)
        i++;
    if (k > i)
        return 0;
    for (p = L; j <= i - k; p = p->next, j++)
        ;
    *p_ele = p->data;
    return 1;
}
