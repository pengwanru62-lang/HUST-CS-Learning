status ReverseList(SqList &L)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //使用双指针法进行线性表反转
    int left = 0;              //左指针初始化为第一个元素
    int right = L.length - 1;  //右指针初始化为最后一个
    while(left<right)
    {
        //交换元素
        ElemType temp = L.elem[left];
        L.elem[left] = L.elem[right];
        L.elem[right] = temp;

        //指针向中间移动
        left++;
        right--;
    }
    return OK;
}