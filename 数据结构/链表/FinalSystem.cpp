/* 单链表演示系统 - 数据结构实验2 */
/*作者：彭婉茹（U202514699）*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//状态码定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//数据元素类型定义
typedef int status;
typedef int ElemType;

//单链表（链式结构）结点的定义
typedef struct LNode{  
      ElemType data;
      struct LNode *next;
} LNode, *LinkList;

// 链表记录结构体
typedef struct {
    char name[30];    // 链表名称
    LinkList L;       // 指向对应单链表
} ListNode;

// 链表管理器（管理多个链表）
#define MAX_LISTS 10           
#define NAME_LEN 30
typedef struct {
    ListNode lists[MAX_LISTS]; // 链表记录数组
    int count;                  // 当前管理的链表数量
    int currentIdx;             // 当前操作链表的索引（-1表示未选择）
} ListManager;
ListManager Manager;

//基本函数声明
status InitList(LinkList &L);
status DestroyList(LinkList &L);
status ClearList(LinkList &L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType &e);
status LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L, ElemType e, ElemType &pre);
status NextElem(LinkList L, ElemType e, ElemType &next);
status ListInsert(LinkList &L, int i, ElemType e);
status ListDelete(LinkList &L, int i, ElemType &e);
status ListTraverse(LinkList L);

//附加功能函数声明
status reverseList(LinkList &L);
status RemoveNthFromEnd(LinkList &L, int n);
status sortList(LinkList &L);
status SaveList(LinkList L,char FileName[]);
status LoadList(LinkList &L,char FileName[]);
void InitManager(); 
status AddList(const char *name);
status RemoveList(const char *name); 
int FindList(const char *name); 

//自定义功能
status GetMax(LinkList L, ElemType &max);
status GetMin(LinkList L, ElemType &min);
status RemoveDuplicate(LinkList &L);
status DeleteVal(LinkList &L, ElemType e);
status SwapElem(LinkList &L, int i, int j);
status SplitList(LinkList L, LinkList &Odd, LinkList &Even);
status SwitchList(const char *name); 
void ShowAllLists(); 
status IsPalindrome(LinkList &L);
status PartitionList(LinkList &L, ElemType pivot);
status DeleteRange(LinkList &L, ElemType min, ElemType max);
status ReverseK(LinkList &L, int k);
status ClearAllLists();
status BatchInsert(LinkList &L, int pos, int n);

int main()
{
    // 初始化全局管理器
    InitManager();
    
    int op = 1;
    LinkList curL = NULL;

    // 首次运行打印菜单
    printf("  ==============================================\n");
    printf("  |  Linear Table On Linked Structure          |\n");
    printf("  |   Author: Peng Wanru (U202514699)          |\n");
    printf("  ==============================================\n");
    printf("  --- List Management ---\n");
    printf("  30.AddList    31.RemoveList  32.FindList\n");
    printf("  33.SwitchList 34.ShowAll     35.ClearAll\n");
    printf("  --- Basic Operations ---\n");
    printf("   1.InitList    2.DestroyList  3.ClearList\n");
    printf("   4.ListEmpty   5.ListLength   6.GetElem\n");
    printf("   7.LocateElem  8.PriorElem    9.NextElem\n");
    printf("  10.ListInsert 11.ListDelete  12.ListTraverse\n");
    printf("  36.BatchInsert\n");
    printf("  --- Algorithm & Custom ---\n");
    printf("  13.reverseList 14.RemoveNth  15.sortList\n");
    printf("  16.IsPalindrome 17.Partition\n");
    printf("  19.DeleteRange 20.ReverseK   21.GetMax\n");
    printf("  22.GetMin     23.RemoveDup  24.DeleteVal\n");
    printf("  25.SwapElem   26.SplitList\n");
    printf("  --- File Operations ---\n");
    printf("  27.SaveList   28.LoadList\n");
    printf("  --------------------------------------------\n");
    printf("   0.Exit\n\n");

    while (op)
    {
        if(Manager.currentIdx >= 0 && Manager.currentIdx < MAX_LISTS)
            curL = Manager.lists[Manager.currentIdx].L;
        else
            curL = NULL;

        printf("=> ");
        scanf("%d", &op);
        getchar();  // 吸收回车符

        /* 根据用户选择执行相应操作 */
        switch (op)
        {
            case 30: {  // 添加新链表
                char name[NAME_LEN];
                printf("  => Enter new list name: ");
                scanf("%s", name); getchar();
                if(AddList(name) == OK)
                    printf("  => List '%s' added & selected!\n", name);
                else
                    printf("  => Add failed! Name exists or full.\n");
                break;
            }

            case 31: {  // 移除链表
                char name[NAME_LEN];
                printf("  => Enter list name to remove: ");
                scanf("%s", name); getchar();
                if(RemoveList(name) == OK)
                    printf("  => List '%s' removed!\n", name);
                else
                    printf("  => Remove failed! Not found.\n");
                break;
            }

            case 32: {  // 查找链表
                char name[NAME_LEN];
                printf("  => Enter list name to find: ");
                scanf("%s", name); getchar();
                int pos = FindList(name);
                if(pos > 0)
                    printf("  => Found at position: %d\n", pos);
                else
                    printf("  => Not found!\n");
                break;
            }

            case 33: {  // 切换链表
                char name[NAME_LEN];
                printf("  => Enter list name to switch: ");
                scanf("%s", name); getchar();
                if(SwitchList(name) == OK)
                    printf("  => Switched to '%s'!\n", name);
                else
                    printf("  => Switch failed! Not found.\n");
                break;
            }

            case 34:  // 显示所有链表
                ShowAllLists();
                break;

            case 35: {  // 清空所有链表
                printf("  => Clear ALL lists? (y/n): ");
                char confirm;
                scanf(" %c", &confirm); getchar();
                if(confirm == 'y' || confirm == 'Y')
                {
                    if(ClearAllLists() == OK)
                        printf("  => All lists cleared!\n");
                    else
                        printf("  => Clear failed!\n");
                }
                else
                    printf("  => Cancelled.\n");
                break;
            }

            case 1:  // 初始化当前链表
                if(curL == NULL) {
                    printf("  => No list selected. Auto-creating 'List_1'...\n");
                    AddList("List_1");
                    curL = Manager.lists[Manager.currentIdx].L;
                }
                if(curL != NULL) {
                    DestroyList(curL);
                    Manager.lists[Manager.currentIdx].L = NULL;
                    if(InitList(Manager.lists[Manager.currentIdx].L) == OK)
                        printf("  => Current list initialized!\n");
                    else
                        printf("  => Init failed!\n");
                }
                 break;

            case 2:  // 销毁当前链表
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                if(Manager.currentIdx >= 0 && DestroyList(Manager.lists[Manager.currentIdx].L) == OK) {
                    printf("  => Current list destroyed!\n");
                    Manager.lists[Manager.currentIdx].L = NULL;
                    Manager.currentIdx = -1;
                } else
                    printf("  => Destroy failed!\n");
                 break;

            case 3:  // 清空当前链表
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                if(ClearList(curL) == OK)
                    printf("  => Current list cleared!\n");
                else
                    printf("  => Clear failed!\n");
                 break;

            case 4:  // 判空
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                if(ListEmpty(curL) == TRUE)
                    printf("  => Current list is empty.\n");
                else if(ListEmpty(curL) == FALSE)
                    printf("  => Current list is not empty.\n");
                else
                    printf("  => Error: List not initialized!\n");
                 break;

            case 5:  // 求表长
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                printf("  => Length: %d\n", ListLength(curL));
                 break;

            case 6: {  // 获得元素
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                int i; ElemType e;
                printf("  => Enter position i: "); scanf("%d", &i); getchar();
                if(GetElem(curL, i, e) == OK)
                    printf("  => Element at %d: %d\n", i, e);
                else
                    printf("  => Failed! Invalid position.\n");
                 break;
            }

            case 7: {  // 查找元素
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                ElemType e1;
                printf("  => Enter value to search: "); scanf("%d", &e1); getchar();
                int pos = LocateElem(curL, e1);
                if(pos > 0)
                    printf("  => Found at position: %d\n", pos);
                else
                    printf("  => Not found!\n");
                 break;
            }

            case 8: {  // 获得前驱
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                ElemType e2, pre;
                printf("  => Enter element: "); scanf("%d", &e2); getchar();
                if(PriorElem(curL, e2, pre) == OK)
                    printf("  => Predecessor: %d\n", pre);
                else
                    printf("  => Failed! First or not found.\n");
                 break;
            }

            case 9: {  // 获得后继
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                ElemType e3, next;
                printf("  => Enter element: "); scanf("%d", &e3); getchar();
                if(NextElem(curL, e3, next) == OK)
                    printf("  => Successor: %d\n", next);
                else
                    printf("  => Failed! Last or not found.\n");
                 break;
            }

            case 10: {  // 插入元素
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                int pos; ElemType val;
                printf("  => Position (1~%d): ", ListLength(curL)+1);
                scanf("%d", &pos); getchar();
                printf("  => Value: "); scanf("%d", &val); getchar();
                if(ListInsert(curL, pos, val) == OK)
                    printf("  => Inserted!\n");
                else
                    printf("  => Insert failed!\n");
                 break;
            }

            case 11: {  // 删除元素
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                int pos; ElemType val;
                printf("  => Position (1~%d): ", ListLength(curL));
                scanf("%d", &pos); getchar();
                if(ListDelete(curL, pos, val) == OK)
                    printf("  => Deleted value: %d\n", val);
                else
                    printf("  => Delete failed!\n");
                 break;
            }

            case 12:  // 遍历链表
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                printf("  => Current list: ");
                if(ListTraverse(curL) != OK) printf("(empty)");
                printf("\n");  break;

            case 36: {  // 批量插入元素
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                int pos, n;
                printf("  => Enter insert position (1~%d): ", ListLength(curL) + 1);
                scanf("%d", &pos); getchar();
                printf("  => Enter number of elements: ");
                scanf("%d", &n); getchar();
                
                if(n <= 0) {
                    printf("  => Invalid count! Must be > 0.\n");
                } else if(BatchInsert(curL, pos, n) == OK) {
                    printf("  => Batch insert successful! Result: ");
                    ListTraverse(curL); printf("\n");
                } else {
                    printf("  => Batch insert failed! Invalid position.\n");
                }
                break;
            }

            case 13:  // 逆置链表
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                if(reverseList(curL) == OK) {
                    printf("  => Reversed! Result: ");
                    ListTraverse(curL); printf("\n");
                } else printf("  => Reverse failed!\n");
                 break;

            case 14: {  // 删除倒数第n个
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                int n;
                printf("  => Enter n (1~%d): ", ListLength(curL));
                scanf("%d", &n); getchar();
                if(RemoveNthFromEnd(curL, n) == OK) {
                    printf("  => Deleted! Result: ");
                    ListTraverse(curL); printf("\n");
                } else printf("  => Failed!\n");
                 break;
            }

            case 15:  // 排序链表
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                if(sortList(curL) == OK) {
                    printf("  => Sorted! Result: ");
                    ListTraverse(curL); printf("\n");
                } else printf("  => Sort failed!\n");
                 break;

            case 16:  // 判断回文
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                if(IsPalindrome(curL) == TRUE)
                    printf("  => YES, palindrome!\n");
                else
                    printf("  => NO, not palindrome.\n");
                 break;

            case 17: {  // 分区链表
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                ElemType pivot;
                printf("  => Enter pivot value: "); scanf("%d", &pivot); getchar();
                if(PartitionList(curL, pivot) == OK) {
                    printf("  => Partitioned! Result: ");
                    ListTraverse(curL); printf("\n");
                } else printf("  => Failed!\n");
                 break;
            }

            case 19: {  // 删除区间节点【修复版】
                if(curL == NULL) { printf("  => Error: No list selected!\n");  break; }
                ElemType min, max;
                printf("  => Enter min max: ");
                scanf("%d %d", &min, &max);
                // 彻底清空输入缓冲区（防卡屏）
                while(getchar() != '\n' && !feof(stdin));

                if(DeleteRange(curL, min, max) == OK) {
                    printf("  => Deleted! Result: ");
                    ListTraverse(curL); printf("\n");
                } else {
                    printf("  => Failed!\n");
                }
                 break;
            }

            case 20: {  // K组翻转【修复版】
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                int k;
                printf("  => Enter k: "); scanf("%d", &k); getchar();
                if(ReverseK(curL, k) == OK) {
                    printf("  => Reversed! Result: ");
                    ListTraverse(curL); printf("\n");
                } else printf("  => Failed!\n");
                 break;
            }

            case 21: {  // 最大值
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                ElemType max;
                if(GetMax(curL, max) == OK)
                    printf("  => Max: %d\n", max);
                else
                    printf("  => Failed!\n");
                 break;
            }

            case 22: {  // 最小值
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                ElemType min;
                if(GetMin(curL, min) == OK)
                    printf("  => Min: %d\n", min);
                else
                    printf("  => Failed!\n");
                 break;
            }

            case 23:  // 去重（要求先排序）
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                if(ListEmpty(curL) == TRUE || ListLength(curL) <= 1) {
                    printf("  => Empty or single list, no duplicates to remove.\n");
                } else {
                    if(RemoveDuplicate(curL) == OK) {
                        printf("  => Duplicates removed! Result: ");
                        ListTraverse(curL); printf("\n");
                    } else {
                        printf("  => Failed!\n");
                    }
                }
                 break;

            case 24: {  // 删除指定值
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                ElemType val;
                printf("  => Enter value: "); scanf("%d", &val); getchar();
                if(DeleteVal(curL, val) == OK) {
                    printf("  => Deleted! Result: ");
                    ListTraverse(curL); printf("\n");
                } else printf("  => Failed!\n");
                 break;
            }

            case 25: {  // 交换元素
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                int i, j;
                printf("  => Enter i j: "); scanf("%d %d", &i, &j); getchar();
                if(SwapElem(curL, i, j) == OK)
                    printf("  => Swapped!\n");
                else
                    printf("  => Failed!\n");
                 break;
            }

            case 26: {  // 奇偶拆分
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                LinkList Odd = NULL, Even = NULL;
                if(SplitList(curL, Odd, Even) == OK) {
                    printf("  => Odd: "); ListTraverse(Odd); printf("\n");
                    printf("  => Even: "); ListTraverse(Even); printf("\n");
                    DestroyList(Odd); DestroyList(Even);
                } else printf("  => Split failed!\n");
                 break;
            }

            case 27: {  // 保存到文件
                if(curL == NULL) { printf("  => Error: No list selected! Use 30.AddList first.\n");  break; }
                char fileName[50];
                printf("  => Enter filename: "); scanf("%s", fileName); getchar();
                if(SaveList(curL, fileName) == OK)
                    printf("  => Saved to %s\n", fileName);
                else
                    printf("  => Save failed!\n");
                 break;
            }

            case 28: {  // 从文件加载
                if(Manager.currentIdx < 0 || Manager.currentIdx >= MAX_LISTS) {
                    printf("  => Error: No list selected! Use 30.AddList first.\n");
                     break;
                }
                char fileName[50];
                printf("  => Enter filename: ");
                scanf("%s", fileName);
                // 彻底清空输入缓冲区
                while(getchar() != '\n' && !feof(stdin));

                DestroyList(Manager.lists[Manager.currentIdx].L);

                // 直接传入管理器中的真实引用，确保加载后指针正确绑定
                if(LoadList(Manager.lists[Manager.currentIdx].L, fileName) == OK) {
                    printf("  => Loaded! Result: ");
                    ListTraverse(Manager.lists[Manager.currentIdx].L); printf("\n");
                } else {
                    printf("  => Load failed! (Check if file exists in current dir)\n");
                    // 加载失败时重建空表，防止后续操作崩溃
                    Manager.lists[Manager.currentIdx].L = NULL;
                    InitList(Manager.lists[Manager.currentIdx].L);
                }
                break;
            }

            case 0:  // 退出系统
                printf("\n");
                for(int i=0; i<Manager.count; i++)
                    DestroyList(Manager.lists[i].L);
                printf("   Thank you for using Linked List System!\n");
                printf("   Author: Peng Wanru (U202514699)\n");
                printf("\n");
                break;

            default:
                printf("  => Invalid input! Please enter 0-36.\n");
                 break;
        }/* end of switch */
    }/* end of while */

    return 0;
}/* end of main */


