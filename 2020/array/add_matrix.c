#include "tsmatrix.h"
#include <stdio.h>
#include <stdlib.h>

bool add_matrix(const TSMatrix* pM, const TSMatrix* pN, TSMatrix* pQ) //这种写法不好看，但是能简单明了的解决问题，以后有机会可以写新算法
{
    int i = 0, j = 0, k = 0, temp;
    if (pM->m != pN->m || pM->n != pN->n)
        return false;

    pQ->m = pM->m;
    pQ->n = pM->n;
    pQ->len = 0;

    while (i < pM->len && j < pN->len && k < MAXSIZE) {
        if (pM->data[i].i < pN->data[j].i) {
            pQ->data[k].i = pM->data[i].i;
            pQ->data[k].j = pM->data[i].j;
            pQ->data[k].e = pM->data[i].e;
            pQ->len++;
            k++;
            i++;
        } else if (pM->data[i].i == pN->data[j].i) {
            if (pM->data[i].j == pN->data[j].j) {
                temp = pM->data[i].e + pN->data[j].e;
                if (temp == 0) {
                    i++;
                    j++;
                } else {
                    pQ->data[k].i = pM->data[i].i;
                    pQ->data[k].j = pM->data[i].j;
                    pQ->data[k].e = temp;
                    pQ->len++;
                    k++;
                    i++;
                    j++;
                }
            } else if (pM->data[i].j > pN->data[j].j) {
                pQ->data[k].i = pN->data[j].i;
                pQ->data[k].j = pN->data[j].j;
                pQ->data[k].e = pN->data[j].e;
                pQ->len++;
                k++;
                j++;
            } else {
                pQ->data[k].i = pM->data[i].i;
                pQ->data[k].j = pM->data[i].j;
                pQ->data[k].e = pM->data[i].e;
                pQ->len++;
                k++;
                i++;
            }
        } else {
            pQ->data[k].i = pN->data[j].i;
            pQ->data[k].j = pN->data[j].j;
            pQ->data[k].e = pN->data[j].e;
            pQ->len++;
            k++;
            j++;
        }
    }

    if (i < pM->len) {
        while (i < pM->len && k < MAXSIZE) {
            pQ->data[k].i = pM->data[i].i;
            pQ->data[k].j = pM->data[i].j;
            pQ->data[k].e = pM->data[i].e;
            pQ->len++;
            k++;
            i++;
        }

    } else if (j < pN->len) {
        while (j < pN->len && k < MAXSIZE) {
            pQ->data[k].i = pN->data[j].i;
            pQ->data[k].j = pN->data[j].j;
            pQ->data[k].e = pN->data[j].e;
            pQ->len++;
            k++;
            j++;
        }
    }
    return true;
}