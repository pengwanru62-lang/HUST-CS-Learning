status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断i的位置是否合法
    if(i < 1 || i > L.length)
    {
        return ERROR;
    }

    //获取元素并赋值给e
    e = L.elem[i-1];

    return OK;
    /********** End **********/
}
