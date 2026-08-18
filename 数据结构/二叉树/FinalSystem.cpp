/* 基于二叉链表的二叉树实现演示系统 - 数据结构实验3 */
/*作者：彭婉茹（U202514699）*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//状态码定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//数据元素类型定义
typedef int status;
typedef int KeyType; 

//二叉树节点类型定义
typedef struct {
    KeyType  key;
    char others[20];
} TElemType;

//二叉链表结点的定义
typedef struct BiTNode{
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

//单棵树信息结构体 
typedef struct
{
    char name[30];
    BiTree T;
} BiTreeInfo;

//多树管理表结构体
typedef struct
{
    BiTreeInfo elem[15];
    int length;
    int listsize;
} TreeList;

// 全局管理器
TreeList TreeManager;
int currentTreeIdx = -1;  // 当前操作的树索引

//基本函数声明（保持不变）
status CreateBiTree(BiTree &T,TElemType definition[]);
status ClearBiTree(BiTree &T);
int BiTreeDepth(BiTree T);
BiTNode* LocateNode(BiTree T,KeyType e);
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c);
status Assign(BiTree &T,KeyType e,TElemType value);
BiTNode* GetSibling(BiTree T,KeyType e);
status DeleteNode(BiTree &T,KeyType e);
status PreOrderTraverse(BiTree T,void (*visit)(BiTree));
status InOrderTraverse(BiTree T,void (*visit)(BiTree));
status PostOrderTraverse(BiTree T,void (*visit)(BiTree));
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree));

//附加功能函数申明（保持不变）
int MaxPathSum(BiTree T);
BiTree LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2);
status InvertTree(BiTree T);
void Save(BiTree T, FILE *fp);
status SaveBiTree(BiTree T, char FileName[]);
BiTree Build(FILE *fp);
status LoadBiTree(BiTree &T,  char FileName[]);
status AddTree(TreeList &L, char name[], BiTree T);
status RemoveTree(TreeList &L, char name[]);
int FindTree(TreeList L, char name[]);
status ShowTree(TreeList L);

//自定义函数声明（保持不变）
int NodeCount(BiTree T);
int LeafCount(BiTree T);
status Getlevel(BiTree T, KeyType e, int &level);
status IsFullBinaryTree(BiTree T);
status IsCompleteBinaryTree(BiTree T);
status IsEqual(BiTree T1, BiTree T2);
status FindMax(BiTree T, KeyType &max);
status FindMin(BiTree T, KeyType &min);
status WidthOfBinaryTree(BiTree T, int &width);
status NodeDegree(BiTree T, KeyType e, int &degree);
status GetDistance(BiTree T, KeyType e1, KeyType e2, int &distance);
BiTree BuildFromPreIn(TElemType pre[], TElemType in[], int len);
BiTree BuildFromPostIn(TElemType post[], TElemType in[], int len);
BiTree BuildFromLevelIn(TElemType level[], TElemType in[], int len);
void PrintNode(BiTree T);
void InitTreeManager();
BiTree& GetCurrentTree();

// 辅助函数声明
status CreateBiTreeHelper(BiTree &T, TElemType definition[], int &index);

int main()
{
    // 初始化树管理器
    InitTreeManager();
    
    int op = 1;

    // 首次运行打印菜单
    printf("  ==============================================\n");
    printf("  |  Binary Tree On Linked Structure           |\n");
    printf("  |   Author: Peng Wanru (U202514699)          |\n");
    printf("  ==============================================\n");
    printf("  --- Tree Management ---\n");
    printf("  30.AddTree    31.RemoveTree  32.FindTree\n");
    printf("  33.SwitchTree 34.ShowAll     35.ClearAll\n");
    printf("  --- Basic Operations ---\n");
    printf("   1.Create      2.Clear        3.Depth\n");
    printf("   4.Locate      5.Insert       6.Delete\n");
    printf("   7.Assign      8.Sibling      9.PreOrder\n");
    printf("  10.InOrder    11.PostOrder   12.LevelOrder\n");
    printf("  --- Algorithm Functions ---\n");
    printf("  13.MaxPath    14.LCA         15.Invert\n");
    printf("  16.SaveFile   17.LoadFile\n");
    printf("  --- Custom Functions ---\n");
    printf("  18.NodeCount  19.LeafCount   20.GetLevel\n");
    printf("  21.IsFull     22.IsComplete  23.IsEqual\n");
    printf("  24.FindMax    25.FindMin     26.Width\n");
    printf("  27.NodeDegree 28.Distance\n");
    printf("  29.BuildPreIn 36.BuildPostIn 37.BuildLevelIn\n");
    printf("  --------------------------------------------\n");
    printf("   0.Exit\n\n");

    while (op)
    {
        printf("=> ");
        scanf("%d", &op);
        getchar();  // 吸收回车符

        /* 获取当前活动树 */
        BiTree &curT = GetCurrentTree();

        /* 根据用户选择执行相应操作 */
        switch (op)
        {
            case 30: {  // 添加新树
                char name[30];
                printf("  => Enter new tree name: ");
                scanf("%s", name); getchar();
                
                // 创建空树
                BiTree newT = NULL;
                if(AddTree(TreeManager, name, newT) == OK)
                {
                    currentTreeIdx = TreeManager.length - 1;
                    printf("  => Tree '%s' added & selected!\n", name);
                }
                else
                    printf("  => Add failed! Name exists or full.\n");
                break;
            }

            case 31: {  // 移除树
                char name[30];
                printf("  => Enter tree name to remove: ");
                scanf("%s", name); getchar();
                if(RemoveTree(TreeManager, name) == OK)
                {
                    printf("  => Tree '%s' removed!\n", name);
                    if(currentTreeIdx >= TreeManager.length)
                        currentTreeIdx = (TreeManager.length > 0) ? 0 : -1;
                }
                else
                    printf("  => Remove failed! Not found.\n");
                break;
            }

            case 32: {  // 查找树
                char name[30];
                printf("  => Enter tree name to find: ");
                scanf("%s", name); getchar();
                int pos = FindTree(TreeManager, name);
                if(pos >= 0)
                    printf("  => Found at position: %d\n", pos + 1);
                else
                    printf("  => Not found!\n");
                break;
            }

            case 33: {  // 切换树
                char name[30];
                printf("  => Enter tree name to switch: ");
                scanf("%s", name); getchar();
                int pos = FindTree(TreeManager, name);
                if(pos >= 0)
                {
                    currentTreeIdx = pos;
                    printf("  => Switched to '%s'!\n", name);
                }
                else
                    printf("  => Switch failed! Not found.\n");
                break;
            }

            case 34:  // 显示所有树
                ShowTree(TreeManager);
                break;

            case 35: {  // 清空所有树
                printf("  => Clear ALL trees? (y/n): ");
                char confirm;
                scanf(" %c", &confirm); getchar();
                if(confirm == 'y' || confirm == 'Y')
                {
                    for(int i = 0; i < TreeManager.length; i++)
                        ClearBiTree(TreeManager.elem[i].T);
                    TreeManager.length = 0;
                    currentTreeIdx = -1;
                    printf("  => All trees cleared!\n");
                }
                else
                    printf("  => Cancelled.\n");
                break;
            }

            case 1: {  // 创建二叉树
                if(curT != NULL) {
                    printf("  => Tree already exists. Clear first? (y/n): ");
                    char c; scanf(" %c", &c); getchar();
                    if(c == 'y' || c == 'Y') ClearBiTree(curT);
                    else {  break; }
                }
                
                printf("  => Enter definition sequence (0 null for empty):\n");
                printf("  => Example: 10 A 5 B 0 null 0 null 15 C 0 null 0 null\n");
                printf("  => Input: ");
                
                // 读取定义序列（简化：假设用户输入格式正确）
                TElemType def[100];
                int idx = 0;
                char line[500];
                fgets(line, 500, stdin);
                char *token = strtok(line, " \n");
                while(token != NULL && idx < 100)
                {
                    def[idx].key = atoi(token);
                    token = strtok(NULL, " \n");
                    if(token != NULL)
                    {
                        strcpy(def[idx].others, token);
                        token = strtok(NULL, " \n");
                    }
                    else
                        strcpy(def[idx].others, "null");
                    idx++;
                }
                def[idx].key = 0; strcpy(def[idx].others, "null");  // 终止符
                
                if(CreateBiTree(curT, def) == OK)
                    printf("  => Tree created successfully!\n");
                else
                    printf("  => Create failed! Duplicate key.\n");
                break;
            }

            case 2:  // 清空当前树
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                if(ClearBiTree(curT) == OK)
                    printf("  => Tree cleared!\n");
                else
                    printf("  => Clear failed!\n");
                 break;

            case 3:  // 求深度
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                printf("  => Depth: %d\n", BiTreeDepth(curT));
                 break;

            case 4: {  // 查找节点
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType e;
                printf("  => Enter key to search: "); scanf("%d", &e); getchar();
                BiTNode* node = LocateNode(curT, e);
                if(node != NULL)
                    printf("  => Found: %d(%s)\n", node->data.key, node->data.others);
                else
                    printf("  => Not found!\n");
                 break;
            }

            case 5: {  // 插入节点
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType e, newKey; char others[20]; int LR;
                printf("  => Enter parent key (0 for root): "); scanf("%d", &e); getchar();
                printf("  => Enter LR (-1=root, 0=left, 1=right): "); scanf("%d", &LR); getchar();
                printf("  => Enter new key: "); scanf("%d", &newKey); getchar();
                printf("  => Enter others: "); scanf("%s", others); getchar();
                
                TElemType c; c.key = newKey; strcpy(c.others, others);
                if(InsertNode(curT, e, LR, c) == OK)
                    printf("  => Inserted!\n");
                else
                    printf("  => Insert failed! Parent not found or duplicate key.\n");
                 break;
            }

            case 6: {  // 删除节点
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType e;
                printf("  => Enter key to delete: "); scanf("%d", &e); getchar();
                if(DeleteNode(curT, e) == OK)
                    printf("  => Deleted!\n");
                else
                    printf("  => Delete failed! Node not found.\n");
                 break;
            }

            case 7: {  // 节点赋值
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType e, newKey; char others[20];
                printf("  => Enter key to modify: "); scanf("%d", &e); getchar();
                printf("  => Enter new key: "); scanf("%d", &newKey); getchar();
                printf("  => Enter new others: "); scanf("%s", others); getchar();
                
                TElemType value; value.key = newKey; strcpy(value.others, others);
                if(Assign(curT, e, value) == OK)
                    printf("  => Assigned!\n");
                else
                    printf("  => Assign failed! Node not found or duplicate key.\n");
                 break;
            }

            case 8: {  // 获取兄弟节点
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType e;
                printf("  => Enter key: "); scanf("%d", &e); getchar();
                BiTNode* sib = GetSibling(curT, e);
                if(sib != NULL)
                    printf("  => Sibling: %d(%s)\n", sib->data.key, sib->data.others);
                else
                    printf("  => No sibling or node is root!\n");
                 break;
            }

            case 9:  // 先序遍历
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                printf("  => PreOrder: "); PreOrderTraverse(curT, PrintNode); printf("\n");
                 break;

            case 10:  // 中序遍历
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                printf("  => InOrder: "); InOrderTraverse(curT, PrintNode); printf("\n");
                 break;

            case 11:  // 后序遍历
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                printf("  => PostOrder: "); PostOrderTraverse(curT, PrintNode); printf("\n");
                 break;

            case 12:  // 层序遍历
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                printf("  => LevelOrder: "); LevelOrderTraverse(curT, PrintNode); printf("\n");
                 break;

            //================ 算法功能 =================
            case 13: {  // 最大路径和
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                printf("  => Max path sum: %d\n", MaxPathSum(curT));
                 break;
            }

            case 14: {  // 最近公共祖先
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType e1, e2;
                printf("  => Enter two keys: "); scanf("%d %d", &e1, &e2); getchar();
                BiTree lca = LowestCommonAncestor(curT, e1, e2);
                if(lca != NULL)
                    printf("  => LCA: %d(%s)\n", lca->data.key, lca->data.others);
                else
                    printf("  => LCA not found!\n");
                 break;
            }

            case 15:  // 翻转二叉树
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                if(InvertTree(curT) == OK)
                {
                    printf("  => Inverted! InOrder: ");
                    InOrderTraverse(curT, PrintNode); printf("\n");
                }
                else
                    printf("  => Invert failed!\n");
                 break;

            case 16: {  // 保存到文件
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                char fileName[50];
                printf("  => Enter filename: "); scanf("%s", fileName); getchar();
                if(SaveBiTree(curT, fileName) == OK)
                    printf("  => Saved to %s\n", fileName);
                else
                    printf("  => Save failed!\n");
                 break;
            }

            case 17: {  // 从文件加载
                if(curT != NULL) {
                    printf("  => Tree exists. Overwrite? (y/n): ");
                    char c; scanf(" %c", &c); getchar();
                    if(c != 'y' && c != 'Y') {  break; }
                    ClearBiTree(curT);
                }
                char fileName[50];
                printf("  => Enter filename: "); scanf("%s", fileName); getchar();
                if(LoadBiTree(curT, fileName) == OK)
                {
                    printf("  => Loaded! InOrder: ");
                    InOrderTraverse(curT, PrintNode); printf("\n");
                }
                else
                    printf("  => Load failed!\n");
                 break;
            }

            case 18: {  // 节点计数
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                printf("  => Node count: %d\n", NodeCount(curT));
                 break;
            }

            case 19: {  // 叶子计数
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                printf("  => Leaf count: %d\n", LeafCount(curT));
                 break;
            }

            case 20: {  // 获取节点层级
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType e; int level;
                printf("  => Enter key: "); scanf("%d", &e); getchar();
                if(Getlevel(curT, e, level) == OK)
                    printf("  => Level: %d\n", level);
                else
                    printf("  => Node not found!\n");
                 break;
            }

            case 21: {  // 判断满二叉树
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                if(IsFullBinaryTree(curT) == TRUE)
                    printf("  => YES, full binary tree.\n");
                else
                    printf("  => NO, not full binary tree.\n");
                 break;
            }

            case 22: {  // 判断完全二叉树
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                if(IsCompleteBinaryTree(curT) == TRUE)
                    printf("  => YES, complete binary tree.\n");
                else
                    printf("  => NO, not complete binary tree.\n");
                 break;
            }

            case 23: {  // 判断两树相等
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                printf("  => Enter second tree name to compare: ");
                char name[30]; scanf("%s", name); getchar();
                int pos = FindTree(TreeManager, name);
                if(pos < 0) { printf("  => Tree not found!\n");  break; }
                
                if(IsEqual(curT, TreeManager.elem[pos].T) == TRUE)
                    printf("  => YES, trees are equal.\n");
                else
                    printf("  => NO, trees are different.\n");
                 break;
            }

            case 24: {  // 查找最大值
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType max = -999999;
                if(FindMax(curT, max) == OK)
                    printf("  => Max key: %d\n", max);
                else
                    printf("  => Find failed!\n");
                 break;
            }

            case 25: {  // 查找最小值
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType min = 999999;
                if(FindMin(curT, min) == OK)
                    printf("  => Min key: %d\n", min);
                else
                    printf("  => Find failed!\n");
                 break;
            }

            case 26: {  // 求树宽度
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                int width;
                if(WidthOfBinaryTree(curT, width) == OK)
                    printf("  => Max width: %d\n", width);
                else
                    printf("  => Calculate failed!\n");
                 break;
            }

            case 27: {  // 节点度
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType e; int degree;
                printf("  => Enter key: "); scanf("%d", &e); getchar();
                if(NodeDegree(curT, e, degree) == TRUE)
                    printf("  => Degree: %d\n", degree);
                else
                    printf("  => Node not found!\n");
                 break;
            }

            case 28: {  // 节点距离
                if(curT == NULL) { printf("  => Error: No tree selected!\n");  break; }
                KeyType e1, e2; int distance;
                printf("  => Enter two keys: "); scanf("%d %d", &e1, &e2); getchar();
                if(GetDistance(curT, e1, e2, distance) == OK)
                    printf("  => Distance: %d\n", distance);
                else
                    printf("  => Calculate failed! Node not found.\n");
                 break;
            }

            case 29: {  // 先序+中序重建
                printf("  => [Demo] Enter 3 nodes for Pre/In rebuild:\n");
                TElemType pre[3], in[3];
                printf("  => Pre: "); for(int i=0;i<3;i++) { scanf("%d %s", &pre[i].key, pre[i].others); }
                printf("  => In:  "); for(int i=0;i<3;i++) { scanf("%d %s", &in[i].key, in[i].others); }
                BiTree rebuilt = BuildFromPreIn(pre, in, 3);
                printf("  => Rebuilt InOrder: "); InOrderTraverse(rebuilt, PrintNode); printf("\n");
                ClearBiTree(rebuilt);
                 break;
            }

            case 36: {  // 后序+中序重建
                printf("  => [Demo] Enter 3 nodes for Post/In rebuild:\n");
                TElemType post[3], in[3];
                printf("  => Post: "); for(int i=0;i<3;i++) { scanf("%d %s", &post[i].key, post[i].others); }
                printf("  => In:   "); for(int i=0;i<3;i++) { scanf("%d %s", &in[i].key, in[i].others); }
                BiTree rebuilt = BuildFromPostIn(post, in, 3);
                printf("  => Rebuilt InOrder: "); InOrderTraverse(rebuilt, PrintNode); printf("\n");
                ClearBiTree(rebuilt);
                 break;
            }

            case 37: {  // 层序+中序重建
                printf("  => [Demo] Enter 3 nodes for Level/In rebuild:\n");
                TElemType level[3], in[3];
                printf("  => Level: "); for(int i=0;i<3;i++) { scanf("%d %s", &level[i].key, level[i].others); }
                printf("  => In:    "); for(int i=0;i<3;i++) { scanf("%d %s", &in[i].key, in[i].others); }
                BiTree rebuilt = BuildFromLevelIn(level, in, 3);
                printf("  => Rebuilt InOrder: "); InOrderTraverse(rebuilt, PrintNode); printf("\n");
                ClearBiTree(rebuilt);
                 break;
            }

            case 0:  // 退出系统
                printf("\n");
                for(int i=0; i<TreeManager.length; i++)
                    ClearBiTree(TreeManager.elem[i].T);
                printf("   Thank you for using Binary Tree System!\n");
                printf("   Author: Peng Wanru (U202514699)\n");
                printf("\n");
                break;

            default:
                printf("  => Invalid input! Please enter 0-37.\n");
                 break;
        }/* end of switch */
    }/* end of while */

    return 0;
}/* end of main */

status CreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int index = 0;  // 使用局部变量，每次调用都会重置
    return CreateBiTreeHelper(T, definition, index);
    /********** End **********/
}

status CreateBiTreeHelper(BiTree &T, TElemType definition[], int &index)
{
    //获取到当前访问的元素的类型
    TElemType elem = definition[index++];

    //判断是否为空树 (递归的终止条件)
    if(elem.key == 0)
    {
        T = NULL;
        return OK;
    }

    //判断关键字是否有重复，从访问过后的节点开始排查
    for(int i=0; i<index-1; i++)    //之前 index 已经++了
    {
        if(elem.key == definition[i].key)
        {
            return ERROR;
        }
    }

    //创建新节点
    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = elem;
    T->lchild = NULL;   //初始默认为 NULL，防止野指针随机值
    T->rchild = NULL;   //初始默认为 NULL，防止野指针随机值

    //开始递归生成树
    if(CreateBiTreeHelper(T->lchild, definition, index) == ERROR)    //先生成左子树
    {
        return ERROR;
    }

    if(CreateBiTreeHelper(T->rchild, definition, index) == ERROR)    //再生成右子树
    {
        return ERROR;
    }

    return OK;
}

status ClearBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断当前二叉树是否为空，这也是递归的终止条件
    if(T == NULL)
    {
        return OK;
    }

    //为了防止指针丢失，这里采用后序遍历
    //递归置空左子树和右子树
    ClearBiTree(T->lchild);
    ClearBiTree(T->rchild);

    //释放当前节点
    free(T);

    //当前置空，防止悬挂指针
    T = NULL;

    return OK;
    /********** End **********/
}

