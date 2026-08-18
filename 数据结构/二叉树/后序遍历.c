status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //非递归实现这个算法的关键在于记录上一个访问的节点

    //首先定义一个栈
    BiTree stack[100];
    int top = -1;

    //定义一个指针用于遍历
    BiTree p = T;

    //定义一个指针用于记录上一次访问的节点，初始为NULL
    BiTree last = NULL;

    //当栈非空或者是p不是NULL的时候就一直循环处理栈
    while(p != NULL || top != -1)
    {
        //一直向左压栈
        while(p != NULL)
        {
            //先入栈
            stack[++top] = p;
            //后访问左边的节点
            p = p->lchild;
        }

        //p为NULL的时候，不是立刻退栈而是查看当前的栈顶元素
        p = stack[top];
        //当右边子树为空或者右边子树刚刚被处理的时候，访问根并弹出栈
        if(p->rchild == NULL || p->rchild == last)
        {
            visit(p);
            last = p;   //注意更新last
            top--;
            p = NULL;   //此时注意p需要置空
        }
        else
        {
            //否则右边还没有处理完成，需要先处理右边
            p = p->rchild;
        }

    }

    return OK;

    /********** End **********/
}
