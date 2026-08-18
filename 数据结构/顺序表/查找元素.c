int LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //遍历查找目标元素e
    for(int i=0; i<L.length; i++)
    {
        //判断是否找到目标元素
        if(L.elem[i] == e)
        {
            return i+1; //返回元素逻辑下标
        }
    }

    //查找失败
    return ERROR;
    /********** End **********/
}