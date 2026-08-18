BiTree LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2)
{
    //初始条件是二叉树T存在；操作结果是该二叉树中e1结点和e2结点的最近公共祖先；
    //思路是采用递归，本质上是需要找到e1 e2分叉的节点

    //1. 节点为空
    if(T == NULL)
    {
        return NULL;
    }

    //2. 该节点是e1或e2
    if(T->data.key == e1 || T->data.key == e2)
    {
        return T;   //这里返回的不是最后的值，而是向它的父节点说明它是一个e1或e2的节点
    }

    //3. 这个节点不是空或者是两个元素的任何一个，那么递归左右子树查找
    BiTree left = LowestCommonAncestor(T->lchild, e1, e2);
    BiTree right = LowestCommonAncestor(T->rchild, e1, e2);

    //4. 判断左右子树是否返回了e1或e2
    if(left != NULL && right != NULL)
    {
        return T; //这里才是返回的最后节点，实际上是第一个分叉的位置
    }

    //5. 如果只有左边找到
    if(left != NULL)
    {
        return left;
    }

    //6. 如果只有右边找到
    return right;
}
