status GetMin(SqList L, ElemType &min)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    min = L.elem[0]; // 初始化最小值为第一个元素

    //遍历线性表寻找最小值
    for(int i=1; i<L.length; i++)
    {
        if(L.elem[i] < min)
        {
            min = L.elem[i];
        }
    }
    return OK;
}