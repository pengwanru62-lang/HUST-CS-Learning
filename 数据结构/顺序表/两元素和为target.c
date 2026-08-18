status TwoSum(SqList L, int target, int &idx1, int &idx2)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //前提线性表是有序的
    int left = 0;              //左指针初始化为第一个元素
    int right = L.length - 1;  //右指针初始化为最后一个元素

    while(left < right)
    {
        int sum = L.elem[left] + L.elem[right]; //计算当前指针指向的两个元素的和

        if(sum == target) //如果找到目标和，返回下标
        {
            idx1 = left + 1; //返回逻辑下标
            idx2 = right + 1;
            return OK;
        }
        else if(sum < target) //如果当前和小于目标和，左指针向右移动增加和
        {
            left++;
        }
        else //如果当前和大于目标和，右指针向左移动减少和
        {
            right--;
        }
    }

    return ERROR; //没有找到满足条件的两个数
}