status RemoveList(const char *name)
// 移除指定名称的链表，释放资源；返回OK，未找到返回ERROR
{
    /********** Begin *********/
    // 第一步：查找目标链表的索引
    int idx = -1;  // -1表示未找到
    for(int i = 0; i < Manager.count; i++)
    {
        if(strcmp(Manager.lists[i].name, name) == 0)
        {
            idx = i;  // 找到目标，记录索引
            break;
        }
    }
    
    // 第二步：未找到目标链表
    if(idx == -1)
    {
        return ERROR;  // 移除失败
    }
    
    // 第三步：销毁链表，释放所有节点内存
    DestroyList(Manager.lists[idx].L);
    Manager.lists[idx].L = NULL;  // 指针置空，防止悬挂
    
    // 第四步：前移覆盖被删除的记录（保持数组连续）
    for(int i = idx; i < Manager.count - 1; i++)
    {
        Manager.lists[i] = Manager.lists[i + 1];
    }
    Manager.count--;  // 链表数量-1
    
    // 第五步：调整当前索引，避免悬空引用
    if(Manager.currentIdx == idx)
    {
        // 删除的是当前链表：切换到第一个或置为未选择
        Manager.currentIdx = (Manager.count > 0) ? 0 : -1;
    }
    else if(Manager.currentIdx > idx)
    {
        // 当前链表在被删除链表之后：索引前移
        Manager.currentIdx--;
    }
    
    return OK;  // 移除成功
    /********** End **********/
}