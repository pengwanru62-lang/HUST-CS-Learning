status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断T是否为空
    if(T == NULL)
    {
        return OK;
    }

    //T非空的时候进行先序遍历
    if(T)
    {
        //根
        visit(T);
        //左
        PreOrderTraverse(T->lchild, visit); //visit是函数本身（对应函数地址），而visit()是函数调用
        //右
        PreOrderTraverse(T->rchild, visit);
    }

    return OK;
    /********** End **********/
}
