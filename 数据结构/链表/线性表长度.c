int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历线性表求表长
    LinkList p = L->next;
    int cnt = 0;
    while(p != NULL)
    {
        cnt++;
        p = p->next;
    }

    return cnt;
    /********** End **********/
}