int BiTreeDepth(BiTree T)
//求二叉树 T 的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断二叉树是否为空树，空树深度返回 0，并且终止递归
    if(T == NULL)
    {
        return 0;
    }
    
    //递归求左子树深度
    int leftDepth = BiTreeDepth(T->lchild);

    //递归求右子树深度
    int rightDepth = BiTreeDepth(T->rchild);

    //返回左右子树深度较大的那个，递归终止的另外一个条件
    return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;

    /********** End **********/
}

BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //终止递归的两个条件：1.找到了相应的节点；2.空树

    //判断是否为空树，如果为空树，那么结束
    if(T == NULL)
    {
        return NULL;
    }

    //找到了相应的节点，那么返回
    if(T->data.key == e)
    {
        return T;
    }

    //没有找到的时候开始递归查找，先找左子树，后找右子树
    //递归查找左子树
    BiTree l_Node = LocateNode(T->lchild, e);
    if(l_Node != NULL)
    {
        return l_Node;
    }

    //递归查找右子树
    BiTree r_Node = LocateNode(T->rchild, e);
    if(r_Node != NULL)
    {
        return r_Node;
    }

    //如果最后都没有找到返回 NULL
    return NULL;
    /********** End **********/
}

status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断二叉树是否为空树，空树返回 ERROR
    if(T == NULL)
    {
        return ERROR;
    }

    //利用 LocateNode() 函数定位需要修改的位置
    BiTree target_node = LocateNode(T, e);
    if(target_node == NULL)
    {
        return ERROR;
    }


    //如果找到了相应的位置还需要防止关键字重复！
    BiTree judge_node = LocateNode(T, value.key);
    {
        if(judge_node != NULL && judge_node != target_node)
        {
            return ERROR;
        }
    }

    //如果找到了可以修改的目标位置就修改对应节点
    target_node->data = value;

    return OK;

    /********** End **********/
}

BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //采用递归的方式查找，关键不是找对应 e 的节点，而是对应 e 的节点的父节点，防止节点丢失
    //判断当前节点是否为空，为空那么结束递归
    if(T == NULL)
    {
        return NULL;
    }

    //判断当前节点的左孩子是否为目标节点
    if(T->lchild != NULL && T->lchild->data.key == e)   //程序不能访问不允许访问的内存，所以需要先判定非空才可以访问 T->lchild->data！！
    {
        return T->rchild;    //如果是那么返回右节点
    }

    //判断当前节点的右孩子是否为目标节点
    if(T->rchild != NULL && T->rchild->data.key == e)
    {
        return T->lchild;
    }

    //在当前节点没有找到对应的兄弟节点，那么依次递归左右子树查找
    //递归左子树查找
    BiTree l_target = GetSibling(T->lchild, e);
    if(l_target != NULL)
    {
        return l_target;
    }

    //递归右子树查找
    BiTree r_target = GetSibling(T->rchild, e);
    if(r_target != NULL)
    {
        return r_target;
    }

    //如果都没有找到，返回 NULL
    return NULL;
    /********** End **********/
}

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //首先需要保证关键字不重复
    BiTree judge = LocateNode(T, c.key);
    if(judge != NULL)
    {
        return ERROR;
    }

    //创建新节点 target 指向需要插入的目标值
    BiTree target = NULL;

    //插入根节点
    if(LR == -1)
    {
        //生成新节点
        target = (BiTree)malloc(sizeof(BiTNode));
        target->data = c;
        target->lchild = NULL;
        target->rchild = T; //根不一定是 NULL

        //赋值 target 给 T
        T = target;
        return OK;
    }

    //如果不是根节点那么需要先定位到目标位置
    BiTree node = LocateNode(T, e);
    if(node == NULL)
    {
        //没找到返回 ERROR
        return ERROR;
    }

    //生成新节点
    target = (BiTree)malloc(sizeof(BiTNode));
    target->data = c;
    target->lchild = NULL;
    target->rchild = NULL;

    //开始根据 LR 确定插入位置
    //插入左节点
    if(LR == 0)
    {
        target->rchild = node->lchild;
        node->lchild = target;
        return OK;
    }
    //插入右节点
    else if(LR == 1)
    {
        target->rchild = node->rchild;
        node->rchild = target;
        return OK;
    }
    else
    {
        return ERROR;
    }

    /********** End **********/
}

