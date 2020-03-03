void output_all_items(GoodsList* L)
{
    for (L = L->next; L != NULL; L = L->next) {
        output_one_item(L);
    }
}
