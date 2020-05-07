#include "bitree.h" //请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

BiTNode* nearest_ancestor(BiTree root, BiTNode* p, BiTNode* q)
{
    Stack P, Q;
    init_stack(&P);
    init_stack(&Q);
    path(root, p, &P);
    path(root, q, &Q);
    BiTNode *a, *b;
    int distance = P.top - Q.top;
    while (distance > 0) {
        pop(&P, &a);
        distance--;
    }
    while (distance < 0) {
        pop(&Q, &b);
        distance++;
    }
    while (!is_empty(&P) && !is_empty(&Q)) {
        pop(&P, &a);
        pop(&Q, &b);
        if (a == b) {
            break;
        }
    }
    return a;
}