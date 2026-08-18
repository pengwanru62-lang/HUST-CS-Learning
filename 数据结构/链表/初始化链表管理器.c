void InitManager()
// 初始化链表管理器，清空所有状态
{
    /********** Begin *********/
    // 重置管理器状态
    Manager.count = 0;                    // 链表数量置0
    Manager.currentIdx = -1;              // 当前索引置-1（未选择任何链表）
    
    // 初始化所有链表记录
    for(int i = 0; i < MAX_LISTS; i++)
    {
        Manager.lists[i].name[0] = '\0';  // 名称字符串置空
        Manager.lists[i].L = NULL;         // 链表指针置空(便于判断是否存在链表)
    }
    /********** End **********/
}