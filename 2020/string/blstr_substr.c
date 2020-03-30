#include "dsstring.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    Block *p1=src.head,*p2=sub->head;
    p2=(Block*)malloc(sizeof(Block));//sub堆头节点创建
    char *pstr1,*pstr2;
    int num=0,m,i;
    if(len<=0||pos<0)//输入合法性判定
    return false;
    pstr1=(char*)malloc(len*sizeof(char)+1);
    pstr2=pstr1;
    m=pos/BLOCK_SIZE;//起始位置在第几块
    num=pos%BLOCK_SIZE-1;//起始位置下标
    for(i=0;i<m;i++)//将p1移至起始块
    {
        p1=p1->next;
        if(p1==src.tail->next)return false;//起始位置大于了块长度
    }
    for(i=0;i<len;num=0,p1=p1->next)//将需要复制的串先拷贝到pstr
    {
        for(;num%BLOCK_SIZE!=0&&i<len;i++)
        *(pstr2++)=p1->ch[num++];
    }
    pstr2=pstr1
    for(i=0;i<len;p2=p2->next)
    {
        for(num=0;num%BLOCK_SIZE!=0&&i<len;i++)
        {
            p2->next=(Block*)malloc(sizeof(Block));//提前开辟下一块区域
            p2->ch[num]=*(pstr2++);//储存在现在的区域
        }
    }

    free(pstr1);//释放临时串
    sub->len=len;
    sub->tail=p2;
    return true;
}