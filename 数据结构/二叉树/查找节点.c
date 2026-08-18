BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //终止递归的两个条件: 1.找到了相应的节点；2.空树

    //判断是否为空树，如果为空树，那么结束
    if(T == NULL)
    {
        return NULL;
    }

    //找到了相应的节点，那么返回
    if(T->data.key == e)
    {
        return T;
    }

    //没有找到的时候开始递归查找，先找左子树，后找右子树
    //递归查找左子树
    BiTree l_Node = LocateNode(T->lchild, e);
    if(l_Node != NULL)
    {
        return l_Node;
    }

    //递归查找右子树
    BiTree r_Node = LocateNode(T->rchild, e);
    if(r_Node != NULL)
    {
        return r_Node;
    }

    //如果最后都没有找到返回NULL
    return NULL;
    /********** End **********/
}
