status RemoveDuplicate(SqList &L)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //如果表中只有一个元素或者没有元素，则不需要删除重复元素
    if(L.length <= 1)
    {
        return OK;
    }

    //使用双重循环删除重复元素
    for(int i=0; i<L.length-1; i++)
    {
        for(int j=i+1; j<L.length; j++)
        {
            if(L.elem[i] == L.elem[j])
            {
                //再用一个循环覆盖删除重复元素
                for(int k=j; k<L.length-1; k++)
                {
                    L.elem[k] = L.elem[k+1];
                }
                L.length--; //更新表长
                j--; //调整j的值以继续检查新的位置
            }
        }
    }
}