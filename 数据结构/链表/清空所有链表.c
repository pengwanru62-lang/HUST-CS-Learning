status ClearAllLists()
// 清空管理器中所有线性表的数据节点，保留头结点和表名；返回OK
{
    /********** Begin *********/
    // 遍历所有已管理的链表
    for(int i = 0; i < Manager.count; i++)
    {
        // 判断链表是否已初始化
        if(Manager.lists[i].L != NULL)
        {
            // 调用单表清空函数，释放数据节点但保留头结点
            ClearList(Manager.lists[i].L);
        }
    }
    return OK;
    /********** End **********/
}