//ClearList 的本质：删数据，不删结构.所以头节点还在

status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历清空线性表
    LinkList p = L->next;
    while(p != NULL)
    {
        LinkList temp = p->next;   //保存下一个节点
        free(p);                   //释放当前节点
        p = temp;
    }

    //保存头节点但是头节点next为空
    L->next = NULL;

    return OK;
    /********** End **********/
}