status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L != NULL)
    {
        return INFEASIBLE;  //如果线性表存在，不能初始化
    }

    //若线性表不存在则构造一个空的线性表
    L = (LinkList)malloc(sizeof(LNode));
    if(!L) return ERROR;
    L->next = NULL;

    return OK;

    /********** End **********/
}

status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    // 链表不存在
    if (L == NULL) {
        return INFEASIBLE;
    }

    LinkList p = L;
    // 循环释放所有结点
    while (p != NULL) {
        LinkList temp = p->next;  // 先保存下一个
        free(p);      // 释放当前
        p = temp;
    }
    
    //销毁后链表置空
    L = NULL;  
    return OK;
    /********** End **********/
}

status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历清空线性表
    LinkList p = L->next;
    while(p != NULL)
    {
        LinkList temp = p->next;   //保存下一个节点
        free(p);                   //释放当前节点
        p = temp;
    }

    //保存头节点但是头节点next为空
    L->next = NULL;

    return OK;
    /********** End **********/
}

status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断线性表是否为空
    return (L->next == NULL) ? TRUE : FALSE;
    /********** End **********/
}

int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历线性表求表长
    LinkList p = L->next;
    int cnt = 0;
    while(p != NULL)
    {
        cnt++;
        p = p->next;
    }

    return cnt;
    /********** End **********/
}

