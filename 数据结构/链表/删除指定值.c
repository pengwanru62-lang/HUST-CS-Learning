status DeleteVal(LinkList &L, ElemType e)
// 删除链表中所有值为e的节点
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //使用双指针法删除所有值为e的节点
    LinkList p = L->next;      //当前节点
    LinkList pre = L;          //前驱节点（初始为头结点）
    
    while(p != NULL)
    {
        if(p->data == e)
        {
            //删除当前节点
            LinkList q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
            //pre不动，继续检查新的p
        }
        else
        {
            //两个指针同时后移
            pre = p;
            p = p->next;
        }
    }

    return OK;
    /********** End **********/
}
