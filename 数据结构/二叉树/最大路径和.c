int MaxPathSum(BiTree T)
{
    //初始条件是二叉树T存在；操作结果是返回根结点到叶子结点的最大路径和；
    //采用递归的思想:最大的路径和等于当前值加上左右子树的最大路径和中的较大值。递归在节点为空或者是叶子节点没有孩子的时候返回
    
    //1. 节点为空
    if(T == NULL)
    {
        return 0;
    }

    //2. 该节点没有叶子节点
    if(T->lchild == NULL && T->rchild == NULL)
    {
        return T->data.key;
    }

    //3. 该节点有叶子节点
    int left = MaxPathSUm(T->lchild);
    int right = MaxPathSUm(T->rchild);

    //4. 判断哪个大，那么返回哪个
    if(left > right)
    {
        return left + T->data.key;
    }
    else
    {
        return right + T->data.key;
    }
}