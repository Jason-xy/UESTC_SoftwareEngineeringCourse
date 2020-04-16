typedef int ElemType;

// 非零元素结点结构
typedef struct OLNode
{
    int row,col;
    ElemType value;
    struct OLNode *right,*down;
}OLNode,*OLink;

// 十字链表结构
typedef struct
{
    OLink *rowhead,*colhead;
    int rows,cols,nums;
}CrossList, *PCrossList;

//////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "crosslist.h"
//#define OVERFLOW 0
int init_cross_list(PCrossList L, const ElemType *A, int m,int n){
    int i,num=0;
    OLink p,q;
    L->nums=m*n;
    L->rows=m;
    L->cols=n;
    //if(!(L->rowhead=(OLink)malloc(sizeof(OLNode)*(m+1))))
    L->rowhead=(OLink)malloc(sizeof(OLNode)*(m+1));
        //exit(OVERFLOW);
    //if(!(L->colhead=(OLink)malloc(sizeof(OLNode)*(n+1))))
    L->colhead=(OLink)malloc(sizeof(OLNode)*(n+1));
        //exit(OVERFLOW);
    for(i=0;i<m;i++)
    L->rowhead[i]=NULL;
    for(i=0;i<n;i++)
    L->colhead[0]=NULL;
    for(i=0;i!=L->nums;i++)
    {
        if(A[i]!=0)
        {
            num++;
            //if(!(p=(OLNode*)malloc(sizeof(OLNode))))
              //exit(OVERFLOW);
            p=(OLNode*)malloc(sizeof(OLNode));
            p->row=(i+1)/n+1;
            p->col=i%n+1;
            p->value=A[i];
            p->right=NULL;
            p->down=NULL;
            if(L->rowhead[(i+1)/n]->value==0)
                L->rowhead[(i+1)/n]=p;
            else
            {
                q=L->rowhead[(i+1)/n];
                while(q->right!=NULL&&q->right->col!=n)
                    q=q->right;
                    p->right=q->right;
                    q->right=p;
            }
            if(L->colhead[i%n]->value==0)
                L->colhead=p;
            else
            {
                q=L->colhead[i%n];
                while(q->down!=NULL&&q->down->row!=m)
                    q=q->down;
                    p->down=q->down;
                    q->down = p;
            }
        }
    }
    return num;
}


int del_cross_list(PCrossList L, ElemType k){
    int i,j,num=0;
    OLink q,lift,up;
    for(i=0;i<L->rows;L++)
    {
        for(lift=NULL,q=L->rowhead[i];q;lift=q,q=q->right)
        {
            if(q->value==k)
            {
                lift->right=q->right;
            }
            j=q->col-1;
            for(up=L->colhead[j];up->down==q;up=up->down);
            up->down=q->down;
            free(q);
        }
    }
}
