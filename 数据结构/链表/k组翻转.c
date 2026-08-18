status ReverseKGroup(LinkList &L, int k)
// 每k个节点为一组翻转，不足k个保持原序；返回OK；k<=1或表不存在返回ERROR/INFEASIBLE
{
    /********** Begin *********/
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    if(k <= 1)
    {
        return OK;
    }
    
    LinkList prevTail = L;  // 记录上一组的尾节点（初始为头结点）
    
    while(prevTail->next != NULL)
    {
        //检查剩余节点是否足够k个
        LinkList check = prevTail->next;
        int count = 0;
        while(check != NULL && count < k)
        {
            check = check->next;
            count++;
        }
        if(count < k) break;  //不足k个，保持原序，结束循环

        // 翻转当前k个节点
        LinkList curr = prevTail->next;
        LinkList nextTail = check;  // 下一组起点
        LinkList prev = nextTail;   // 翻转后的第一个节点应指向nextTail
        
        for(int i = 0; i < k; i++)
        {
            LinkList temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        // 连接上一组尾节点与当前组新头节点
        prevTail->next = prev;
        prevTail = curr;  // 更新prevTail为当前组的新尾节点
    }
    
    return OK;
    /********** End **********/
}