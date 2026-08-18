status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L != NULL)
    {
        return INFEASIBLE;  //如果线性表存在，不能初始化
    }

    //若线性表不存在则构造一个空的线性表
    L = (LinkList)malloc(sizeof(LNode));
    if(!L) return ERROR;
    L->next = NULL;

    return OK;

    /********** End **********/
}