status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断i的位置是否合法
    if(i < 1) return ERROR;

    //遍历线性表定位第i个元素
    int cnt = 1;
    LinkList p = L->next;
    LinkList pr = L;
    while(p != NULL && cnt++ < i)
    {
        pr = p;
        p = p->next;
    }

    if(p == NULL && cnt != i) return ERROR; //i的位置非法 
    
    //在第i个元素前插入目标元素
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    pr->next = q;
    q->next = p;

    return OK;
    /********** End **********/
}
