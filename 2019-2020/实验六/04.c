#include "lab52.h" // 请不要删除本行头文件，否则检查不通过
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int CurrentCnt; // 请不要删除本行的全局变量声明，否则检查不通过

bool delete_item(GoodsList* L, char* goods_id)
{
    GoodsList *pre, *cur;
    pre = NULL, cur = L;
    for (; !strcmp(cur->data.goods_id, goods_id); pre = cur, cur = cur->next)
        ;
    if (!cur) {
        return false;
    }
    if (!pre) {
        L = L->next;
        free(pre);
        return true;
    } else {
        pre->next = cur->next;
        free(pre);
        return true;
    }
}
