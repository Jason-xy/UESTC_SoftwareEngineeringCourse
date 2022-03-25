#include "dsstring.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

//本题icoding抽风哈，过不了请自行迎和icoding改，本份代码在2022.3.25晚能过的，我是搞不明白题意
//根本读不懂题意，做icoding最难的事莫过于猜测题意
bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    if (len == 0) return false;
    if (pos + len - 1 >= src.len) len = src.len - pos; //len都超出原字符串长度了还得算查找成功我也是服了icoding了
    int d = pos / BLOCK_SIZE, r = pos % BLOCK_SIZE;
    Block* p = src.head, *q = sub->head; int i;
    for (i = 0; i < d; ++i) p = p->next;
    i = r; int j, k = BLOCK_SIZE, first = 1; //i, p指向src, k, q指向sub
    for (j = 1; j <= len; ++j) {
        if (i >= BLOCK_SIZE) i = 0, p = p->next;
        if (k >= BLOCK_SIZE) {
            k = 0;
            if (first) {
                q = sub->head = (Block*)malloc(sizeof(Block));
                first = 0;
            }
            else {
                q->next = (Block*)malloc(sizeof(Block));
                q = q->next;
            }
            if (q == NULL) return false;
        }
        q->ch[k] = p->ch[i];
        ++k, ++i;
    }
    for (; k < BLOCK_SIZE; ++k) q->ch[k] = BLS_BLANK;
    sub->tail = q, sub->len = len;
    return true;
}