status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历查找元素e的前驱
    LinkList p = L->next;
    LinkList pr = L;    //前驱指针
    while(p != NULL)
    {
        if(p->data == e)
        {
            //第一个元素没有前驱
            if(p == L->next) return ERROR;
            //其余元素存在前驱
            pre = pr->data;
            return OK;
        }
        //指针后移
        pr = p; 
        p = p->next;
    }

    return ERROR; //遍历完成没有匹配成功
    /********** End **********/
}