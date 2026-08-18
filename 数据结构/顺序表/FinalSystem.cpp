/* 顺序表演示系统 - 数据结构实验1 */
/*作者：彭婉茹（U202514699）*/

#include <stdio.h>
#include <stdlib.h>

// 状态码定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//数据元素类型定义
typedef int status;
typedef int ElemType;

//线性表（顺序结构）的定义
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;
//线性表的集合类型定义
typedef struct{  //线性表的集合类型定义
     struct { char name[30];
               SqList L;    
     } elem[10];
     int length;
}LISTS;
LISTS Lists;

//函数声明
status InitList(SqList &L);
status DestroyList(SqList &L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
status ListLength(SqList L);
status GetElem(SqList L, int i, ElemType &e);
int LocateElem(SqList L, ElemType e);
status PriorElem(SqList L, ElemType e, ElemType &pre);
status NextElem(SqList L, ElemType e, ElemType &next);
status ListInsert(SqList &L, int i, ElemType e);
status ListDelete(SqList &L, int i, ElemType &e);
status ListTraverse(SqList L);

//附加功能函数声明
status MaxSubArray(SqList& L, int& maxSum);
status SubArrayNum(SqList& L, int &k, int &cnt);
status sortList(SqList& L);
status SaveList(SqList L, char FileName[]);
status LoadList(SqList &L, char FileName[]);
status AddList(LISTS &Lists,char ListName[]);
status RemoveList(LISTS &Lists,char ListName[]);
int LocateList(LISTS Lists,char ListName[]);

//自定义功能函数说明
status ReverseList(SqList &L); // 翻转线性表
status RemoveDuplicate(SqList &L); // 去重
status GetMax(SqList L, ElemType &max); // 最大值
status GetMin(SqList L, ElemType &min); // 最小值
status DeleteVal(SqList &L, ElemType e); // 删除所有指定值
status SplitList(SqList L, SqList &Odd, SqList &Even); // 奇偶拆分线性表
status BatchInsert(SqList &L, int pos, ElemType arr[], int n); // 在位置pos处批量插入元素
status BatchDelete(SqList &L, int pos, int n); // 从位置pos处批量删除n个元素
status MergeList(SqList L1, SqList L2, SqList &merged); // 合并两个线性表
status TwoSum(SqList L, int target, int &idx1, int &idx2); // 在有序线性表中找到两个数使得它们的和为target，返回它们的下标
status SwapElem(SqList &L, int i, int j);          // 交换元素
status RotateList(SqList &L, int k);               // 循环移位
//集合管理辅助函数声明
status SaveCurrentToList(SqList L, LISTS &Lists, char ListName[]); // 保存当前表到集合
status LoadListToCurrent(LISTS Lists, char ListName[], SqList &L); // 从集合加载表到当前

int main()
{
    SqList L;
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;

    int op = 1;

    // 首次运行打印菜单
    printf("  ==============================================\n");
    printf("  |  Linear Table On Sequence Structure        |\n");
    printf("  |  Author: Peng Wanru (U202514699)           |\n");
    printf("  ==============================================\n");
    printf("  --- Basic Operations ---\n");
    printf("   1.InitList    2.DestroyList  3.ClearList\n");
    printf("   4.ListEmpty   5.ListLength   6.GetElem\n");
    printf("   7.LocateElem  8.PriorElem    9.NextElem\n");
    printf("  10.ListInsert 11.ListDelete  12.ListTraverse\n");
    printf("  --- Algorithm Functions ---\n");
    printf("  13.MaxSubArray 14.SubArrayNum 15.sortList\n");
    printf("  24.TwoSum      25.MergeList   33.SwapElem\n");
    printf("  --- Custom Functions ---\n");
    printf("  21.ReverseList 22.RemoveDup   23.GetMax\n");
    printf("  26.GetMin      27.DeleteVal   28.SplitList\n");
    printf("  --- Batch & File ---\n");
    printf("  29.BatchInsert 30.BatchDelete\n");
    printf("  16.SaveList    17.LoadList    34.RotateList\n");
    printf("  --- List Collection ---\n");
    printf("  18.AddList     19.RemoveList  20.LocateList\n");
    printf("  31.SaveCurrentToList  32.LoadListToCurrent\n");
    printf("  --------------------------------------------\n");
    printf("   0.Exit\n\n");

    while (op)
    {
        printf("=> ");
        scanf("%d", &op);
        getchar();  // 吸收回车符

        /* 根据用户选择执行相应操作 */
        switch (op)
        {
            case 1: {  // 初始化线性表
                if (L.elem != NULL) {
                    printf("  => Linear table already exists! Destroy first? (y/n): ");
                    char c; scanf(" %c", &c); getchar();
                    if(c == 'y' || c == 'Y') {
                        DestroyList(L);
                        if (InitList(L) == OK)
                            printf("  => Linear table created successfully!\n");
                        else
                            printf("  => Failed to create linear table!\n");
                    } else {
                        printf("  => Failed to create linear table!\n");
                    }
                } else {
                    if (InitList(L) == OK)
                        printf("  => Linear table created successfully!\n");
                    else
                        printf("  => Failed to create linear table!\n");
                }
                break;
            }

            case 2:  // 销毁线性表
                if (DestroyList(L) == OK)
                    printf("Linear table destroyed!\n");
                else
                    printf("Failed to destroy!\n");
                break;

            case 3:  // 清空线性表
                if (ClearList(L) == OK)
                    printf("Linear table cleared!\n");
                else
                    printf("Failed to clear!\n");
                break;

            case 4:  // 判定空表
                if (ListEmpty(L) == TRUE)
                    printf("The linear table is empty.\n");
                else if (ListEmpty(L) == FALSE)
                    printf("The linear table is not empty.\n");
                else
                    printf("Error: Linear table does not exist!\n");
                break;

            case 5:  // 求表长
                printf("  => Length of linear table: %d\n", ListLength(L));
                break;

            case 6: {  // 获得元素
                int i; ElemType e;
                printf("  => Enter position i to get element: ");
                scanf("%d", &i); getchar();
                if (GetElem(L, i, e) == OK)    
                    printf("  => Element at position %d: %d\n", i, e);
                else
                    printf("Failed! Invalid position!\n");
                break;
            }

            case 7: {  // 查找元素
                ElemType e1;
                printf("  => Enter element value to search: ");
                scanf("%d", &e1); getchar();
                int pos = LocateElem(L, e1);
                if (pos > 0)
                    printf("  => Element %d found at position: %d\n", e1, pos);
                else if (pos == 0)
                    printf("Element not found!\n");
                else
                    printf("Search failed: Table doesn't exist!\n");
                break;
            }

            case 8: {  // 获得前驱
                ElemType e2, pre;
                printf("  => Enter element to find predecessor: ");
                scanf("%d", &e2); getchar();
                if (PriorElem(L, e2, pre) == OK)
                    printf("  => Predecessor of %d is: %d\n", e2, pre);
                else
                    printf("Failed! Element is first or not found!\n");
                break;
            }

            case 9: {  // 获得后继
                ElemType e3, next;
                printf("  => Enter element to find successor: ");
                scanf("%d", &e3); getchar();
                if (NextElem(L, e3, next) == OK)
                    printf("  => Successor of %d is: %d\n", e3, next);
                else
                    printf("Failed! Element is last or not found!\n");
                break;
            }

            case 10: {  // 插入元素
                int insert_pos; ElemType insert_e;
                printf("  => Enter insert position (1~%d): ", ListLength(L) + 1);
                scanf("%d", &insert_pos); getchar();
                printf("  => Enter element value to insert: ");
                scanf("%d", &insert_e); getchar();
                if (ListInsert(L, insert_pos, insert_e) == OK)
                    printf("Insert successful!\n");
                else
                    printf("Insert failed! Invalid position!\n");
                break;
            }

            case 11: {  // 删除元素
                int del_pos; ElemType del_e;
                printf("  => Enter position to delete (1~%d): ", ListLength(L));
                scanf("%d", &del_pos); getchar();
                if (ListDelete(L, del_pos, del_e) == OK)
                    printf("  => Deleted! Value: %d\n", del_e);
                else
                    printf("Delete failed! Invalid position!\n");
                break;
            }

            case 12:  // 遍历线性表
                printf("  => Current list: ");
                if (ListTraverse(L) != OK) 
                    printf("(empty)");
                printf("\n");
                break;

            case 13: {  // 最大连续子数组和
                ElemType maxSum;
                if (MaxSubArray(L, maxSum) == OK)
                    printf("  => Max subarray sum: %d\n", maxSum);
                else
                    printf("Calculation failed!\n");
                break;
            }

            case 14: {  // 和为k的子数组个数
                int k, cnt;
                printf("  => Enter target sum k: ");
                scanf("%d", &k); getchar();
                if (SubArrayNum(L, k, cnt) == OK)
                    printf("  => Subarrays with sum %d: %d\n", k, cnt);
                else
                    printf("Calculation failed!\n");
                break;
            }

            case 15:  // 排序线性表
                if (sortList(L) == OK) {
                    printf("Sorted! Result: ");
                    ListTraverse(L); printf("\n");
                } else
                    printf("Sort failed!\n");
                break;

            case 24: {  // TwoSum两数之和
                int target, idx1, idx2;
                printf("  => Enter target sum: ");
                scanf("%d", &target); getchar();
                sortList(L);  // 确保有序
                if(TwoSum(L, target, idx1, idx2) == OK)
                    printf("  => Found: L[%d]=%d + L[%d]=%d = %d\n", 
                           idx1, L.elem[idx1-1], idx2, L.elem[idx2-1], target);
                else
                    printf("No pair found with target sum!\n");
                break;
            }

            case 25: {  // MergeList合并线性表
                // 检查主表L是否已初始化
                if(L.elem == NULL) {
                    printf("  => Error: List L is not initialized! Please run 1.InitList first.\n");
                    break;
                }

                SqList L2, merged;
                // 显式初始化局部变量
                L2.elem = NULL; L2.length = 0; L2.listsize = 0;
                merged.elem = NULL; merged.length = 0; merged.listsize = 0;

                InitList(L2);
                // 注意：不要 InitList(merged)，MergeList 内部会自己初始化

                printf("  => Demo merge: Enter 3 elements for L2 (space separated)\n");
                for(int i=1; i<=3; i++) {
                    ElemType val;
                    printf("    L2[%d] = ", i);
                    scanf("%d", &val);
                    ListInsert(L2, i, val);
                }
                // 清理输入缓冲区
                while(getchar() != '\n' && !feof(stdin));

                // 排序确保合并结果有序
                sortList(L);
                sortList(L2);

                printf("  => L1: "); ListTraverse(L); printf("\n");
                printf("  => L2: "); ListTraverse(L2); printf("\n");

                if(MergeList(L, L2, merged) == OK) {
                    printf("Merged! Result: ");
                    ListTraverse(merged); printf("\n");
                } else {
                    printf("Merge failed! (Check if lists are valid)\n");
                }
                
                // 释放临时表内存
                DestroyList(L2);
                DestroyList(merged);
                break;
            }

            case 21:  // 翻转线性表
                if (ReverseList(L) == OK) {
                    printf("Reversed! Result: ");
                    ListTraverse(L); printf("\n");
                } else
                    printf("Reverse failed!\n");
                break;
            
            case 22:  // 去重
                if (RemoveDuplicate(L) == OK) {
                    printf("Duplicates removed! Result: ");
                    ListTraverse(L); printf("\n");
                } else
                    printf("Remove duplicate failed!\n");
                break;
            
            case 23: {  // 求最大值
                ElemType max;
                if (GetMax(L, max) == OK)
                    printf("  => Maximum value: %d\n", max);
                else
                    printf("Get max failed!\n");
                break;
            }

            case 26: {  // 求最小值
                ElemType min;
                if (GetMin(L, min) == OK)
                    printf("  => Minimum value: %d\n", min);
                else
                    printf("Get min failed!\n");
                break;
            }

            case 27: {  // 删除所有指定值
                ElemType val;
                printf("  => Enter value to delete all: ");
                scanf("%d", &val); getchar();
                if (DeleteVal(L, val) == OK) {
                    printf("  => Deleted! Result: ");
                    ListTraverse(L); printf("\n");
                } else
                    printf("  => Delete failed!\n");
                break;
            }

            case 28: {  // 奇偶拆分线性表
                // 检查主表L是否已初始化
                if(L.elem == NULL) {
                    printf("  => Error: List L is not initialized! Please run 1.InitList first.\n");
                    break;
                }
                
                // 检查主表是否为空
                if(L.length == 0) {
                    printf("  => Warning: List L is empty, nothing to split.\n");
                    break;
                }
                
                SqList Odd, Even;
                // 显式初始化局部变量，防止随机值干扰
                Odd.elem = NULL; Odd.length = 0; Odd.listsize = 0;
                Even.elem = NULL; Even.length = 0; Even.listsize = 0;
                
                if (SplitList(L, Odd, Even) == OK) {
                    printf("  => Odd list: "); 
                    if(Odd.length == 0) printf("(empty)");
                    else ListTraverse(Odd); 
                    printf("\n");
                    
                    printf("  => Even list: "); 
                    if(Even.length == 0) printf("(empty)");
                    else ListTraverse(Even); 
                    printf("\n");
                    
                    // 释放临时表内存，防止泄漏
                    DestroyList(Odd); 
                    DestroyList(Even);
                } else {
                    printf("  => Split failed!\n");
                }
                break;
            }

            case 29: {  // 批量插入
                int pos, n;
                printf("  => Enter insert position (1~%d): ", ListLength(L) + 1);
                scanf("%d", &pos); getchar();
                printf("  => Enter number of elements to insert: ");
                scanf("%d", &n); getchar();
                if(n > 0 && n <= 100) {
                    ElemType *arr = (ElemType *)malloc(n * sizeof(ElemType));
                    printf("  => Enter %d elements (space separated): ", n);
                    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
                    while(getchar() != '\n' && !feof(stdin));
                    
                    if(BatchInsert(L, pos, arr, n) == OK) {
                        printf("  => Batch insert successful! Result: ");
                        ListTraverse(L); printf("\n");
                    } else printf("  => Batch insert failed!\n");
                    free(arr);
                } else printf("  => Invalid element count!\n");
                break;
            }

            case 30: {  // 批量删除
                int pos, n;
                printf("  => Enter start position to delete (1~%d): ", ListLength(L));
                scanf("%d", &pos); getchar();
                printf("  => Enter number of elements to delete: ");
                scanf("%d", &n); getchar();
                if(BatchDelete(L, pos, n) == OK) {
                    printf("  => Deleted elements: ");
                    for(int i=0; i<n; i++) {
                        printf("%d ", L.elem[pos-1+i]);
                    }
                    printf("\n");
                    printf("  => Batch delete successful! Result: ");
                    ListTraverse(L); printf("\n");
                } else printf("  => Batch delete failed!\n");
                break;
            }

            case 16: {  // 保存线性表到文件
                char fileName[50];
                printf("  => Enter filename to save: ");
                scanf("%s", fileName); getchar();
                if (SaveList(L, fileName) == OK)
                    printf("  => Saved to file: %s\n", fileName);
                else
                    printf("  => Save failed!\n");
                break;
            }

            case 17: {  // 从文件加载线性表
                char fileName[50];
                printf("  => Enter filename to load: ");
                scanf("%s", fileName); getchar();
                if(L.elem != NULL) DestroyList(L);
                if (LoadList(L, fileName) == OK) {
                    printf("  => Loaded! Content: ");
                    ListTraverse(L); printf("\n");
                } else
                    printf("  => Load failed! File not found or invalid!\n");
                break;
            }

            case 18: {  // 增加新线性表
                char listName[30];
                printf("  => Enter name for new list: ");
                scanf("%s", listName); getchar();
                if (AddList(Lists, listName) == OK)
                    printf("  => List added successfully!\n");
                else
                    printf("  => Add failed! Collection full or name exists!\n");
                break;
            }

            case 19: {  // 删除线性表
                char listName[30];
                printf("  => Enter name of list to remove: ");
                scanf("%s", listName); getchar();
                if (RemoveList(Lists, listName) == OK)
                    printf("  => List removed!\n");
                else
                    printf("  => Remove failed! Name not found!\n");
                break;
            }

            case 20: {  // 查找线性表
                char listName[30];
                printf("  => Enter name to search: ");
                scanf("%s", listName); getchar();
                int pos = LocateList(Lists, listName);
                if (pos > 0)
                    printf("  => List '%s' found at position: %d\n", listName, pos);
                else
                    printf("  => Search failed! List not found!\n");
                break;
            }

            case 31: {  // 保存当前表到集合
                char listName[30];
                printf("  => Enter name to save current list: ");
                scanf("%s", listName); getchar();
                if(SaveCurrentToList(L, Lists, listName) == OK)
                    printf("  => Current list saved as: %s\n", listName);
                else
                    printf("  => Save failed! Name exists or collection full.\n");
                break;
            }

            case 32: {  // 从集合加载表到当前
                char listName[30];
                printf("  => Enter list name to load: ");
                scanf("%s", listName); getchar();
                if(LoadListToCurrent(Lists, listName, L) == OK) {
                    printf("  => Loaded list: %s\n", listName);
                    printf("  => Content: "); ListTraverse(L); printf("\n");
                } else
                    printf("  => Load failed! List not found.\n");
                break;
            }

            case 33: {  // 交换元素
                int i, j;
                printf("  => Enter position i: ");
                scanf("%d", &i); getchar();
                printf("  => Enter position j: ");
                scanf("%d", &j); getchar();
                if(SwapElem(L, i, j) == OK)
                    printf("  => Swap successful!\n");
                else
                    printf("  => Swap failed! Invalid position.\n");
                break;//
            }

            case 34: {  // 循环移位
                int k;
                printf("  => Enter shift k (positive=right, negative=left): ");
                scanf("%d", &k); getchar();
                if(RotateList(L, k) == OK) {
                    printf("  => Rotated! Result: ");
                    ListTraverse(L); printf("\n");
                } else printf("  => Rotate failed!\n");
                break;
            }

            case 0:
                printf("\n");
                printf("   Thank you for using Linear Table System!\n");
                printf("\n");
                // 清理资源
                if(L.elem != NULL) DestroyList(L);
                for(int i=0; i<Lists.length; i++)
                    DestroyList(Lists.elem[i].L);
                break;

            default:
                printf("Invalid input! Please enter 0-32.\n");
                break;
        }/* end of switch */		
    }/* end of while */

    return 0;
}/* end of main */


status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/

    //第一步：判断线性表是否存在,存在则返回INFEASIBLE
    if(L.elem != NULL)
    {
        return INFEASIBLE;
    }

    //第二步：线性表L不存在时，分配空间
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(L.elem == NULL)
    {
        return OVERFLOW;    //空间不足则溢出
    }

    //第三步：初始化长度和当前实际储存空间大小
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    //第四步：初始化成功，则返回
    return OK;
    /********** End **********/
}

