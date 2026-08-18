status DeleteNode(BiTree &T,KeyType e)
//删除结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //递归有两种处理情况，对应出口。第一种是为空；第二种是找到了对应的元素为根
    //同时中间涉及到替换，所以不仅需要找到e，更关键的是他的父节点
    
    //判断是否为空
    if(T == NULL)
    {
        return ERROR;
    }

    //如果现在的根就是目标
    if(T->data.key == e)
    {

        //判断对应的三种情况
        //1. 节点的度为0
        if(T->lchild == NULL && T->rchild == NULL)
        {
            //删除根节点
            free(T);
            T = NULL; //防止野指针！！
            return OK;
        }

        //2.1 节点度为1，只有右节点
        if(T->lchild == NULL && T->rchild != NULL)
        {
            BiTree p = T;
            T = T->rchild;
            free(p);
            return OK;
        }

        //2.2 节点度为1，只有左节点
        if(T->lchild != NULL && T->rchild == NULL)
        {
            BiTree p = T;
            T = T->lchild;
            free(p);
            return OK;
        }

        //3. 节点度为2
        if(T->lchild != NULL && T->rchild != NULL)
        {
            BiTree p = T;
            T = T->lchild;

            //使用循环找到最右节点
            BiTree q = T;   //注意此时T已经被更新了！！
            while(q->rchild != NULL)
            {
                q = q->rchild;
            }

            q->rchild = p->rchild;
            free(p);
            return OK;
        }
    }

    //如果当前不是对应的节点e，那么依次递归搜索左右子树
    if(DeleteNode(T->lchild, e) == OK)
    {
        return OK;
    }

    if(DeleteNode(T->rchild, e) == OK)
    {
        return OK;
    }

    return ERROR;
    /********** End **********/
}