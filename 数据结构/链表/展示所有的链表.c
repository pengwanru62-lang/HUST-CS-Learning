void ShowAllLists()
// 显示所有管理的链表信息（名称、长度、当前标记）
{
    /********** Begin *********/
    // 情况1：没有管理的链表
    if(Manager.count == 0)
    {
        printf("  => No lists managed.\n");
        return;
    }
    
    // 情况2：显示表头信息
    printf("  => Managed Lists (%d/%d):\n", Manager.count, MAX_LISTS);
    
    // 逐个显示每个链表的信息
    for(int i = 0; i < Manager.count; i++)
    {
        // 当前操作的链表标记为*
        char mark = (i == Manager.currentIdx) ? '*' : ' ';
        
        // 获取链表长度
        int len = ListLength(Manager.lists[i].L);
        
        // 格式化输出：[标记] 名称 (长度)
        printf("     [%c] %s (Length: %d)\n", mark, Manager.lists[i].name, len);
    }
    /********** End **********/
}