status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if(L.elem == NULL)     //表没有初始化，不能进行销毁操作
    {
        return INFEASIBLE;
    }

    free(L.elem);           //释放线性表
    L.elem = NULL;          //将指针置为NULL防止悬挂指针
    L.length = 0;           //长度置0
    L.listsize = 0;         //储存空间置0

    return OK;
    /********** End **********/
}

status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if(L.elem == NULL)          //线性表不存在的时候不清空
    {
        return INFEASIBLE;
    }

    L.length = 0;               //长度置0

    return OK;

    /********** End **********/
}

status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if(L.elem == NULL)      //线性表不存在
        return INFEASIBLE;

    if(L.length == 0)       //线性表长度为0
    {
        return TRUE;
    }
    else                    //线性表长度不为0
    {
        return FALSE;
    }
    /********** End **********/
}


status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //表存在时返回线性表的长度
    return L.length;
    /********** End **********/
}


status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断i的位置是否合法
    if(i < 1 || i > L.length)
    {
        return ERROR;
    }

    //获取元素并赋值给e
    e = L.elem[i-1];

    return OK;
    /********** End **********/
}

int LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //遍历查找目标元素e
    for(int i=0; i<L.length; i++)
    {
        //判断是否找到目标元素
        if(L.elem[i] == e)
        {
            return i+1; //返回元素逻辑下标
        }
    }

    //查找失败
    return ERROR;
    /********** End **********/
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //遍历查找元素e的前驱
    for(int i=0; i<L.length; i++)
    {
        if(L.elem[i] == e)
        {
            //第一个元素没有前驱
            if(i == 0)
            {
                return ERROR;
            }
            //其余元素存在前驱
            pre = L.elem[i-1];
            return OK;
        }      
    }
    
    //查找失败
    return ERROR;
    /********** End **********/
}


