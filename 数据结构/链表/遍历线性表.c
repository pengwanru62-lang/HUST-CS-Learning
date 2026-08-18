status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历输出线性表的每一个元素
    LinkList p = L->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }

    return OK;
    /********** End **********/
}