status BatchDelete(SqList &L, int pos, int n)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断删除位置是否合法
    if(pos<1 || pos>L.length || pos + n - 1>L.length)
    {
        return ERROR;
    }

    //将pos+n位置及之后的元素向前移动n个位置
    for(int i=pos + n - 1; i<L.length; i++)
    {
        L.elem[i - n] = L.elem[i];
    }

    //更新表长
    L.length -= n;

    return OK;
}