status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断i的位置是否合法
    if(i<1) return ERROR;

    //遍历链表匹配是否存在目标元素
    int cnt=1;
    LinkList p = L->next;
    while(p != NULL && cnt < i)
    {
        p = p->next;
        cnt++;
    }

    if(p != NULL) //成功找到元素
    {
        e = p->data;
        return OK;
    }

    return ERROR;   //i的值超过表长

    /********** End **********/
}

status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历线性表查找是否存在目标元素
    LinkList p = L->next;
    int i=1;    //元素逻辑序号
    while(p != NULL)
    {
        if(p->data == e) return i;
        i++;
        p = p->next;
    }

    return ERROR; 

    /********** End **********/
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历查找元素e的前驱
    LinkList p = L->next;
    LinkList pr = L;    //前驱指针
    while(p != NULL)
    {
        if(p->data == e)
        {
            //第一个元素没有前驱
            if(p == L->next) return ERROR;
            //其余元素存在前驱
            pre = pr->data;
            return OK;
        }
        //指针后移
        pr = p; 
        p = p->next;
    }

    return ERROR; //遍历完成没有匹配成功
    /********** End **********/
}

status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历线性表匹配e并获取后继
    LinkList p = L->next;
    while(p != NULL)  
    {
        if(e == p->data)
        {
            if(p->next == NULL) return ERROR;  //最后一个元素没有后继
            next = p->next->data;
            return OK;
        }
        p = p->next;
    }

    return ERROR;  //查找失败
    /********** End **********/
}

