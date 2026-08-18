status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    // 链表不存在
    if (L == NULL) {
        return INFEASIBLE;
    }

    LinkList p = L;
    // 循环释放所有结点
    while (p != NULL) {
        LinkList temp = p->next;  // 先保存下一个
        free(p);      // 释放当前
        p = temp;
    }
    
    L = NULL;  // 必须置空，代表链表已销毁
    return OK;
    /********** End **********/
}
//必须循环释放防止内存泄漏