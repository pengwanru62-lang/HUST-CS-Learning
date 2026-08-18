status IsPalindrome(LinkList &L)
{
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //快慢指针找中点
    LinkList slow = L->next;
    LinkList fast = L->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //翻转后半部分链表
    LinkList secondHalf = slow->next;
    slow->next = NULL; //先断开前后半部分
    LinkList prev = NULL;
    LinkList curr = secondHalf;
    while(curr != NULL)
    {
        LinkList nextT = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextT;
    }

    //比较前后两半部分
    status isPalindrome = TRUE;
    LinkList p1 = L->next, p2 = prev;   //p1指向链表头，p2指向后半部分链表头.同时保留prev便于回复链表
    while(p2!=NULL)
    {
        if(p1->data != p2->data)
        {
            isPalindrome = FALSE;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    //恢复链表
    curr = prev;
    prev = NULL;
    while(curr != NULL)
    {
        LinkList nextT = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextT;
    }
    slow->next = prev;
    return isPalindrome ? TRUE : FALSE;
}