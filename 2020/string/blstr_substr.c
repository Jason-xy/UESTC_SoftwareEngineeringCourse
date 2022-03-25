#include "dsstring.h" // �벻Ҫɾ���������鲻ͨ��
#include <stdio.h>
#include <stdlib.h>

//����icoding������������������ӭ��icoding�ģ����ݴ�����2022.3.25���ܹ��ģ����Ǹ㲻��������
//�������������⣬��icoding���ѵ���Ī���ڲ²�����
bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    if (len == 0) return false;
    if (pos + len - 1 >= src.len) len = src.len - pos; //len������ԭ�ַ��������˻�������ҳɹ���Ҳ�Ƿ���icoding��
    int d = pos / BLOCK_SIZE, r = pos % BLOCK_SIZE;
    Block* p = src.head, *q = sub->head; int i;
    for (i = 0; i < d; ++i) p = p->next;
    i = r; int j, k = BLOCK_SIZE, first = 1; //i, pָ��src, k, qָ��sub
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