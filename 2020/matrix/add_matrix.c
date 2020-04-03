#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ)
{
    int i,j,km=0,kn=0,kq=0;

    if(pM->m!=pN->m||pM->n!=pN->n)
        return false;
    // if(pM->len==0)pQ=pN;
    // if(pN->len==0)pQ=pM;
    // if(pQ==pN||pQ==pM)return true;
    for(i=1;i<=pM->m&&km<=pM->len&&kn<=pN->len;i++)
    {
        for(j=1;j<=pM->n&&km<=pM->len&&kn<=pN->len;j++)
        {
            if(pM->data[km].i==i&&pM->data[km].j==j)
            {
                pQ->data[kq++].e=pM->data[km++].e;
                if(pN->data[kn].i==i&&pN->data[kn].j==j)
                {
                    pQ->data[kq-1].e+=pN->data[kn++].e;
                    if(pQ->data[kq-1].e==0)
                    {
                        kq--;
                        continue;
                    }
                }
                pQ->data[kq-1].i=i;
                pQ->data[kq-1].j=j;
            }
            else if(pN->data[kn].i==i&&pN->data[kn].j==j)
            {
                pQ->data[kq++].e=pN->data[kn++].e;
                if(pQ->data[kq-1].e==0)
                {
                        kq--;
                        continue;
                }
                pQ->data[kq-1].i=i;
                pQ->data[kq-1].j=j;
            }
        }
    }
    pQ->m=pM->m;
    pQ->n=pM->n;
    pQ->len=kq;
    return true;
}