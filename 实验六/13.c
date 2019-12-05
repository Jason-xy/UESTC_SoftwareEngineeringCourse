#include "lab52.h" // 请不要删除本行头文件，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

extern int CurrentCnt; // 请不要删除本行的全局变量声明，否则检查不通过

GoodsInfo read_goods_info()
{
    GoodsInfo goods;
    read_line(goods.goods_id, MAX_ID_LEN);
    read_line(goods.goods_name, MAX_NAME_LEN);
    scanf("%d", &goods.goods_price);
    read_line(goods.goods_discount, MAX_PRICE_LEN);
    scanf("%d", &goods.goods_amount);
    scanf("%d", &goods.goods_remain);
    return goods;
}
