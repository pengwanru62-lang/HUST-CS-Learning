status BatchInsert(SqList &L, int pos, ElemType arr[], int n)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断插入位置是否合法
    if(pos < 1 || pos > L.length + 1)
    {
        return ERROR;
    }

    //判断是否需要扩容，如果需要则重新分配空间
    while(L.length+n > L.listsize)
    {
        ElemType *newelem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newelem)
        {
            return ERROR;
        }
        L.elem = newelem;
        L.listsize += LISTINCREMENT;
    }

    //将插入位置及之后的元素向后移动n个位置
    for(int i=L.length - 1; i>=pos-1; i--)
    {
        L.elem[i + n] = L.elem[i];
    }

    //将新元素插入到指定位置
    for(int i=0; i<n; i++)
    {
        L.elem[pos - 1 + i] = arr[i];
    }   

    //更新表长
    L.length += n;

    return OK;
}