status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断i的位置是否合法
    if(i < 1) return ERROR;

    //遍历线性表定位第i个元素
    int cnt = 1;
    LinkList p = L->next;
    LinkList pr = L;
    while(p != NULL && cnt++ < i)
    {
        pr = p;
        p = p->next;
    }

    if(p == NULL && cnt != i) return ERROR; //i的位置非法 
    
    //在第i个元素前插入目标元素
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    pr->next = q;
    q->next = p;

    return OK;
    /********** End **********/
}

status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断删除位置i是否合法
    if(i < 1) return ERROR;

    //遍历定位目标删除位置
    LinkList p = L->next;
    LinkList pre = L;
    int cnt = 1;
    while(p != NULL && cnt++ < i)
    {
        pre = p;
        p = p->next;
    }

    //判断i的位置是否合法
    if(p == NULL) return ERROR;

    //保存删除的值
    e = p->data;
    
    //释放并改变链表连接
    pre->next = p->next;
    free(p);

    return OK;
    /********** End **********/
}

status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //遍历输出线性表的每一个元素
    LinkList p = L->next;
    while(p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
        if(p != NULL) printf(" ");
    }

    return OK;
    /********** End **********/
}

status reverseList(LinkList &L)
{
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //采用头插法逆置链表
    LinkList p = L->next;   ///从第二个节点开始遍历,p指向需要头插的元素
    L->next = NULL;

    while(p)
    {
        LinkList q = p->next;   //先保存下一个节点
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return OK;
}

status RemoveNthFromEnd(LinkList &L,int n)
{
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //利用已有函数获取长度
    int len = ListLength(L);

    //判断n是否合法
    if(n < 1 || n > len)
    {
        return INFEASIBLE;
    }

    ElemType e;
    //利用已有函数删除倒数第n个节点
    ListDelete(L,len-n+1,e);
    return OK;
}

status sortList(LinkList &L)
{
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }
    
    //只有一个元素的时候不用排序
    if(ListLength(L) <= 1)
    {
        return OK;
    }

    //利用冒泡排序
    for(int i=0; i<ListLength(L)-1; i++)
    {
        ElemType flag = 0;  //记录是否有交换
        LinkList p = L->next;
        for(int j=0; j<ListLength(L)-1-i; j++)
        {
            if(p->data > p->next->data)
            {
                flag = 1;
                ElemType temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
        if(!flag) break;
    }
    return OK;
}

status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //打开文件
    FILE *fp = fopen(FileName, "w");
    if(!fp) return ERROR;

    //跳过头节点，遍历链表
    LinkList p = L->next;

    //逐个写入文件
    while(p != NULL)
    {
        fprintf(fp,"%d ", p->data);
        p = p->next;
    }

    //关闭文件
    fclose(fp);

    return OK;
    /********** End 1 **********/
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    //判断线性表是否存在
    if(L != NULL)
    {
        return INFEASIBLE;
    }

    //打开文件
    FILE *fp = fopen(FileName, "r");
    if(!fp) return ERROR;

    //创建头节点
    L = (LinkList)malloc(sizeof(LNode));
    if(!L)
    {
        fclose(fp);
        return ERROR;
    }
    L->next = NULL;

    //尾部逐个插入
    LinkList tail = L;
    ElemType x;
    while(fscanf(fp, "%d", &x) != EOF)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if(!p)
        {
            fclose(fp);
            return ERROR;
        }
        p->data = x;
        tail->next = p;
        tail = p;
    }
    tail->next = NULL;

    //关闭文件
    fclose(fp);

    return OK;
    /********** End 2 **********/
}

