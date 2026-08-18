status GetMax(LinkList L, ElemType &max)
// 查找链表中的最大值
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //空表无法获取最大值
    if(L->next == NULL) return ERROR;

    //遍历链表查找最大值
    LinkList p = L->next;
    max = p->data;
    p = p->next;
    while(p != NULL)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }

    return OK;
    /********** End **********/
}
