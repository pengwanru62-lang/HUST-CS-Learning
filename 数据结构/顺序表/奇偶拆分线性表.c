status SplitList(SqList L, SqList &Odd, SqList &Even)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //初始化奇数线性表和偶数线性表
    InitList(Odd);
    InitList(Even);

    //遍历原线性表，将元素分配到奇数线性表和偶数线性表中
    for(int i=0; i<L.length; i++)
    {
        if(L.elem[i] % 2 == 0) //偶数元素
        {
            ListInsert(Even, Even.length + 1, L.elem[i]);
        }
        else //奇数元素
        {
            ListInsert(Odd, Odd.length + 1, L.elem[i]);
        }
    }
    return OK;
}