status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L中元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //遍历查找元素e的后继
    for(int i=0; i<L.length; i++)
    {
        if(L.elem[i] == e)
        {
            //最后一个元素没有后继
            if(i == L.length - 1)
            {
                return ERROR;
            }
            //其余元素存在后继
            next = L.elem[i+1];
            return OK;
        }      
    }
    
    //查找失败
    return ERROR;
    /********** End **********/
}


status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断i的值是否合法
    if(i<1 || i>L.length+1) return ERROR;

    //判断插入后是否会溢出，如果溢出则重新分配空间
    if(L.length >= L.listsize)
    {
        ElemType *newelem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(newelem == NULL) //判断是否扩充失败
        {
            return OVERFLOW;
        }
        L.elem = newelem;
        L.listsize += LISTINCREMENT;
    }
    
    //第i个以及之后元素向后移位
    for(int j=L.length-1; j>=i-1; j--)
    {
        L.elem[j+1] = L.elem[j];
    }

    //插入新元素
    L.elem[i-1] = e;

    //更新表长
    L.length++;

    return OK;
    /********** End **********/
}


status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断i是否合法
    if(i<1 || i>L.length) return ERROR;

    //保存需要删除的元素
    e = L.elem[i-1];
    
    //依次移动元素实现删除
    for(int j=i; j<L.length; j++)
    {
        L.elem[j-1] = L.elem[j];
    }

    //更新表长
    L.length--;

    return OK;
    /********** End **********/
}

