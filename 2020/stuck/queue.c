#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过
//96
bool init_queue(LinkQueue LQ)
{
    *LQ = (LinkQueue)malloc(sizeof(LinkQueueNode));
    if (*LQ != NULL) {
        (*LQ)->next = *LQ;
        return true;
    }
    return false;
}

bool enter_queue(LinkQueue LQ, ElemType x)
{
	LinkQueue NewNode, temp;
    temp = (*LQ)->next;
    NewNode = (LinkQueue)malloc(sizeof(LinkQueueNode));
    if (NewNode != NULL) {
        NewNode->data = x;
        NewNode->next = temp;
        (*LQ)->next = NewNode;
        *LQ = NewNode;
        return true;
    }
    return false;
}

bool leave_queue(LinkQueue LQ, ElemType *x)
{
	LinkQueue temp;
    if ((*LQ)->next != NULL) {
        temp = (*LQ)->next;
        *x = temp->data;
        (*LQ)->next = temp->next;
        free(temp);
        return true;
    }
    if ((*LQ)->next->next == (*LQ)->next&&(*LQ)->next!=NULL) {
        temp = (*LQ)->next;
        *x = temp->data;
        (*LQ)->next = NULL;
        free(temp);
        return true;
    }
    return false;
}