status DeleteNode(BiTree &T,KeyType e)
//删除结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //递归有两种处理情况，对应出口。第一种是为空；第二种是找到了对应的元素为根
    //同时中间涉及到替换，所以不仅需要找到 e，更关键的是他的父节点
    
    //判断是否为空
    if(T == NULL)
    {
        return ERROR;
    }

    //如果现在的根就是目标
    if(T->data.key == e)
    {

        //判断对应的三种情况
        //1. 节点的度为 0
        if(T->lchild == NULL && T->rchild == NULL)
        {
            //删除根节点
            free(T);
            T = NULL; //防止野指针！！
            return OK;
        }

        //2.1 节点度为 1，只有右节点
        if(T->lchild == NULL && T->rchild != NULL)
        {
            BiTree p = T;
            T = T->rchild;
            free(p);
            return OK;
        }

        //2.2 节点度为 1，只有左节点
        if(T->lchild != NULL && T->rchild == NULL)
        {
            BiTree p = T;
            T = T->lchild;
            free(p);
            return OK;
        }

        //3. 节点度为 2
        if(T->lchild != NULL && T->rchild != NULL)
        {
            BiTree p = T;
            T = T->lchild;

            //使用循环找到最右节点
            BiTree q = T;   //注意此时 T 已经被更新了！！
            while(q->rchild != NULL)
            {
                q = q->rchild;
            }

            q->rchild = p->rchild;
            free(p);
            return OK;
        }
    }

    //如果当前不是对应的节点 e，那么依次递归搜索左右子树
    if(DeleteNode(T->lchild, e) == OK)
    {
        return OK;
    }

    if(DeleteNode(T->rchild, e) == OK)
    {
        return OK;
    }

    return ERROR;
    /********** End **********/
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//先序遍历二叉树 T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //判断 T 是否为空
    if(T == NULL)
    {
        return OK;
    }

    //T 非空的时候进行先序遍历
    if(T)
    {
        //根
        visit(T);
        //左
        PreOrderTraverse(T->lchild, visit);
        //右
        PreOrderTraverse(T->rchild, visit);
    }

    return OK;
    /********** End **********/
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//中序遍历二叉树 T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //非递归实现的整体思路是：首先创建一个栈，向左一路压栈，为空的时候转向右子树

    //定义栈
    BiTree stack[100];
    int top = -1;

    //定义一个遍历指针
    BiTree p = T;
    //当栈非空或者是 p 不是 NULL 的时候就一直循环
    while(p != NULL || top != -1)
    {
        while(p != NULL)
        {
            //当前 p 入栈
            stack[++top] = p;
            //p 向左走
            p = p->lchild;
        }
        
        //此时 p 为空，退栈
        p = stack[top--];
        visit(p);

        //转向右边
        p = p->rchild;
    }

    return OK;
    /********** End **********/
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//后序遍历二叉树 T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //非递归实现这个算法的关键在于记录上一个访问的节点

    //首先定义一个栈
    BiTree stack[100];
    int top = -1;

    //定义一个指针用于遍历
    BiTree p = T;

    //定义一个指针用于记录上一次访问的节点，初始为 NULL
    BiTree last = NULL;

    //当栈非空或者是 p 不是 NULL 的时候就一直循环处理栈
    while(p != NULL || top != -1)
    {
        //一直向左压栈
        while(p != NULL)
        {
            //先入栈
            stack[++top] = p;
            //后访问左边的节点
            p = p->lchild;
        }

        //p 为 NULL 的时候，不是立刻退栈而是查看当前的栈顶元素
        p = stack[top];
        //当右边子树为空或者右边子树刚刚被处理的时候，访问根并弹出栈
        if(p->rchild == NULL || p->rchild == last)
        {
            visit(p);
            last = p;   //注意更新 last
            top--;
            p = NULL;   //此时注意 p 需要置空
        }
        else
        {
            //否则右边还没有处理完成，需要先处理右边
            p = p->rchild;
        }

    }

    return OK;

    /********** End **********/
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树 T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //层序遍历必须使用队列，先进先出，每一次访问一个节点就把他的左右子节点入队

    //首先判断树是否为空
    if(T == NULL)
    {
        return OK;
    }

    //定义一个队列
    BiTree queue[100];
    int front = 0;
    int rear = -1;

    //根节点入队
    queue[++rear] = T;

    //当队列非空就一致循环处理队列
    while(front <= rear)
    {
        //队首元素出队
        BiTree p = queue[front++];
        //访问出队的节点
        visit(p);
        //同时让不为空的左右子树分别按顺序入队
        if(p->lchild != NULL)
        {
            queue[++rear] = p->lchild;
        }
        if(p->rchild != NULL)
        {
            queue[++rear] = p->rchild;
        }
    }

    return OK;
    /********** End **********/
}

