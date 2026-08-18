status reverseList(LinkList &L)
{
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //采用头插法逆置链表
    LinkList p = L->next;   ///从第二个节点开始遍历,p指向需要头插的元素
    L->next = NULL;

    while(p)
    {
        LinkList q = p->next;   //先保存下一个节点
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return OK;
}