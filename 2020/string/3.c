#include "dsstring.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    if (pos < 0 || len <= 0 || src.head == NULL)
        return false;
    char* temp = (char*)malloc(len * sizeof(char) + 1);
    Block *str1 = src.head, *b_temp;
    int b_num, ch_num, i, k;
    pos++;
    b_num = pos / BLOCK_SIZE;
    ch_num = pos % BLOCK_SIZE;
    for (i = 0; i < b_num; str1 = str1->next, i++)
        if (str1 == src.tail)
            return false;
    for (i = 0; i < len;) {
        for (; ch_num < BLOCK_SIZE + 1 && i < len; ch_num++) {
            *(temp + i) = str1->ch[ch_num - 1];
            i++;
        }
        str1 = str1->next;
        for (k = 0; k < BLOCK_SIZE && i < len; k++, i++) {
            *(temp + i) = str1->ch[k];
        }
    }
    sub->head = (Block*)malloc(sizeof(Block));
    str1 = sub->head->next;
    for (i = 0; i < len;) {
        str1 = (Block*)malloc(sizeof(Block));
        for (k = 0; k < BLOCK_SIZE && i < len; k++, i++) {
            str1->ch[k] = *(temp + i);
        }
        if (i == len)
            for (; k < BLOCK_SIZE; k++)
                str1->ch[k] = '#';
        sub->tail = str1;
        str1 = str1->next;
    }
    sub->len = len;
    return true;
}
