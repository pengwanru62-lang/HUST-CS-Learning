status GetMin(LinkList L, ElemType &min)
// 查找链表中的最小值
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //空表无法获取最小值
    if(L->next == NULL) return ERROR;

    //遍历链表查找最小值
    LinkList p = L->next;
    min = p->data;
    p = p->next;
    while(p != NULL)
    {
        if(p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }

    return OK;
    /********** End **********/
}