status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //依次遍历输出元素
    for(int i=0; i<L.length; i++)
    {   
        //控制输出格式
        if(i == L.length-1)
        {
            printf("%d", L.elem[i]);
        }
        else{
            printf("%d ", L.elem[i]);
        }
    }

    return OK;
    /********** End **********/
}

status MaxSubArray(SqList& L, int& maxSum)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    maxSum = L.elem[0];         // 初始化最大子数组和为第一个元素
    int currentSum = L.elem[0]; // 当前子数组和也初始化为第一个元素

    for(int i = 1; i < L.length; i++)
    {
        // 如果当前子数组和为负数，则从当前元素重新开始计算
        if(currentSum < 0)
        {
            currentSum = L.elem[i];
        }
        else
        {
            currentSum += L.elem[i];
        }

        // 更新最大子数组和
        if(currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }
    return OK;
}

status SubArrayNum(SqList& L, int &k, int &cnt)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    cnt = 0; // 初始化计数器

    // 双重循环枚举所有子数组，计算子数组和并与k比较
    for(int i=0; i<L.length; i++)
    {
        int sum = 0;
        for(int j=i; j<L.length; j++)
        {
            sum += L.elem[j];
            if(sum == k)
            {
                cnt++; // 找到一个子数组和为k，计数器加1
            }
        }
    }
    return OK;
}

