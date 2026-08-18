status DeleteRange(LinkList &L, ElemType min, ElemType max)
// 删除所有值在 [min, max] 范围内的节点；返回OK；表不存在返回INFEASIBLE
{
    /********** Begin *********/
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    if(L->next == NULL) return OK;  // 空表无需删除

    LinkList prev = L;          // 前驱节点（初始为头结点）
    LinkList curr = L->next;    // 当前节点

    while(curr != NULL)
    {
        if(curr->data >= min && curr->data <= max)
        {
            // 匹配到待删除节点
            LinkList temp = curr;
            prev->next = curr->next;  // 跳过当前节点
            curr = curr->next;        // 移动到下一个
            free(temp);               // 释放内存
        }
        else
        {
            // 不匹配，两个指针同步后移
            prev = curr;
            curr = curr->next;
        }
    }
    return OK;
    /********** End **********/
}