status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断i的位置是否合法
    if(i<1) return ERROR;

    //遍历链表匹配是否存在目标元素
    int cnt=1;
    LinkList p = L->next;
    while(p != NULL && cnt < i)
    {
        p = p->next;
        cnt++;
    }

    if(p != NULL) //成功找到元素
    {
        e = p->data;
        return OK;
    }

    return ERROR;   //i的值超过表长

    /********** End **********/
}
