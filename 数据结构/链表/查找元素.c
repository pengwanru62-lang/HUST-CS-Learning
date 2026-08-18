status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历线性表查找是否存在目标元素
    LinkList p = L->next;
    int i=1;    //元素逻辑序号
    while(p != NULL)
    {
        if(p->data == e) return i;
        i++;
        p = p->next;
    }

    if(p == NULL) return ERROR; //
    /********** End **********/
}
