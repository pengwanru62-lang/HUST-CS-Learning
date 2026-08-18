status SubArrayNum(SqList& L, int &k, int &cnt)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    cnt = 0; // 初始化计数器

    // 双重循环枚举所有子数组，计算子数组和并与k比较
    for(int i=0; i<L.length; i++)
    {
        int sum = 0;
        for(int j=i; j<L.length; j++)
        {
            sum += L.elem[j];
            if(sum == k)
            {
                cnt++; // 找到一个子数组和为k，计数器加1
            }
        }
    }
    return OK;
}