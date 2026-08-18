status AddList(const char *name)
// 添加新链表到管理器，自动切换到新链表；返回OK，名称重复或容量满返回ERROR，内存失败返回OVERFLOW
{
    /********** Begin *********/
    // 第一步：检查管理器容量是否已满
    if(Manager.count >= MAX_LISTS)
    {
        return ERROR;  // 容量已满，无法添加
    }
    
    // 第二步：检查名称是否已存在（保证名称唯一性）
    for(int i = 0; i < Manager.count; i++)
    {
        if(strcmp(Manager.lists[i].name, name) == 0)
        {
            return ERROR;  // 名称重复，添加失败
        }
    }
    
    // 第三步：在数组末尾添加新记录
    int idx = Manager.count;  // 新链表的索引
    
    // 复制名称到记录中
    strncpy(Manager.lists[idx].name, name, NAME_LEN - 1);
    Manager.lists[idx].name[NAME_LEN - 1] = '\0';  // 确保字符串结束
    
    // 初始化新链表（带头结点）
    if(InitList(Manager.lists[idx].L) != OK)
    {
        return OVERFLOW;  // 内存分配失败
    }
    
    // 第四步：更新管理器状态
    Manager.count++;                // 链表数量+1
    Manager.currentIdx = idx;       // 自动切换到新创建的链表
    
    return OK;  // 添加成功
    /********** End **********/
}