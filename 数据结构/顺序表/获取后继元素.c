status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //遍历线性表查找目标元素后继
    for(int i=0; i<L.length; i++)
    {
        if(L.elem[i] == e)
        {
            //最后一个元素没有后继
            if(i == L.length-1)
            {
                return ERROR;
            }
            //其余元素存在后继
            next = L.elem[i+1];
            return OK;
        }
    }

    //查找失败
    return ERROR;
    /********** End **********/
}