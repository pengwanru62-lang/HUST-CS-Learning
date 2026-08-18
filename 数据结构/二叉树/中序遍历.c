status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //非递归实现的整体思路是：首先创建一个栈，向左一路压栈，为空的时候转向右子树

    //定义栈
    BiTree stack[100];
    int top = -1;

    //定义一个遍历指针
    BiTree p = T;
    //当栈非空或者是p不是NULL的时候就一直循环
    while(p != NULL || top != -1)
    {
        while(p != NULL)
        {
            //当前p入栈
            stack[++top] = p;
            //p向左走
            p = p->lchild;
        }
        
        //此时p为空，退栈
        p = stack[top--];
        visit(p);

        //转向右边
        p = p->rchild;
    }

    return OK;
    /********** End **********/
}