void Save(BiTree T, FILE *fp)
{
    //递归实现储存
    //为空的时候加载到文件里面就是空
    if(T == NULL)
    {
        fprintf(fp, "0 null ");
        return;
    }

    //非空时候正常存入
    fprintf(fp, "%d %s ", T->data.key, T->data.others);

    //递归储存左右子树
    Save(T->lchild,fp);
    Save(T->rchild,fp);
}

status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件 FileName 中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    //注意需要保存树的结构，因此需要保存空的地方
    FILE *fp = fopen(FileName, "w");
    if(fp == NULL)
    {
        return ERROR;
    }

    Save(T, fp);

    fclose(fp);     //注意需要关闭文件
    return OK;
    /********** End 1 **********/
}

BiTree Build(FILE *fp)
{
    //先定义临时变量保存读取到的数据
    TElemType temp;
    //如果读取到的不足两个数据，那就是 NULL
    if(fscanf(fp, "%d %s ",&temp.key, temp.others) != 2)
    {
        return NULL;
    }

    //key 为 0 的时候也对应 NULL
    if(temp.key == 0)
    {
        return NULL;
    }

    //创建新节点
    BiTree Node = (BiTree)malloc(sizeof(BiTNode));
    Node->data = temp;
        
    //递归读取左右子树
    Node->lchild = Build(fp);
    Node->rchild = Build(fp);

    //返回根
    return Node;

}

int MaxPathSum(BiTree T)
{
    //初始条件是二叉树 T 存在；操作结果是返回根结点到叶子结点的最大路径和；
    //采用递归的思想：最大的路径和等于当前值加上左右子树的最大路径和中的较大值。递归在节点为空或者是叶子节点没有孩子的时候返回
    
    //1. 节点为空
    if(T == NULL)
    {
        return 0;
    }

    //2. 该节点没有叶子节点
    if(T->lchild == NULL && T->rchild == NULL)
    {
        return T->data.key;
    }

    //3. 该节点有叶子节点
    int left = MaxPathSum(T->lchild);
    int right = MaxPathSum(T->rchild);

    //4. 判断哪个大，那么返回哪个
    if(left > right)
    {
        return left + T->data.key;
    }
    else
    {
        return right + T->data.key;
    }
}

BiTree LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2)
{
    //初始条件是二叉树 T 存在；操作结果是该二叉树中 e1 结点和 e2 结点的最近公共祖先；
    //思路是采用递归，本质上是需要找到 e1 e2 分叉的节点

    //1. 节点为空
    if(T == NULL)
    {
        return NULL;
    }

    //2. 该节点是 e1 或 e2
    if(T->data.key == e1 || T->data.key == e2)
    {
        return T;   //这里返回的不是最后的值，而是向它的父节点说明它是一个 e1 或 e2 的节点
    }

    //3. 这个节点不是空或者是两个元素的任何一个，那么递归左右子树查找
    BiTree left = LowestCommonAncestor(T->lchild, e1, e2);
    BiTree right = LowestCommonAncestor(T->rchild, e1, e2);

    //4. 判断左右子树是否返回了 e1 或 e2
    if(left != NULL && right != NULL)
    {
        return T; //这里才是返回的最后节点，实际上是第一个分叉的位置
    }

    //5. 如果只有左边找到
    if(left != NULL)
    {
        return left;
    }

    //6. 如果只有右边找到
    return right;
}

status InvertTree(BiTree T)
{
    //初始条件是二叉树 T 存在；操作结果是将 T 翻转，使其所有结点的左右结点互换；
    //思路是采用递归的思想，将每个节点的左右子树交换即可
    if(T == NULL)
    {
        return OK;
    }

    //交换左右子树
    BiTree temp = T->rchild;
    T->rchild = T->lchild;
    T->lchild = temp;

    //递归左右子树
    InvertTree(T->lchild);
    InvertTree(T->rchild);

    return OK;
}

status LoadBiTree(BiTree &T,  char FileName[])
//读入文件 FileName 的结点数据，创建二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    FILE *fp = fopen(FileName, "r");
    if(fp == NULL)
    {
        return ERROR;
    }

    T = Build(fp);

    fclose(fp);
    return OK;
    /********** End 2 **********/
}

status AddTree(TreeList &L, char name[], BiTree T)
{
    //判断顺序表是否已满
    if(L.length >= L.listsize)
    {
        return ERROR;
    }

    //判断是否有重名的树
    if(FindTree(L,name) != -1)
    {
        return ERROR;
    }

    //添加树到顺序表
    strcpy(L.elem[L.length].name, name);
    L.elem[L.length].T = T;

    //更新长度
    L.length++;

    return OK;
}

int FindTree(TreeList L, char name[])
{
    //遍历顺序表，查找是否有重名的树
    for(int i = 0; i < L.length; i++)
    {
        if(strcmp(L.elem[i].name, name) == 0)
        {
            return i;
        }
    }
    //如果没有找到，返回 -1
    return -1;

}

status RemoveTree(TreeList &L, char name[])
{
    //先查找对应的树
    int pos = FindTree(L, name);

    //没找到对应的树
    if(pos == -1)
    {
        return ERROR;
    }

    //删除对应的树，释放相应的二叉树空间
    ClearBiTree(L.elem[pos].T);  // 释放二叉树空间

    //为了保持顺序表的连续性，需要将后面的元素前移!!!
    for(int i = pos; i < L.length - 1; i++)
    {
        L.elem[i] = L.elem[i + 1];
    }

    L.length--;  // 顺序表长度减 1

    return OK;
}

status ShowTree(TreeList L)
{
    //首先判断线性表是否为空
    if(L.length == 0)
    {
        printf("No trees to show.\n");
        return OK;
    }

    //遍历顺序表，显示每棵树的信息
    for(int i = 0; i < L.length; i++)
    {
        printf("%d. %s\n", i + 1, L.elem[i].name);
    }

    return OK;
}

