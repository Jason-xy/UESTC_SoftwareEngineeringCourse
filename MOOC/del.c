int del(Seqlest *L,int i, int k)
{
    int j;
    if(i<1||i>L->last+1)//判断i是否合法   last为最后一个元素在数组中的脚标
    {
        printf("输入i非法");
        return 0;
    }
    if(i+k>=L->last+1)//i后元素不够k时,或者刚好为k时
    {
        L->last=i-1;//删除i后全部元素，将第i个元素作为表尾
        return 1;
    }
    else//第i个元素后多于k个元素时
    {
        for(j=0;j<L->last+1-k;j++)//尾部剩余的last+1-k个元素需要移动
        L->elem[j+i]=L->elem[j+k+i];
        L->last=L->last-k;//减少了k个元素
        return 1;
    }
}