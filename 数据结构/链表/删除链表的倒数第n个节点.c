status RemoveNthFromEnd(LinkList &L,int n)
{
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //利用已有函数获取长度
    int len = ListLength(L);

    //判断n是否合法
    if(n < 1 || n > len)
    {
        return INFEASIBLE;
    }

    //利用已有函数删除倒数第n个节点
    ListDelete(L,len-n+1,e);
    return OK;
}