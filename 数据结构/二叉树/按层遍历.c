status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //层序遍历必须使用队列，先进先出，每一次访问一个节点就把他的左右子节点入队

    //首先判断树是否为空
    if(T == NULL)
    {
        return OK;
    }

    //定义一个队列
    BiTree queue[100];
    int front = 0;
    int rear = -1;

    //根节点入队
    queue[++rear] = T;

    //当队列非空就一致循环处理队列
    while(front <= rear)
    {
        //队首元素出队
        BiTree p = queue[front++];
        //访问出队的节点
        visit(p);
        //同时让不为空的左右子树分别按顺序入队
        if(p->lchild != NULL)
        {
            queue[++rear] = p->lchild;
        }
        if(p->rchild != NULL)
        {
            queue[++rear] = p->rchild;
        }
    }

    return OK;
    /********** End **********/
}