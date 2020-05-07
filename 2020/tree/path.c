#include "bitree.h" //请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool path(BiTNode* root, BiTNode* node, Stack* s)
{
    BiTree tp = root, pre = NULL;
    int flag = 0,mark=0;
    while (!is_empty(s) || mark==0) {
        mark=1;
        if (tp && tp != pre) {
            push(s, tp);
            if (tp == node) {
                flag = 1;
                break;
            }
            tp = tp->left;
        } else {
            top(s, &tp);
            if (tp->right && tp->right != pre)
                tp = tp->right;
            else {
                pre = tp;
                pop(s, &tp);
            }
        }
    }
    if (flag)
        return true;
    else
        return false;
}

#include "bitree.h" //请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool path(BiTNode* root, BiTNode* node, Stack* s)
{
    if (root == NULL || node == NULL)
        return false;
    BiTNode* p = root;
    BiTNode* pre = NULL;
    while (p != NULL || !is_empty(s)) {
        while (p != NULL) {
            push(s, p);
            if (p == node) {
                return true;
            }
            p = p->left;
        }
        if (!is_empty(s)) {
            top(s, &p);
            while (p->right == NULL || pre != NULL && p->right == pre) {
                pop(s, &pre);
                top(s, &p);
            }
            p = p->right;
        }
    }
    return false;
}