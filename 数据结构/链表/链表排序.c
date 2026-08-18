status sortList(LinkList &L)
{
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }
    
    //只有一个元素的时候不用排序
    if(ListLength(L) == 1)
    {
        return OK;
    }

    //利用冒泡排序
    LinkList p = L->next;
    for(int i=0; i<ListLength(L)-1; i++)
    {
        ElemType flag = 0;  //记录是否有交换
        for(int j=0; j<ListLength(L)-1-i; j++)
        {
            if(p->data > p->next->data)
            {
                flag = 1;
                ElemType temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
        if(!flag) break;
    }
    return OK;
}
