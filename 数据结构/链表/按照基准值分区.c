status PartitionList(LinkList &L, ElemType pivot)
{
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //创建两个虚拟的头节点收集大于和小于pivot的情况
    LinkList lessL = InitList();
    LinkList biggerL = InitList();
    LinkList P = lessL;

    //遍历原链表分区
    LinkList p = L->next;
    while(p)
    {
        LinkList nextT = p->next;
        p->next = NULL; //断开原来的链接
        if(p->data < pivot)
        {
            lessL->next = p;
            lessL = p;
        }
        else
        {
            biggerL->next = p;
            biggerL = p;
        }
        p = nextT;
    }

    //合并两个链表
    lessL->next = biggerL->next;
    biggerL->next = NULL;   //封口
    L->next = P->next;

    return OK;
}