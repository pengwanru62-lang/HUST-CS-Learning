
status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)          //线性表不存在的时候不清空
    {
        return INFEASIBLE;
    }

    L.length = 0;               //长度置0

    return OK;

    /********** End **********/
}
