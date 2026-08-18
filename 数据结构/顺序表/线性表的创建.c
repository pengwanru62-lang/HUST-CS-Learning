status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    //第一步：判断线性表是否存在,存在则返回INFEASIBLE
    if(L.elem != NULL)
    {
        return INFEASIBLE;
    }

    //第二步：线性表L不存在时，分配空间
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType)); 
    if(L.elem == NULL)
    {
        return OVERFLOW;    
    }

    //第三步：初始化长度和当前实际储存空间大小
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    //第四步：初始化成功，则返回
    return OK;
    /********** End **********/
}
