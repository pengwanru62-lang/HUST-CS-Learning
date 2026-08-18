void Save(BiTree T, FILE *fp)
{
    //递归实现储存
    //为空的时候加载到文件里面就是空
    if(T == NULL)
    {
        fprintf(fp, "0 null ");
        return;
    }

    //非空时候正常存入
    fprintf(fp, "%d %s ", T->data.key, T->data.others);

    //递归储存左右子树
    Save(T->lchild,fp);
    Save(T->rchild,fp);
}

status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    //注意需要保存树的结构，因此需要保存空的地方
    FILE *fp = fopen(FileName, "w");
    if(fp == NULL)
    {
        return ERROR;
    }

    Save(T, fp);

    fclose(fp);     //注意需要关闭文件
    return OK;
    /********** End 1 **********/
}

BiTree Build(FILE *fp)
{
    //先定义临时变量保存读取到的数据
    TElemType temp;
    //如果读取到的不足两个数据，那就是NULL
    if(fscanf(fp, "%d %s ",&temp.key, temp.others) != 2)
    {
        return NULL;
    }

    //key为0的时候也对应NULL
    if(temp.key == 0)
    {
        return NULL;
    }

    //创建新节点
    BiTree Node = (BiTree)malloc(sizeof(BiTNode));
    Node->data = temp;
        
    //递归读取左右子树
    Node->lchild = Build(fp);
    Node->rchild = Build(fp);

    //返回根
    return Node;

}

status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    FILE *fp = fopen(FileName, "r");
    if(fp == NULL)
    {
        return ERROR;
    }

    T = Build(fp);

    fclose(fp);
    return OK;
    /********** End 2 **********/
}
