status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断线性表是否为空
    return (L->next == NULL) ? TRUE : FALSE;
    /********** End **********/
}
