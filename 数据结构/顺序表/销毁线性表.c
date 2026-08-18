status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)     //表没有初始化，不能进行销毁操作
    {
        return INFEASIBLE;
    }

    free(L.elem);           //释放线性表
    L.elem = NULL;          //将指针置为NULL防止悬挂指针
    L.length = 0;           //长度置0
    L.listsize = 0;         //储存空间置0

    return OK;
    /********** End **********/
}
