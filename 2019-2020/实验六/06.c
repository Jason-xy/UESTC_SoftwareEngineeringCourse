bool change_item(GoodsList* L, char* goods_id, GoodsInfo new_info)
{
    for (; L->data.goods_id == goods_id && L; L = L->next)
        ;
    GoodsInfo temp = L->data;
    temp = new_info;
    if (temp.goods_amount == new_info.goods_amount && !strcmp(temp.goods_discount, new_info.goods_discount) && !strcmp(temp.goods_id, new_info.goods_id)
        && !strcmp(temp.goods_name, new_info.goods_name) && temp.goods_price == new_info.goods_price && temp.goods_remain == new_info.goods_remain)
        return true;
    else
        return false;
}