int NodeCount(BiTree T)
{
    //判断二叉树是否为空，如果为空则返回 0
    if(T == NULL)
    {
        return 0;
    }

    //递归计算左右子树的节点点数
    int leftCount = NodeCount(T->lchild);
    int rightCount = NodeCount(T->rchild);

    //返回根节点加上左右子树的节点点数
    return 1 + leftCount + rightCount;
}

int LeafCount(BiTree T)
{
    //判断二叉树是否为空，如果为空则返回 0
    if(T == NULL)
    {
        return 0;
    }

    //如果当前是叶子节点
    if(T->lchild == NULL && T->rchild == NULL)
    {
        return 1;  // 叶子节点计数为 1
    }

    //递归计算左右子树的叶子节点数
    int leftLeafCount = LeafCount(T->lchild);
    int rightLeafCount = LeafCount(T->rchild);

    // 返回左右子树的叶子节点数之和
    return leftLeafCount + rightLeafCount;

}

status Getlevel(BiTree T, KeyType e, int &level)
{
    //空树
    if(T == NULL)
    {
        return ERROR;
    }

    //找到了目标节点
    if(T->data.key == e)
    {
        level = 1;
        return OK;
    }

    int l = 0;
    int r = 0;

    //没有找到目标节点，递归查找左右子树
    //递归查找左子树
    if(Getlevel(T->lchild, e, l) == OK)
    {
        level = l + 1;
        return OK;
    }
    //递归查找右子树
    if(Getlevel(T->rchild, e, r) == OK)
    {
        level = r + 1;
        return OK;
    }

    //如果没有找到目标节点，返回 ERROR
    return ERROR;
}

status IsFullBinaryTree(BiTree T)
{
    //判断树是否为空
    if(T == NULL)
    {
        return TRUE;    //空树也是满二叉树
    }
    
    int n = NodeCount(T);
    int h = BiTreeDepth(T);

    //满二叉树的节点数满足 n = 2^h - 1
    if(n == (1 << h) - 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;   
    }

}

status IsCompleteBinaryTree(BiTree T)
{
    //将树转化为对应的'层序遍历'序列，判断出现了 NULL 之后是不是还有 NULL 节点出现，如果有，那么就不是完全二叉树
    //判断树是否为空
    if(T == NULL)
    {
        return TRUE;    //空树也是满二叉树
    }

    //层序遍历二叉树，判断是否满足完全二叉树的条件
    BiTree queue[100];  
    int front = 0;
    int rear = 0;

    queue[rear++] = T;

    //标志位，表示是否遇到了 NULL 节点
    int flag = 0;

    while(front < rear)
    {
        //出队
        BiTree node = queue[front++];

        if(node == NULL)
        {
            //一旦遇到了 NULL 节点，后续的节点都必须是 NULL 节点
            flag = 1;
        }
        else
        {
            //如果之前已经遇到了 NULL 节点，那么说明不是完全二叉树
            if(flag)
            {
                return FALSE;
            }
            //将左右子节点入队
            queue[rear++] = node->lchild;
            queue[rear++] = node->rchild;
        }
    }

    return TRUE;
}

status IsEqual(BiTree T1, BiTree T2)
{
    //还是采用递归比较，先比较当前节点，再递归比较左右子树是否相等
    //判断两棵树是否相等，递归的终止条件是两棵树都为空或者其中一棵树为空
    if(T1 == NULL && T2 == NULL)
    {
        return TRUE;
    }

    if(T1 == NULL || T2 == NULL)
    {
        return FALSE;
    }

    //如果当前节点的值不相等，那么两棵树也不相等
    if(T1->data.key != T2->data.key || strcmp(T1->data.others, T2->data.others) != 0)
    {
        return FALSE;
    }

    //递归比较左右子树
    return IsEqual(T1->lchild, T2->lchild) && IsEqual(T1->rchild, T2->rchild);
}

status FindMax(BiTree T, KeyType &max)
{
    //递归找到二叉树中的最大值
    //判断树是否为空
    if(T == NULL)
    {
        return ERROR;
    }

    //当前节点的值与 max 比较，更新 max
    if(T->data.key > max)
    {
        max = T->data.key;
    }

    //递归比较左右子树
    FindMax(T->lchild, max);
    FindMax(T->rchild, max);

    return OK;
}

status FindMin(BiTree T, KeyType &min)
{
    //递归找到二叉树中的最小值
    //判断树是否为空
    if(T == NULL)
    {
        return ERROR;
    }

    //当前节点的值与 min 比较，更新 min
    if(T->data.key < min)
    {
        min = T->data.key;
    }

    //递归比较左右子树
    FindMin(T->lchild, min);
    FindMin(T->rchild, min);

    return OK;
}

status WidthOfBinaryTree(BiTree T, int &width)
{
    if(T == NULL)
    {
        width = 0;
        return OK;
    }

    //队列模拟层序遍历
    BiTree queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = T;
    
    width = 0;

    while(front < rear)
    {
        //计算当前层的节点数
        int currentWidth = rear - front;
        //判断是否需要更新宽度
        if(currentWidth > width)
        {
            width = currentWidth;
        }
        //处理当前层的节点
        for(int i = 0; i<currentWidth; i++)
        {
            //出队
            BiTree node = queue[front++];
            //将左右子节点入队
            if(node->lchild != NULL)    //注意在入队之前需要先判空
            {
                queue[rear++] = node->lchild;
            }
            if(node->rchild != NULL)
            {
                queue[rear++] = node->rchild;
            }
        }
    }

    return OK;  
}

