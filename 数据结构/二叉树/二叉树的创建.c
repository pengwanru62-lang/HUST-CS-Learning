status CreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //定义一个静态变量用于指示当前访问位置的下标
    static KeyType index = 0;

    //获取到当前访问的元素的类型
    TElemType elem = definition[index++];

    //判断是否为空树(递归的终止条件)
    if(elem.key == 0)
    {
        T = NULL;
        return OK;
    }

    //判断关键字是否有重复，从访问过后的节点开始排查
    for(int i=0; i<index-1; i++)    //之前index已经++了，此处不可以让index不匹配
    {
        if(elem.key == definition[i].key)
        {
            return ERROR;
        }
    }

    //创建新节点
    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = elem;
    T->lchild = NULL;   //初始默认为NULL，防止野指针随机值
    T->rchild = NULL;   //初始默认为NULL，防止野指针随机值

    //开始递归生成树
    if(CreateBiTree(T->lchild, definition) == ERROR)    //先生成左子树
    {
        return ERROR;
    }

    if(CreateBiTree(T->rchild, definition) == ERROR)    //再生成右子树
    {
        return ERROR;
    }

    return OK;
    /********** End **********/
}

//初始默认为NULL，防止野指针随机值
//递归终止条件为NULL，即递归到空子树时，返回OK