status GetMax(LinkList L, ElemType &max)
// 查找链表中的最大值
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //空表无法获取最大值
    if(L->next == NULL) return ERROR;

    //遍历链表查找最大值
    LinkList p = L->next;
    max = p->data;
    p = p->next;
    while(p != NULL)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }

    return OK;
    /********** End **********/
}

status GetMin(LinkList L, ElemType &min)
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //空表无法获取最小值
    if(L->next == NULL) return ERROR;

    //遍历链表查找最小值
    LinkList p = L->next;
    min = p->data;
    p = p->next;
    while(p != NULL)
    {
        if(p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }

    return OK;
    /********** End **********/
}

status RemoveDuplicate(LinkList &L)
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //空表或单元素表无需去重
    if(L->next == NULL || L->next->next == NULL) return OK;

    //排序
    sortList(L);
    //遍历链表，删除重复元素
    LinkList p = L->next;  //p指向当前比较节点
    while(p != NULL && p->next != NULL)
    {
        if(p->data == p->next->data)
        {
            //删除重复节点
            LinkList q = p->next;
            p->next = q->next;
            free(q);
            //p不动，继续比较新的p->next
        }
        else
        {
            p = p->next;  //移动到下一个不同值的节点
        }
    }
    return OK;
    /********** End **********/
}