status NodeDegree(BiTree T, KeyType e, int &degree)
{
    if(T == NULL)
    {
        return FALSE;
    }

    //判断当前节点是否值为 e
    if(T->data.key == e)
    {
        degree = 0;
        if(T->lchild != NULL)
        {
            degree++;
        }
        if(T->rchild != NULL)
        {
            degree++;
        }
        return TRUE;
    }


    int d = 0;

    //递归在左右子树中查找
    if(NodeDegree(T->lchild, e, d) == TRUE)
    {     
        degree = d;
        return TRUE;
    }
    if(NodeDegree(T->rchild, e, d) == TRUE)
    {
        degree = d;
        return TRUE;
    }

    return FALSE;
}

status GetDistance(BiTree T, KeyType e1, KeyType e2, int &distance)
{
    //关键在于利用：距离 = e1 → LCA + LCA → e2
    //判空
    if(T == NULL)
    {
        return ERROR;
    }

    int d1 = 0;
    int d2 = 0;

    //求深度
    if(Getlevel(T, e1, d1) == ERROR || Getlevel(T, e2, d2) == ERROR)    //这个代表节点不存在
    {
        return ERROR;
    }

    //求 LCA
    BiTree lca = LowestCommonAncestor(T, e1, e2);
    if(lca == NULL)
    {
        return ERROR;
    }

    int dlca = 0;
    Getlevel(T, lca->data.key, dlca);

    //计算距离
    distance = (d1 - dlca) + (d2 - dlca);

    return OK;
}

BiTree BuildFromPreIn(TElemType pre[], TElemType in[], int len)
{
    if(len <= 0)
    {
        return NULL;
    }

    //创建根节点，先序第一个
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = pre[0];
    root->lchild = NULL;
    root->rchild = NULL;

    //在中序中找到根的位置
    int rootIndex = 0;
    for(int i = 0; i < len; i++)    
    {
        if(in[i].key == pre[0].key)
        {
            rootIndex = i;
            break;
        }
    }

    //左子树长度
    int leftLen = rootIndex;
    //右子树长度
    int rightLen = len - 1 - rootIndex;

    //递归构建左子树和右子树
    root->lchild = BuildFromPreIn(pre + 1, in, leftLen);
    root->rchild = BuildFromPreIn(pre + 1 + leftLen, in + 1 + leftLen, rightLen);   //关键在于定位出来右子树的位置！！！//同时存在指针加减移动

    return root;
}

BiTree BuildFromPostIn(TElemType post[], TElemType in[], int len)
{
    if(len <= 0)
    {
        return NULL;
    }

    //创建根节点，后序最后一个
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = post[len - 1];
    root->lchild = NULL;
    root->rchild = NULL;

    //在中序中找到根的位置
    int rootIndex = 0;
    for(int i = 0; i < len; i++)    
    {
        if(in[i].key == post[len - 1].key)
        {
            rootIndex = i;
            break;
        }
    }

    //左子树长度
    int leftLen = rootIndex;
    //右子树长度
    int rightLen = len - 1 - rootIndex;

    //递归构建左子树和右子树
    root->lchild = BuildFromPostIn(post, in, leftLen);
    root->rchild = BuildFromPostIn(post + leftLen, in + 1 + leftLen, rightLen);   //关键在于定位出来右子树的位置！！！//同时存在指针加减移动

    return root;
}

BiTree BuildFromLevelIn(TElemType level[], TElemType in[], int len)
{
    if(len <= 0)
    {
        return NULL;
    }

    //创建根节点，层序第一个
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = level[0];
    root->lchild = NULL;
    root->rchild = NULL;

    //在中序中找到根的位置
    int rootIndex = 0;
    for(int i = 0; i < len; i++)    
    {
        if(in[i].key == level[0].key)
        {
            rootIndex = i;
            break;
        }
    }

    //构造左右子树的中序，利用中序和层序递归求解
    TElemType leftIn[100];
    TElemType rightIn[100];
    int leftLen = 0;
    int rightLen = 0;

    for(int i = 0; i < len; i++)
    {
        if(i < rootIndex)
        {
            leftIn[leftLen++] = in[i];
        }
        else if(i > rootIndex)
        {
            rightIn[rightLen++] = in[i];
        }
    }

    //构造左右子树的层序
    TElemType leftLevel[100];
    TElemType rightLevel[100];
    int l = 0;
    int r = 0;

    for(int i = 1; i < len; i++)   //从第二个开始，因为第一个是根节点
    {
        // 检查是否属于左子树
        int found = 0;
        for(int j = 0; j < leftLen; j++)
        {
            if(level[i].key == leftIn[j].key)
            {
                leftLevel[l++] = level[i];
                found = 1;
                break;
            }
        }
        if(found) continue;
        // 检查是否属于右子树
        for(int j = 0; j < rightLen; j++)
        {
            if(level[i].key == rightIn[j].key)
            {
                rightLevel[r++] = level[i];
                break;
            }
        }
    }

    //递归构造左子树和右子树
    root->lchild = BuildFromLevelIn(leftLevel, leftIn, leftLen);
    root->rchild = BuildFromLevelIn(rightLevel, rightIn, rightLen);

    return root;
}

// 辅助函数实现
void PrintNode(BiTree T)
// 遍历时的访问函数：打印节点信息
{
    /********** Begin *********/
    if(T != NULL)
    {
        printf("%d(%s) ", T->data.key, T->data.others);
    }
    /********** End **********/
}

void InitTreeManager()
// 初始化树管理器
{
    /********** Begin *********/
    TreeManager.length = 0;
    TreeManager.listsize = 15;
    currentTreeIdx = -1;
    for(int i = 0; i < 15; i++)
    {
        TreeManager.elem[i].name[0] = '\0';
        TreeManager.elem[i].T = NULL;
    }
    /********** End **********/
}

BiTree& GetCurrentTree()
// 获取当前操作的树引用
{
    /********** Begin *********/
    if(currentTreeIdx >= 0 && currentTreeIdx < TreeManager.length)
    {
        return TreeManager.elem[currentTreeIdx].T;
    }
    static BiTree dummy = NULL;
    return dummy;
    /********** End **********/
}
