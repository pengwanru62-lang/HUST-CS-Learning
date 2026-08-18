status InvertTree(BiTree T)
{
    //初始条件是二叉树T存在；操作结果是将T翻转，使其所有结点的左右结点互换；
    //思路是采用递归的思想，将每个节点的左右子树交换即可
    if(T == NULL)
    {
        return OK;
    }

    //交换左右子树
    BiTree temp = T->rchild;
    T->rchild = T->lchild;
    T->lchild = temp;

    //递归左右子树
    InvertTree(T->lchild);
    InvertTree(T->rchild);

    return OK;
}