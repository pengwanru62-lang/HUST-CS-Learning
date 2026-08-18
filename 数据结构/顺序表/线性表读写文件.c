status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //打开文件
    FILE *fp = fopen(FileName,"w");
    if(!fp)  //判断打开是否成功
    {
        return ERROR;
    }           

    //一次性将所有元素写入文件
    fwrite(L.elem, sizeof(ElemType), L.length, fp);

    //关闭文件
    fclose(fp);

    return OK;
    /********** End **********/
}

status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem != NULL)
    {
        return INFEASIBLE;
    }
    
    //打开文件
    FILE *fp = fopen(FileName, "r");
    if(!fp)
    {
        fclose(fp);
        return ERROR;
    }

    //线性表不存在时，初始化线性表
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(L.elem == NULL)
    {
        fclose(fp);
        return ERROR;
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    //一次性读入数据到线性表
    while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
    {
        //更新表长
        L.length++;
        //判断是否会溢出，如果会则重新分配空间
        if(L.length >= L.listsize)
        {
            ElemType *newelem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
            if(!newelem)
            {
                fclose(fp);
                return ERROR;
            }
            L.elem=newelem;
            L.listsize +=LISTINCREMENT;
        }
    }

    //关闭文件
    fclose(fp);
    return OK;
    /********** End **********/
}