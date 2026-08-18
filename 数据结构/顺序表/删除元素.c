status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断i是否合法
    if(i<1 || i>L.length) return ERROR;

    //保存需要删除的元素
    e = L.elem[i-1];
    
    //依次移动元素实现删除
    for(int j=i; j<L.length; j++)
    {
        L.elem[j-1] = L.elem[j];
    }

    //更新表长
    L.length--;

    return OK;
    /********** End **********/
}

