BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //终止递归的两个条件: 1.找到了相应的节点；2.空树

    //判断是否为空树，如果为空树，那么结束
    if(T == NULL)
    {
        return NULL;
    }

    //找到了相应的节点，那么返回
    if(T->data.key == e)
    {
        return T;
    }

    //没有找到的时候开始递归查找，先找左子树，后找右子树
    //递归查找左子树
    BiTree l_Node = LocateNode(T->lchild, e);
    if(l_Node != NULL)
    {
        return l_Node;
    }

    //递归查找右子树
    BiTree r_Node = LocateNode(T->rchild, e);
    if(r_Node != NULL)
    {
        return r_Node;
    }

    //如果最后都没有找到返回NULL
    return NULL;
    /********** End **********/
}

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //首先需要保证关键字不重复
    BiTree judge = LocateNode(T, c.key);
    if(judge != NULL)
    {
        return ERROR;
    }

    //创建新节点target指向需要插入的目标值
    BiTree target = NULL;

    //插入根节点
    if(LR == -1)
    {
        //生成新节点
        target = (BiTree)malloc(sizeof(BiTNode));
        target->data = c;
        target->lchild = NULL;
        target->rchild = T; //根不一定是NULL！！

        //赋值target给T
        T = target;
        return OK;
    }

    //如果不是根节点那么需要先定位到目标位置
    BiTree node = LocateNode(T, e);
    if(node == NULL)
    {
        //没找到返回ERROR
        return ERROR;
    }

    //生成新节点
    target = (BiTree)malloc(sizeof(BiTNode));
    target->data = c;
    target->lchild = NULL;
    target->rchild = NULL;

    //开始根据LR确定插入位置
    //插入左节点
    if(LR == 0)
    {
        target->rchild = node->lchild;
        node->lchild = target;
        return OK;
    }
    //插入右节点
    else if(LR == 1)
    {
        target->rchild = node->rchild;
        node->rchild = target;
        return OK;
    }
    else
    {
        return ERROR;
    }

    /********** End **********/
}