status DeleteVal(LinkList &L, ElemType e)
// 删除链表中所有值为e的节点
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //使用双指针法删除所有值为e的节点
    LinkList p = L->next;      //当前节点
    LinkList pre = L;          //前驱节点（初始为头结点）
    
    while(p != NULL)
    {
        if(p->data == e)
        {
            //删除当前节点
            LinkList q = p;
            pre->next = p->next;
            p = p->next;
            free(q);
            //pre不动，继续检查新的p
        }
        else
        {
            //两个指针同时后移
            pre = p;
            p = p->next;
        }
    }

    return OK;
    /********** End **********/
}

status SwapElem(LinkList &L, int i, int j)
// 交换链表中第i个和第j个位置元素的值（不交换节点指针）
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //判断位置是否合法
    if(i < 1 || j < 1) return ERROR;

    //定位第i个节点
    LinkList p = L->next;
    int cnt = 1;
    while(p != NULL && cnt < i)
    {
        p = p->next;
        cnt++;
    }
    if(p == NULL) return ERROR;  //i超出表长

    //定位第j个节点
    LinkList q = L->next;
    cnt = 1;
    while(q != NULL && cnt < j)
    {
        q = q->next;
        cnt++;
    }
    if(q == NULL) return ERROR;  //j超出表长

    //交换两个节点的数据域（不交换节点本身）
    ElemType temp = p->data;
    p->data = q->data;
    q->data = temp;

    return OK;
    /********** End **********/
}

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

