status RemoveDuplicate(LinkList &L)
// 去重（要求链表已按升序排序）
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //空表或单元素表无需去重
    if(L->next == NULL || L->next->next == NULL) return OK;

    //排序
    sortList(L);
    //遍历链表，删除重复元素
    LinkList p = L->next;  //p指向当前比较节点
    while(p != NULL && p->next != NULL)
    {
        if(p->data == p->next->data)
        {
            //删除重复节点
            LinkList q = p->next;
            p->next = q->next;
            free(q);
            //p不动，继续比较新的p->next
        }
        else
        {
            p = p->next;  //移动到下一个不同值的节点
        }
    }
}