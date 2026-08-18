status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历线性表匹配e并获取后继
    LinkList p = L->next;
    while(p != NULL)  
    {
        if(e == p->data)
        {
            if(p->next == NULL) return ERROR;  //最后一个元素没有后继
            next = p->next->data;
            return OK;
        }
        p = p->next;
    }

    return ERROR;  //查找失败
    /********** End **********/
}