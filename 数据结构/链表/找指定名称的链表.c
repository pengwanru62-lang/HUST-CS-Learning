int FindList(const char *name)
// 查找指定名称的链表，成功返回逻辑序号（从1开始），未找到返回0
{
    /********** Begin *********/
    // 遍历所有管理的链表
    for(int i = 0; i < Manager.count; i++)
    {
        // 比较名称是否匹配
        if(strcmp(Manager.lists[i].name, name) == 0)
        {
            return i + 1;  // 返回逻辑序号（从1开始）
        }
    }
    
    // 遍历完成未找到
    return 0;  // 未找到返回0
    /********** End **********/
}