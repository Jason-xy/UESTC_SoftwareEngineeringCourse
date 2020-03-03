#include "lab52.h" // 请不要删除本行头文件，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

extern int CurrentCnt; // 请不要删除本行的全局变量声明，否则检查不通过

void init_list(GoodsList** L)
{
    FILE* fp;
    GoodsInfo goodsInfo;
    GoodsList *p, *r;

    (*L) = (GoodsList*)malloc(sizeof(GoodsList));
    r = (*L);
    if ((fp = fopen(GOODS_FILE_NAME, "r")) == NULL) {
        if ((fp = fopen(GOODS_FILE_NAME, "w")) == NULL)
            printf("提示：不能创建商品文件\n");
    } else {
        while (!feof(fp)) {
            fscanf(fp, "%s", goodsInfo.goods_id);
            fscanf(fp, "\t%s", goodsInfo.goods_name);
            fscanf(fp, "\t%d", &goodsInfo.goods_price);
            fscanf(fp, "\t%s", goodsInfo.goods_discount);
            fscanf(fp, "\t%d", &goodsInfo.goods_amount);
            fscanf(fp, "\t%d\n", &goodsInfo.goods_remain);
            p = (GoodsList*)malloc(sizeof(GoodsList));
            p->data = goodsInfo;
            r->next = p;
            r = p;
            CurrentCnt++;
        }
    }
    fclose(fp);
    r->next = NULL;
    printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
}
