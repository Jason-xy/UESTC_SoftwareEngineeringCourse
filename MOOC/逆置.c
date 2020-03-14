NodeList* Reverse(NodeList* L)
{
    if(L||L->next)//判断没有节点和只有一个节点的情况
    {
        return L;
    }
    NodeList* pCur=L;//当前节点
    NodeList* pPre=L->next;//当前的下一个节点
    NodeList* pTemp=NULL;
    while(pPre)//逆置操作 直到最后一个节点
    {
            pTemp=pCur;//保存当前节点指针位置
            pCur=pCur->next;//将当前节点指针后移
            pPre->next=pTemp;//倒置节点
            pPre=pCur->next;//将下一个节点指针后移
    }
    return pCur;
}