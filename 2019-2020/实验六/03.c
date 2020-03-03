bool insert_item(GoodsList *L, GoodsInfo goodsInfo, int choice)
{
    GoodsList *p = L;
    switch (choice)
    {
    case 0:
    {
        while(p->next)
        p = p->next;
    p->next = malloc(sizeof(GoodsList));
    p->next->data = goodsInfo;
    p->next->next = NULL;
    return true;
    }
    case 1:
    {
        p = malloc(sizeof(GoodsList));
        p->data = goodsInfo;
        p->next = L->next;
        L->next = p;
        return true;
    }
    default:
    {
        int i;
        for(i = 1;i <= choice - 2;++i)
            p = p->next;
        GoodsList *q = malloc(sizeof(GoodsList));
        q->next = p->next;
        p->next = q;
        return true;
    }
    }   
}