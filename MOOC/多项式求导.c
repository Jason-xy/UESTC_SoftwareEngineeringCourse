void Derivative(PolyNode *PL)//头节点不含数据元素
{
    PolyNode *p=PL->next;
    while(p)//当p不为空时
    {
        p->coef=p->coef*p->exp;//导数的系数=系数*指数
        p->exp=p->exp-1;//导数的指数=指数减一
        p=p->next;//移动到下个节点
    }
}