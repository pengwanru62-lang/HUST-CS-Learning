status SwitchList(const char *name)
// 切换到指定名称的链表作为当前操作链表；返回OK，未找到返回ERROR
{
    /********** Begin *********/
    // 遍历查找目标链表
    for(int i = 0; i < Manager.count; i++)
    {
        if(strcmp(Manager.lists[i].name, name) == 0)
        {
            Manager.currentIdx = i;  // 更新当前索引
            return OK;  // 切换成功
        }
    }
    
    // 未找到目标链表
    return ERROR;  // 切换失败
    /********** End **********/
}