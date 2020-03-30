#include "dsstring.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    Block *p,*q;
	int i,k,n,
	flag=1;	//用来标志复制是否完成，1完成，0未完成
	
	if(pos<1||pos>S.curlen||len<0||len>S.curlen-pos+1)
		return 0;
	n=len/BLOCK_SIZE; 
	if(len%BLOCK_SIZE)
	n++; // n为块的个数 
	p=(Block*)malloc(sizeof(Block));
	(*Sub).head=p;	// 生成空的Sub串 
	for(i=1;i<n;i++)
	{
		q=(Block*)malloc(sizeof(Block));
		p->next=q;
		p=q;
	}
	p->next=NULL;
	(*Sub).tail=p;
	(*Sub).curlen=len;
	for(i=len%BLOCK_SIZE; i<BLOCK_SIZE; i++)
		*(p->ch+i)=blank; // 填充Sub尾部的多余空间 
	q=(*Sub).head; // q指向Sub串即将复制的块 
	i=0;		// i指示即将复制的字符在块中的位置 
	p=S.head;	// p指向S串的当前块 
	n=0;		// n指示当前字符在串中的序号 
	while(flag)
	{
		for(k=0; k<BLOCK_SIZE; k++) // k指示当前字符在块中的位置 
		if(*(p->ch+k)!=blank)
		{
			n++;
			if(n>=pos&&n<=pos+len-1) // 复制 
			{
				if(i==BLOCK_SIZE)
				{ // 到下一块 
					q=q->next;
					i=0;
				}
				*(q->ch+i)=*(p->ch+k);
				i++;
				if(n==pos+len-1) // 复制结束 
				{
					flag=0;
					break;
				}
			}
		}
		p=p->next;
	}
	return 1;
}