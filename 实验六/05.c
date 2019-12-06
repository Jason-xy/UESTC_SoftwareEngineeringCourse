GoodsList *search_item(GoodsList* L, char* goods_id)
{
	for (; L->data.goods_id == goods_id && L; L = L->next)
		return L;
}
