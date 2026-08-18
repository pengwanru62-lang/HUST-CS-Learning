status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //插入前需要判断线性表的集合是否已满
    if(Lists.length >= 10)
    {
        return ERROR;
    }

    //利用第一关的函数初始化一个空的线性表
    Lists.elem[Lists.length].L.elem = NULL;     //这里需要先初始化指针为NULL，防止随机值没有办法使用InitList函数
    InitList(Lists.elem[Lists.length].L);

    //将线性表名称添加到集合中
    int i = 0;
    while (ListName[i] != '\0')
    {
        Lists.elem[Lists.length].name[i] = ListName[i];
        i++;
    }
    Lists.elem[Lists.length].name[i] = '\0'; 

    //更新表长
    Lists.length++;

    return OK;

    /********** End **********/
}