status sortList(SqList& L)
{
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //使用冒泡排序算法对线性表进行排序
    for(int i=0; i<L.length-1; i++)
    {
        for(int j=0; j<L.length-1-i; j++)
        {
            if(L.elem[j] > L.elem[j+1])
            {
                //交换元素
                ElemType temp = L.elem[j];
                L.elem[j] = L.elem[j+1];
                L.elem[j+1] = temp;
            }
        }
    }
    return OK;
}

status SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //打开文件（使用二进制模式确保数据完整）
    FILE *fp = fopen(FileName, "wb");
    if(!fp)  //判断打开是否成功
    {
        return ERROR;
    }           

    //一次性将所有元素写入文件
    fwrite(L.elem, sizeof(ElemType), L.length, fp);

    //关闭文件
    fclose(fp);

    return OK;
    /********** End **********/
}

status LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem != NULL)
    {
        return INFEASIBLE;
    }
    
    //打开文件（使用二进制模式）
    FILE *fp = fopen(FileName, "rb");
    if(!fp)  // 修复：文件打开失败时不应对NULL调用fclose
    {
        return ERROR;
    }

    //线性表不存在时，初始化线性表
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(L.elem == NULL)
    {
        fclose(fp);
        return OVERFLOW;
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    //一次性读入数据到线性表
    while(fread(&L.elem[L.length], sizeof(ElemType), 1, fp) == 1)
    {
        //更新表长
        L.length++;
        //判断是否会溢出，如果会则重新分配空间
        if(L.length >= L.listsize)
        {
            ElemType *newelem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
            if(!newelem)
            {
                fclose(fp);
                free(L.elem);
                L.elem = NULL;
                return OVERFLOW;
            }
            L.elem = newelem;
            L.listsize += LISTINCREMENT;
        }
    }

    //关闭文件
    fclose(fp);
    return OK;
    /********** End **********/
}

status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    /********** Begin *********/
    //插入前需要判断线性表的集合是否已满
    if(Lists.length >= 10)
    {
        return ERROR;
    }

    //利用第一关的函数初始化一个空的线性表
    Lists.elem[Lists.length].L.elem = NULL;     //这里需要先初始化指针为NULL，防止随机值没有办法使用InitList函数
    InitList(Lists.elem[Lists.length].L);

    //将线性表名称添加到集合中
    int i = 0;
    while (ListName[i] != '\0')
    {
        Lists.elem[Lists.length].name[i] = ListName[i];
        i++;
    }
    Lists.elem[Lists.length].name[i] = '\0'; 

    //更新表长
    Lists.length++;

    return OK;

    /********** End **********/
}

