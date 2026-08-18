status SplitList(LinkList L, LinkList &Odd, LinkList &Even)
// 奇偶拆分线性表（按元素值奇偶性，不是位置）
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //初始化奇数链表和偶数链表（带头结点）
    if(Odd != NULL) DestroyList(Odd);
    if(Even != NULL) DestroyList(Even);
    
    Odd = (LinkList)malloc(sizeof(LNode));
    Even = (LinkList)malloc(sizeof(LNode));
    if(Odd == NULL || Even == NULL) return OVERFLOW;
    Odd->next = NULL;
    Even->next = NULL;

    LinkList p = L->next;      //原链表遍历指针
    LinkList oddTail = Odd;    //奇数链表尾指针
    LinkList evenTail = Even;  //偶数链表尾指针

    //遍历原链表，按元素值奇偶性拆分
    while(p != NULL)
    {
        LinkList q = p->next;  //保存下一个节点
        p->next = NULL;        //断开原连接

        if(p->data % 2 == 0)  //偶数
        {
            //尾插法插入偶数链表
            evenTail->next = p;
            evenTail = p;
        }
        else  //奇数
        {
            //尾插法插入奇数链表
            oddTail->next = p;
            oddTail = p;
        }
        p = q;  //继续处理下一个节点
    }

    return OK;
    /********** End **********/
}