status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)      //线性表不存在
        return INFEASIBLE;

    if(L.length == 0)       //线性表长度为0
    {
        return TRUE;
    }
    else                    //线性表长度不为0
    {
        return FALSE;
    }
    /********** End **********/
}
