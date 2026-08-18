//关键在在于LoadList函数需要创建头节点
//fprintf(fp,"%d ", p->data);需要加空格分隔元素方便之后的读取

status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //打开文件
    FILE *fp = fopen(FileName, "w");
    if(!fp) return ERROR;

    //跳过头节点，遍历链表
    LinkList p = L->next;

    //逐个写入文件
    while(p != NULL)
    {
        fprintf(fp,"%d ", p->data);
        p = p->next;
    }

    //关闭文件
    fclose(fp);

    return OK;
    /********** End 1 **********/
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    //判断线性表是否存在
    if(L != NULL)
    {
        return INFEASIBLE;
    }

    //打开文件
    FILE *fp = fopen(FileName, "r");
    if(!fp) return ERROR;

    //创建头节点
    L = (LinkList)malloc(sizeof(LNode));
    if(!L)
    {
        fclose(fp);
        return ERROR;
    }
    L->next = NULL;

    //尾部逐个插入
    LinkList tail = L;
    ElemType x;
    while(fscanf(fp, "%d", &x) != EOF)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if(!p)
        {
            fclose(fp);
            return ERROR;
        }
        p->data = x;
        tail->next = p;
        tail = p;
    }
    tail->next = NULL;

    //关闭文件
    fclose(fp);

    return OK;
    /********** End 2 **********/
}
