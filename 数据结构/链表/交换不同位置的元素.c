status SwapElem(LinkList &L, int i, int j)
// 交换链表中第i个和第j个位置元素的值（不交换节点指针）
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断位置是否合法
    if(i < 1 || j < 1) return ERROR;

    //定位第i个节点
    LinkList p = L->next;
    int cnt = 1;
    while(p != NULL && cnt < i)
    {
        p = p->next;
        cnt++;
    }
    if(p == NULL) return ERROR;  //i超出表长

    //定位第j个节点
    LinkList q = L->next;
    cnt = 1;
    while(q != NULL && cnt < j)
    {
        q = q->next;
        cnt++;
    }
    if(q == NULL) return ERROR;  //j超出表长

    //交换两个节点的数据域（不交换节点本身）
    ElemType temp = p->data;
    p->data = q->data;
    q->data = temp;

    return OK;
    /********** End **********/
}