status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    /********** Begin *********/
    //查找是否存在名称匹配的线性表
    int found=-1;   //found=-1表示没找到，否则为匹配到的相应下标
    for(int i=0; i<Lists.length; i++)
    {
        int j =0;
        int flag=1; //标记是否匹配
        while(ListName[j]!='\0' && Lists.elem[i].name[j]!='\0')
        {
            //依次比较两个字符串是否相等
            if(ListName[j] != Lists.elem[i].name[j])
            {
                flag = 0;
                break;
            }
            j++;
        }
        //字符串完全相等：内容相同并且同时结束
        if(flag==1 && ListName[j]=='\0' && Lists.elem[i].name[j]=='\0')
        {
            found = i;
            break;
        }
    }

    //如果匹配失败则返回ERROR
    if(found == -1)
    {
        return ERROR;
    }
    
    //匹配成功则销毁相应线性表
    DestroyList(Lists.elem[found].L);

    //移动覆盖删除Lists集合对应部分
    // 修复：k<=Lists.length-1 改为 k<Lists.length 避免越界
    for(int k=found; k<Lists.length; k++)
    {
        Lists.elem[k] = Lists.elem[k+1];
    }

    //更新表长
    Lists.length--;

    return OK;

    /********** End **********/
}

int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    /********** Begin *********/
    //查找是否存在名称匹配的线性表
    int found = -1; //found=-1表示没找到，否则为匹配到的相应下标
    for(int i=0; i<Lists.length; i++)
    {
        //依次比较两个字符串是否相等
        int j = 0;
        int flag = 1;   //标记是否匹配
        while(ListName[j]!='\0' && Lists.elem[i].name[j]!='\0')
        {
            if(ListName[j] != Lists.elem[i].name[j])
            {
                flag = 0;
                break;
            }
            j++;
        }

        //字符串完全相等：内容相同并且同时结束
        if(flag==1 && ListName[j]=='\0' && Lists.elem[i].name[j]=='\0')
        {
            found = i;
            break;
        }
    }
    
    //返回逻辑下标
    return found + 1;

    /********** End **********/
}

status ReverseList(SqList &L)
// 翻转线性表
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //使用双指针分别从前后两端向中间遍历，交换元素实现翻转
    int left = 0;
    int right = L.length - 1;
    while(left < right)
    {
        //交换元素
        ElemType temp = L.elem[left];
        L.elem[left] = L.elem[right];
        L.elem[right] = temp;

        //指针向中间移动
        left++;
        right--;
    }
    return OK;
    /********** End **********/
}

status RemoveDuplicate(SqList &L)
// 去重
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //如果表中只有一个元素或者没有元素，则不需要删除重复元素
    if(L.length <= 1)
    {
        return OK;
    }

    //使用双重循环删除重复元素
    for(int i=0; i<L.length-1; i++)
    {
        for(int j=i+1; j<L.length; j++)
        {
            if(L.elem[i] == L.elem[j])
            {
                //再用一个循环覆盖删除重复元素
                for(int k=j; k<L.length-1; k++)
                {
                    L.elem[k] = L.elem[k+1];
                }
                L.length--; //更新表长
                j--; //调整j的值以继续检查新的位置
            }
        }
    }
    // 修复：添加返回值
    return OK;
    /********** End **********/
}

status GetMax(SqList L, ElemType &max)
// 最大值
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //如果表为空，返回错误
    if(L.length == 0) return ERROR;

    max = L.elem[0]; // 初始化最大值为第一个元素

    //遍历线性表寻找最大值
    for(int i=1; i<L.length; i++)
    {
        if(L.elem[i] > max)
        {
            max = L.elem[i];
        }
    }
    return OK;
    /********** End **********/
}

status GetMin(SqList L, ElemType &min)
// 最小值
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //如果表为空，返回错误
    if(L.length == 0) return ERROR;

    min = L.elem[0]; // 初始化最小值为第一个元素

    //遍历线性表寻找最小值
    for(int i=1; i<L.length; i++)
    {
        if(L.elem[i] < min)
        {
            min = L.elem[i];
        }
    }
    return OK;
    /********** End **********/
}

status DeleteVal(SqList &L, ElemType e)
// 删除所有指定值
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //使用双指针法删除值为e的元素
    int i = 0; //慢指针，指向下一个要被覆盖的位置
    for(int j=0; j<L.length; j++) //快指针，遍历线性表
    {
        if(L.elem[j] != e) //如果当前元素不等于e，则将其保留
        {
            L.elem[i] = L.elem[j]; //覆盖慢指针位置的元素
            i++; //慢指针向后移动
        }
    }

    //更新表长
    L.length = i;

    return OK;
    /********** End **********/
}

