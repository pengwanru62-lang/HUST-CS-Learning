status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断删除位置i是否合法
    if(i < 1) return ERROR;

    //遍历定位目标删除位置
    LinkList p = L->next;
    LinkList pre = L;
    int cnt = 1;
    while(p != NULL && cnt++ < i)
    {
        pre = p;
        p = p->next;
    }

    //判断i的位置是否合法
    if(p == NULL) return ERROR;

    //保存删除的值
    e = p->data;
    
    //释放并改变链表连接
    pre->next = p->next;
    free(p);

    return OK;
    /********** End **********/
}