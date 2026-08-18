status MergeList(SqList L1, SqList L2, SqList &merged)
{
    //判断线性表是否存在
    if(L1.elem == NULL || L2.elem == NULL)
    {
        return INFEASIBLE;
    }

    //初始化合并后的线性表
    InitList(merged);

    int i = 0, j = 0; // i和j分别是L1和L2的当前元素索引

    //使用双指针法合并两个有序线性表
    while(i < L1.length && j < L2.length)
    {
        if(L1.elem[i] <= L2.elem[j])
        {
            ListInsert(merged, merged.length + 1, L1.elem[i]);
            i++;
        }
        else
        {
            ListInsert(merged, merged.length + 1, L2.elem[j]);
            j++;
        }
    }

    //如果L1还有剩余元素，全部插入到merged中
    while(i < L1.length)
    {
        ListInsert(merged, merged.length + 1, L1.elem[i]);
        i++;
    }

    //如果L2还有剩余元素，全部插入到merged中
    while(j < L2.length)
    {
        ListInsert(merged, merged.length + 1, L2.elem[j]);
        j++;
    }

    return OK;
}