status SplitList(SqList L, SqList &Odd, SqList &Even)
// 奇偶拆分线性表
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //初始化奇数线性表和偶数线性表（确保目标表为空）
    if(Odd.elem != NULL) DestroyList(Odd);
    if(Even.elem != NULL) DestroyList(Even);
    InitList(Odd);
    InitList(Even);

    //遍历原线性表，将奇数元素插入到Odd中，偶数元素插入到Even中
    for(int i=0; i<L.length; i++)
    {
        if(L.elem[i] % 2 == 0) //偶数
        {
            // 偶数表空间不足时自动扩容
            if(Even.length >= Even.listsize)
            {
                ElemType *newelem = (ElemType *)realloc(Even.elem, (Even.listsize + LISTINCREMENT) * sizeof(ElemType));
                if(newelem == NULL) return OVERFLOW;
                Even.elem = newelem;
                Even.listsize += LISTINCREMENT;
            }
            Even.elem[Even.length++] = L.elem[i];
        }
        else //奇数
        {
            // 奇数表空间不足时自动扩容
            if(Odd.length >= Odd.listsize)
            {
                ElemType *newelem = (ElemType *)realloc(Odd.elem, (Odd.listsize + LISTINCREMENT) * sizeof(ElemType));
                if(newelem == NULL) return OVERFLOW;
                Odd.elem = newelem;
                Odd.listsize += LISTINCREMENT;
            }
            // 插入奇数元素
            Odd.elem[Odd.length++] = L.elem[i];
        }
    }
    return OK;
    /********** End **********/
}

status BatchInsert(SqList &L, int pos, ElemType arr[], int n)
// 在位置pos处批量插入元素
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断插入位置是否合法
    if(pos < 1 || pos > L.length + 1)
    {
        return ERROR;
    }

    //判断插入元素个数是否合法
    if(n <= 0) return OK;

    //判断插入后是否会溢出，如果会则重新分配空间
    while(L.length + n > L.listsize)
    {
        ElemType *newelem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(newelem == NULL)
        {
            return OVERFLOW;
        }
        L.elem = newelem;
        L.listsize += LISTINCREMENT;
    }

    //将pos及之后的元素向后移动n个位置
    for(int i=L.length-1; i>=pos-1; i--)
    {
        L.elem[i+n] = L.elem[i];
    }

    //将新元素批量插入到pos位置
    for(int j=0; j<n; j++)
    {
        L.elem[pos-1+j] = arr[j];
    }

    //更新表长
    L.length += n;

    return OK;
    /********** End **********/
}

status BatchDelete(SqList &L, int pos, int n)
// 从位置pos处批量删除n个元素
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断删除位置是否合法
    if(pos < 1 || pos > L.length || pos + n - 1 > L.length)
    {
        return ERROR;
    }

    //判断删除个数是否合法
    if(n <= 0) return OK;

    //将pos+n及之后的元素向前移动n个位置覆盖要删除的元素
    for(int i=pos+n-1; i<L.length; i++)
    {
        L.elem[i-n] = L.elem[i];
    }

    //更新表长
    L.length -= n;

    return OK;
    /********** End **********/
}

status MergeList(SqList L1, SqList L2, SqList &merged)
// 合并两个有序线性表
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L1.elem == NULL || L2.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断目标表是否已初始化
    if(merged.elem != NULL)
    {
        return INFEASIBLE;
    }

    //初始化合并后的线性表
    InitList(merged);

    int i = 0, j = 0; // i和j分别是L1和L2的当前元素索引

    //使用双指针法合并两个有序线性表
    while(i < L1.length && j < L2.length)
    {
        if(L1.elem[i] <= L2.elem[j])
        {
            // 目标表空间不足时自动扩容
            if(merged.length >= merged.listsize)
            {
                ElemType *newelem = (ElemType *)realloc(merged.elem, (merged.listsize + LISTINCREMENT) * sizeof(ElemType));
                if(newelem == NULL) return OVERFLOW;
                merged.elem = newelem;
                merged.listsize += LISTINCREMENT;
            }
            merged.elem[merged.length++] = L1.elem[i++];
        }
        else
        {
            // 目标表空间不足时自动扩容
            if(merged.length >= merged.listsize)
            {
                ElemType *newelem = (ElemType *)realloc(merged.elem, (merged.listsize + LISTINCREMENT) * sizeof(ElemType));
                if(newelem == NULL) return OVERFLOW;
                merged.elem = newelem;
                merged.listsize += LISTINCREMENT;
            }
            merged.elem[merged.length++] = L2.elem[j++];
        }
    }

    //如果L1还有剩余元素，全部插入到merged中
    while(i < L1.length)
    {
        if(merged.length >= merged.listsize)
        {
            ElemType *newelem = (ElemType *)realloc(merged.elem, (merged.listsize + LISTINCREMENT) * sizeof(ElemType));
            if(newelem == NULL) return OVERFLOW;
            merged.elem = newelem;
            merged.listsize += LISTINCREMENT;
        }
        merged.elem[merged.length++] = L1.elem[i++];
    }

    //如果L2还有剩余元素，全部插入到merged中
    while(j < L2.length)
    {
        if(merged.length >= merged.listsize)
        {
            ElemType *newelem = (ElemType *)realloc(merged.elem, (merged.listsize + LISTINCREMENT) * sizeof(ElemType));
            if(newelem == NULL) return OVERFLOW;
            merged.elem = newelem;
            merged.listsize += LISTINCREMENT;
        }
        merged.elem[merged.length++] = L2.elem[j++];
    }

    return OK;
    /********** End **********/
}

