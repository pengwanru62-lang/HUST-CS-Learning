status ClearBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    
    //判断二叉树是否为空树，这也是递归的终止条件
    if(T == NULL)
    {
        return OK;
    }

    //递归释放左子树
    ClearBiTree(T->lchild);

    //递归释放右子树
    ClearBiTree(T->rchild);

    //释放当前结点
    free(T);

    //将指针置为NULL防止悬挂指针
    T = NULL;

    return OK;

    /********** End **********/
}

/*核心思想：

先释放左子树
再释放右子树
最后释放当前结点

因为如果先释放当前结点：free(T);

后面：T->lchild T->rchild就访问不到了。

这是典型的：后序遍历删除*/