status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //遍历查找元素e的前驱
    for(int i=0; i<L.length; i++)
    {
        if(L.elem[i] == e)
        {
            //第一个元素没有前驱
            if(i == 0)
            {
                return ERROR;
            }
            //其余元素存在前驱
            pre = L.elem[i-1];
            return OK;
        }      
    }
    
    //查找失败
    return ERROR;
    /********** End **********/
}
