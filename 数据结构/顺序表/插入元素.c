status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断i的值是否合法
    if(i<1 || i>L.length+1) return ERROR;

    //判断插入后是否会溢出，如果溢出则重新分配空间
    if(L.length >= L.listsize)
    {
        ElemType *newelem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(newelem == NULL) //判断是否扩充失败
        {
            return ERROR;
        }
        L.elem = newelem;
        L.listsize += LISTINCREMENT;
    }
    
    //第i个以及之后元素向后移位
    for(int j=L.length-1; j>=i-1; j--)
    {
        L.elem[j+1] = L.elem[j];
    }

    //插入新元素
    L.elem[i-1] =e;

    //更新表长
    L.length++;

    return OK;
    /********** End **********/
}
