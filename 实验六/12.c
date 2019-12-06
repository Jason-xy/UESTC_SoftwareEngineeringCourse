void bubble_sort(GoodsList* L)
{
	if (!L)
	{
		return;
	}
	else
	{
		GoodsList* tail = NULL;
		GoodsList* flag = NULL;
		while (flag != L)
		{
			tail = flag;
			flag = L;
			GoodsList* pre = L;
			while (pre->next != tail)
			{
				GoodsList* cur = pre->next;
				if (pre->data.goods_price > cur->data.goods_price)
				{
					int temp = pre->data.goods_price;
					pre->data.goods_price = cur->data.goods_price;
					cur->data.goods_price = temp;
					flag = pre->next;
				}
				pre = pre->next;
			}
		}
	}
}
