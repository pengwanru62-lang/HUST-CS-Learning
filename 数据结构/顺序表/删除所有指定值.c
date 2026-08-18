status DeleteVal(SqList &L, ElemType e)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //使用双指针法删除值为e的元素
    int i = 0; //慢指针，指向下一个要被覆盖的位置
    for(int j=0; j<L.length; j++) //快指针，遍历线性表
    {
        if(L.elem[j] != e) //如果当前元素不等于e，则将其保留
        {
            L.elem[i] = L.elem[j]; //覆盖慢指针位置的元素
            i++; //慢指针向后移动
        }
    }

    //更新表长
    L.length = i;

    return OK;
}