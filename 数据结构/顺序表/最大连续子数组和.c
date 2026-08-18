status MaxSubArray(SqList& L, int& maxSum)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    maxSum = L.elem[0];         // 初始化最大子数组和为第一个元素
    int currentSum = L.elem[0]; // 当前子数组和也初始化为第一个元素

    for(int i = 1; i < L.length; i++)
    {
        // 如果当前子数组和为负数，则从当前元素重新开始计算
        if(currentSum < 0)
        {
            currentSum = L.elem[i];
        }
        else
        {
            currentSum += L.elem[i];
        }

        // 更新最大子数组和
        if(currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }
    return OK;
}