status PartitionList(LinkList &L, ElemType pivot)
{
    //判断线性表是否存在
    if(L == NULL)
    {
        return INFEASIBLE;
    }

    //创建两个虚拟的头节点收集大于和小于pivot的情况
    LinkList lessL = (LinkList)malloc(sizeof(LNode));
    LinkList biggerL = (LinkList)malloc(sizeof(LNode));
    if(!lessL || !biggerL) return OVERFLOW;
    lessL->next = NULL;
    biggerL->next = NULL;
    LinkList P = lessL;

    //遍历原链表分区
    LinkList p = L->next;
    while(p)
    {
        LinkList nextT = p->next;
        p->next = NULL; //断开原来的链接
        if(p->data < pivot)
        {
            lessL->next = p;
            lessL = p;
        }
        else
        {
            biggerL->next = p;
            biggerL = p;
        }
        p = nextT;
    }

    //合并两个链表
    lessL->next = biggerL->next;
    biggerL->next = NULL;   //封口
    L->next = P->next;

    free(P); free(biggerL);
    return OK;
}

status DeleteRange(LinkList &L, ElemType min, ElemType max)
// 删除所有值在 [min, max] 范围内的节点；返回OK；表不存在返回INFEASIBLE
{
    /********** Begin *********/
    // 修复：增加空表保护，避免访问 L->next 时崩溃
    if(L == NULL) return INFEASIBLE;
    if(L->next == NULL) return OK;
    
    // 兼容用户输入 min > max 的情况
    if(min > max) { ElemType t = min; min = max; max = t; }

    LinkList prev = L;          // 前驱节点（初始为头结点）
    LinkList curr = L->next;    // 当前节点

    while(curr != NULL)
    {
        if(curr->data >= min && curr->data <= max)
        {
            // 匹配到待删除节点
            LinkList temp = curr;
            prev->next = curr->next;  // 跳过当前节点
            curr = prev->next;        // curr 指向下一个待检查节点
            free(temp);               // 释放内存
            // prev 不动，继续检查新的 curr
        }
        else
        {
            // 不匹配，两个指针同步后移
            prev = curr;
            curr = curr->next;
        }
    }
    return OK;
    /********** End **********/
}

status ReverseK(LinkList &L, int k)
// 每k个节点为一组翻转，不足k个保持原序；返回OK；k<=1或表不存在返回ERROR/INFEASIBLE
{
    /********** Begin *********/
    // 修复：增加空表保护
    if(L == NULL) return INFEASIBLE;
    if(k <= 1) return OK;
    
    LinkList prevTail = L;  // 记录上一组的尾节点（初始为头结点）
    
    while(prevTail->next != NULL)
    {
        // 检查剩余节点是否足够k个
        LinkList check = prevTail->next;
        int count = 0;  // 修复：删除乱码，正确声明 count
        while(check != NULL && count < k) { 
            check = check->next; 
            count++; 
        }
        if(count < k) break;  // 不足k个，保持原序，结束循环

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

status ClearAllLists()
// 清空管理器中所有线性表的数据节点，保留头结点和表名；返回OK
{
    /********** Begin *********/
    for(int i = 0; i < Manager.count; i++)
    {
        if(Manager.lists[i].L != NULL)
            ClearList(Manager.lists[i].L);
    }
    return OK;
    /********** End **********/
}

status BatchInsert(LinkList &L, int pos, int n)
// 在位置pos处批量插入n个元素，返回OK；位置不合法或n<=0返回ERROR；表不存在返回INFEASIBLE
{
    /********** Begin *********/
    if(L == NULL) return INFEASIBLE;
    int len = ListLength(L);
    if(pos < 1 || pos > len + 1) return ERROR;
    if(n <= 0) return ERROR;

    LinkList p = L;
    for(int i = 1; i < pos; i++) p = p->next;

    LinkList tail = p;
    ElemType val;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        LinkList newNode = (LinkList)malloc(sizeof(LNode));
        if(!newNode) return OVERFLOW;
        newNode->data = val;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    while(getchar() != '\n' && !feof(stdin));
    return OK;
    /********** End **********/
}