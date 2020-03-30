#include "dsstring.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    if(pos<0||len<=0||src.head==NULL)
    return false;
    char *temp=(char*)malloc(len*sizeof(char)+1);
    Block *str1=src.head->next,*b_temp;
    int b_num,ch_num,i,k;
    b_num=pos/BLOCK_SIZE;
    ch_num=pos%BLOCK_SIZE;
    for(i=0;i<b_num-1;str1=str1->next,i++)if(str1->ch[0]<48||str1->ch[0]>122)return false;
    for(i=0;i<len;)
    {
        for(;ch_num<BLOCK_SIZE&&i<len;ch_num++)
        {
            *(temp+i)=str1->ch[ch_num];
            i++;
        }
        str1=str1->next;
        for(k=0;k<BLOCK_SIZE&&i<len;k++,i++)
        {
            *(temp+i)=str1->ch[k];
        }
    }
    b_temp=(Block*)malloc(sizeof(Block));
    sub->head=str1=b_temp;
    for(i=0;i<len;)
    {
        str1->next=(Block*)malloc(sizeof(Block));
        for(k=0;k<BLOCK_SIZE&&i<len;k++,i++)
        {
            str1->ch[k]=*(temp+i);
        }
        if(i==len)
            for(;k<BLOCK_SIZE;k++)
                str1->ch[k]='#';
        sub->tail=str1;        
        str1=str1->next=NULL;
    }
    sub->len=len;
    return true;
}