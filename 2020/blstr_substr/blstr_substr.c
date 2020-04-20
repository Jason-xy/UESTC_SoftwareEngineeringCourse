#include "dsstring.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    Block *temp, *source;
    source = src.head;
    int ori = 0, des = 0, srclen = src.len;
    temp = (Block*)malloc(sizeof(Block));
    temp->next = NULL;
    if (pos >= src.len || len <= 0) {
        return false;
    } else {
        sub->head = temp;
        while (pos > 0) {
            if (ori == BLOCK_SIZE) {
                ori = 0;
                source = source->next;
            }
            ori++;
            pos--;
            srclen--;
        }
        while (len > 0 && srclen > 0) {
            if (ori == BLOCK_SIZE) {
                ori = 0;
                source = source->next;
            }
            if (des == BLOCK_SIZE) {
                des = 0;
                temp->next = (Block*)malloc(sizeof(Block));
                temp = temp->next;
                temp->next = NULL;
            }
            temp->ch[des] = source->ch[ori];
            des++;
            ori++;
            srclen--;
            len--;
            sub->len++;
        }
        while (des < BLOCK_SIZE) {
            temp->ch[des] = BLS_BLANK;
            des++;
        }
        sub->tail = temp;
        return true;
    }
}