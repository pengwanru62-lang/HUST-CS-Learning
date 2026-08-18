status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //依次遍历输出元素
    for(int i=0; i<L.length; i++)
    {
        printf("%d ",L.elem[i]);
    }

    return OK;
    /********** End **********/
}