#include "crosslist.h"
#include <stdio.h>
#include <stdlib.h>

int init_cross_list(PCrossList L, const ElemType* A, int m, int n)
{
    L->rowhead = (OLink*)malloc((m + 1) * (sizeof(OLNode)));
    L->colhead = (OLink*)malloc((n + 1) * (sizeof(OLNode)));
    int i;
    for (i = 0; i < m + 1; i++)
        L->rowhead[i] = NULL;
    for (i = 0; i < n + 1; i++)
        L->colhead[i] = NULL;
    L->rows = m;
    L->cols = n;
    int cnt_zero = 0;
    for (i = 0; i < m * n; i++) {
        if (A[i] == 0) {
            cnt_zero++;
            continue;
        }
        OLink p, q, temp = (OLink)malloc(sizeof(OLNode));
        temp->row = i / n + 1;
        temp->col = i % n + 1;
        temp->value = A[i];
        p = L->rowhead[temp->row];
        q = L->colhead[temp->col];
        if (p == NULL) {
            L->rowhead[temp->row] = temp;
            L->rowhead[temp->row]->right = NULL;
        } else {
            for (; p->right != NULL; p = p->right)
                ;
            p->right = temp;
            temp->right = NULL;
        }
        if (q == NULL) {
            L->colhead[temp->col] = temp;
            L->colhead[temp->col]->down = NULL;
        } else {
            for (; q->down != NULL; q = q->down)
                ;
            q->down = temp;
            temp->down = NULL;
        }
    }
    L->nums = m * n - cnt_zero;
    return m * n - cnt_zero;
}
int del_cross_list(PCrossList L, ElemType k)
{
    if (k == 0)
        return 0;
    OLink pre_col = NULL, pre_row = NULL, cur_col, cur_row;
    int i, num = 0;
    for (i = 1; i <= L->rows; i++) {
        for (cur_row = L->rowhead[i]; cur_row != NULL; pre_row = cur_row, cur_row = cur_row->right) { //按照行主序遍历
            if (cur_row->value != k)
                continue; //当元素找不到时
            else {
                num++;
                if (pre_row != NULL)
                    pre_row->right = cur_row->right;
                else {
                    L->rowhead[i] = cur_row->right;
                }
                for (cur_col = L->colhead[cur_row->col]; cur_col != cur_row && cur_col != NULL; pre_col = cur_col, cur_col = cur_col->down)
                    ; //找到结点的列
                if (pre_col == NULL) { //当第一个就是要删除的元素时
                    L->colhead[cur_row->col] = cur_col->down;
                    free(pre_col); //释放空间
                } else {
                    pre_col->down = cur_col->down;
                    free(pre_col);
                }
            }
        }
    }
    return num;
}
