int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断二叉树是否为空树，空树深度返回0，并且终止递归
    if(T == NULL)
    {
        return 0;
    }
    
    //递归求左子树深度
    int leftDepth = BiTreeDepth(T->lchild);

    //递归求右子树深度
    int rightDepth = BiTreeDepth(T->rchild);

    //返回左右子树深度较大的那个,递归终止的另外一个条件
    return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;

    /********** End **********/
}

/*核心思想：
递归求左子树深度
递归求右子树深度
返回左右子树深度较大的那个,递归终止的另外一个条件*/
