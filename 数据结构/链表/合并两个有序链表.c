// 辅助函数：合并两个带头结点的有序链表
LinkList LinkList MergeTwo(LinkList &L1, LinkList &L2)
{
    LinkList d = (LinkList)malloc(sizeof(LNode));
    LinkList tail = d;
    LinkList p1 = L1->next, p2 = L2->next;
    while(p1 && p2)
    {
        if(p1->data <= p2->data) 
        {
            tail->next = p1;
            p1 = p1->next; 
        }
        else 
        { 
            tail->next = p2; 
            p2 = p2->next; 
        }
        tail = tail->next;
    }
    tail->next = (p1) ? p1 : p2;    //合并剩余部分
    return d;
}
