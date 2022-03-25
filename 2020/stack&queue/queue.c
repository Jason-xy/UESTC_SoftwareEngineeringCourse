#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

bool init_queue(LinkQueue* LQ){
    *LQ = (LinkQueue)malloc(sizeof(LinkQueueNode));
    if ((*LQ) != NULL) {
        (*LQ)->next = (*LQ);
        return true;
    }
    return false;
}

bool enter_queue(LinkQueue* LQ, ElemType x){
    LinkQueue t = (LinkQueue)malloc(sizeof(LinkQueueNode));
    if (t == NULL) return false;
    t->data = x;
    t->next = (*LQ)->next;
    (*LQ)->next = t;
    //Swap(&((*LQ)->data), &(t->data));
    (*LQ) = t;
    return true;
}

bool leave_queue(LinkQueue* LQ, ElemType* x){
    if ((*LQ)->next == (*LQ)) return false;
    LinkQueue t = (*LQ)->next->next;
    *x = t->data;
    (*LQ)->next->next = t->next;
    if (t == (*LQ)) (*LQ) = t->next;
    free(t);
    return true;
}

//int main() {
//    LinkQueue LQ;
//    init_queue(&LQ);
//    for(int i = 1; i <= 1; ++i)
//        enter_queue(&LQ, i);
//    for (int i = 1; i <= 2; ++i) {
//        int x = 0;
//        leave_queue(&LQ, &x);
//        printf("%d\n", x);
//    }
//    return 0;
//}
