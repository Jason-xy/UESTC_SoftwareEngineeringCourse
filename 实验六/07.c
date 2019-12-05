#include "lab52.h" // 请不要删除本行头文件，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

extern int CurrentCnt; // 请不要删除本行的全局变量声明，否则检查不通过

void output_one_item(GoodsList* p)
{
    if (p) {
        GoodsInfo temp = p->data;
        printf("%s\n%s\n%d\n%s\n%d\n%d\n", temp.goods_id, temp.goods_name, temp.goods_price, temp.goods_discount, temp.goods_amount, temp.goods_remain);
    }
}
