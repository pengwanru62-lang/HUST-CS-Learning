status GetMax(SqList L, ElemType &max)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    max = L.elem[0]; // 初始化最大值为第一个元素

    //遍历线性表寻找最大值
    for(int i=1; i<L.length; i++)
    {
        if(L.elem[i] > max)
        {
            max = L.elem[i];
        }
    }
    return OK;
}