status TwoSum(SqList L, int target, int &idx1, int &idx2)
// 在有序线性表中找到两个数使得它们的和为target
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //如果元素少于2个，无法找到两数之和
    if(L.length < 2) return ERROR;

    //前提：线性表已按升序排序
    int left = 0;              //左指针初始化为第一个元素
    int right = L.length - 1;  //右指针初始化为最后一个元素

    while(left < right)
    {
        int sum = L.elem[left] + L.elem[right]; //计算当前指针指向的两个元素的和

        if(sum == target) //如果找到目标和，返回下标
        {
            idx1 = left + 1; //返回逻辑下标（从1开始）
            idx2 = right + 1;
            return OK;
        }
        else if(sum < target) //如果当前和小于目标和，左指针向右移动增加和
        {
            left++;
        }
        else //如果当前和大于目标和，右指针向左移动减少和
        {
            right--;
        }
    }

    return ERROR; //没有找到满足条件的两个数
    /********** End **********/
}

status SaveCurrentToList(SqList L, LISTS &Lists, char ListName[])
// 将当前线性表L保存到集合Lists中，命名为ListName
{
    /********** Begin *********/
    //判断集合是否已满
    if(Lists.length >= 10)
    {
        return ERROR;
    }

    //判断名称是否已存在
    if(LocateList(Lists, ListName) > 0)
    {
        return ERROR;
    }

    //在集合末尾创建新条目
    int idx = Lists.length;

    //复制名称到集合中
    int i = 0;
    while(ListName[i] != '\0' && i < 29)
    {
        Lists.elem[idx].name[i] = ListName[i];
        i++;
    }
    Lists.elem[idx].name[i] = '\0';

    //深拷贝线性表数据到集合中
    Lists.elem[idx].L.length = L.length;
    Lists.elem[idx].L.listsize = L.listsize;
    if(L.length > 0)
    {
        Lists.elem[idx].L.elem = (ElemType *)malloc(L.listsize * sizeof(ElemType));
        if(Lists.elem[idx].L.elem == NULL)
        {
            return OVERFLOW;
        }

        //拷贝元素到集合中
        for(int j = 0; j < L.length; j++)
        {
            Lists.elem[idx].L.elem[j] = L.elem[j];
        }
    }
    else
    {
        Lists.elem[idx].L.elem = NULL;
    }

    //更新集合长度
    Lists.length++;

    return OK;
    /********** End **********/
}


status LoadListToCurrent(LISTS Lists, char ListName[], SqList &L)
// 从集合Lists中加载名为ListName的线性表到当前表L
{
    /********** Begin *********/
    //查找目标表在集合中的位置
    int pos = LocateList(Lists, ListName) - 1;  //转为0起始下标
    if(pos < 0)  //未找到
    {
        return ERROR;
    }

    //释放当前表L的原有资源
    if(L.elem != NULL)
    {
        free(L.elem);
        L.elem = NULL;
    }

    //深拷贝集合中的目标表到当前表L
    L.length = Lists.elem[pos].L.length;
    L.listsize = Lists.elem[pos].L.listsize;
    if(L.length > 0)
    {
        L.elem = (ElemType *)malloc(L.listsize * sizeof(ElemType));
        if(L.elem == NULL)
        {
            return OVERFLOW;
        }
        for(int i = 0; i < L.length; i++)
        {
            L.elem[i] = Lists.elem[pos].L.elem[i];
        }
    }

    return OK;
    /********** End **********/
}

status SwapElem(SqList &L, int i, int j)
// 交换线性表中第i个和第j个元素，返回OK；位置不合法返回ERROR；表不存在返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //判断位置是否合法
    if(i < 1 || i > L.length || j < 1 || j > L.length)
    {
        return ERROR;
    }

    //同一位置无需交换
    if(i == j) return OK;

    //交换元素
    ElemType temp = L.elem[i-1];
    L.elem[i-1] = L.elem[j-1];
    L.elem[j-1] = temp;

    return OK;
    /********** End **********/
}

status RotateList(SqList &L, int k)
// 将线性表循环移动k位（k>0向右，k<0向左），返回OK；表不存在返回INFEASIBLE。
{
    /********** Begin *********/
    //判断线性表是否存在
    if(L.elem == NULL)
    {
        return INFEASIBLE;
    }

    //空表或单元素表无需移动
    if(L.length <= 1) return OK;

    //规范化k值
    k = k % L.length;
    if(k < 0) k += L.length;
    if(k == 0) return OK;

    //三次翻转法实现循环右移：整体翻转 - 前k个翻转 - 后n-k个翻转
    // 1. 整体翻转
    int left = 0, right = L.length - 1;
    while(left < right) {
        ElemType t = L.elem[left]; L.elem[left] = L.elem[right]; L.elem[right] = t;
        left++; right--;
    }
    // 2. 前k个翻转
    left = 0; right = k - 1;
    while(left < right) {
        ElemType t = L.elem[left]; L.elem[left] = L.elem[right]; L.elem[right] = t;
        left++; right--;
    }
    // 3. 后n-k个翻转
    left = k; right = L.length - 1;
    while(left < right) {
        ElemType t = L.elem[left]; L.elem[left] = L.elem[right]; L.elem[right] = t;
        left++; right--;
    }

    return OK;
    /********** End **********/
}
