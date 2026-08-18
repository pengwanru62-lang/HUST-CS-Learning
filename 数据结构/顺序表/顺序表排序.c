status sortList(SqList& L)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //使用冒泡排序算法对线性表进行排序
    for(int i=0; i<L.length-1; i++)
    {
        for(int j=0; j<L.length-1-i; j++)
        {
            if(L.elem[j] > L.elem[j+1])
            {
                //交换元素
                ElemType temp = L.elem[j];
                L.elem[j] = L.elem[j+1];
                L.elem[j+1] = temp;
            }
        }
    }
    return OK;
}