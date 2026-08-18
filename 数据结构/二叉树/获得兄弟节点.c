BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //采用递归的方式查找，关键不是找对应e的节点，而是对应e的节点的父节点，防止节点丢失
    //判断当前节点是否为空,为空那么结束递归
    if(T == NULL)
    {
        return NULL;
    }

    //判断当前节点的左孩子是否为目标节点
    if(T->lchild != NULL && T->lchild->data.key == e)   //程序不能访问不允许访问的内存，所以需要先判定非空才可以访问T->lchild->data！！
    {
        return T->rchild;    //如果是那么返回右节点
    }

    //判断当前节点的右孩子是否为目标节点
    if(T->rchild != NULL && T->rchild->data.key == e)
    {
        return T->lchild;
    }

    //在当前节点没有找到对应的兄弟节点，那么依次递归左右子树查找
    //递归左子树查找
    BiTree l_target = GetSibling(T->lchild, e);
    if(l_target != NULL)
    {
        return l_target;
    }

    //递归右子树查找
    BiTree r_target = GetSibling(T->rchild, e);
    if(r_target != NULL)
    {
        return r_target;
    }

    //如果都没有找到，返回NULL
    return NULL;
    /********** End **********/
}
