/* 基于邻接表的图实现演示系统 - 数据结构实验4 */
/*作者：彭婉茹（U202514699）*/
/*---- 头文件的申明 ----*/
#include<stdio.h>
#include<stdlib.h>
#include "string.h"

/*---- 预定义 ----*/
// 定义布尔类型TRUE和FALSE
#define TRUE 1
#define FALSE 0

// 定义函数返回值类型
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define INFINITY 999999  // 定义无穷大（用于网）

// 定义数据元素类型
typedef int ElemType;
typedef int status;
typedef int KeyType;
typedef enum {DG,DN,UDG,UDN} GraphKind;

//定义顶点类型，包含关键字和其他信息
typedef struct {
    KeyType key; //关键字
    char others[20]; //其他信息
} VertexType;

//定义邻接表结点类型
typedef struct ArcNode {
    int adjvex; //顶点在顶点数组中的下标
    int weight; //边的权值（用于网）
    struct ArcNode *nextarc; //指向下一个结点的指针
} ArcNode;

//定义头结点类型和数组类型（头结点和边表构成一条链表）
typedef struct VNode{
    VertexType data; //顶点信息
    ArcNode *firstarc; //指向第一条弧的指针
} VNode,AdjList[MAX_VERTEX_NUM];

//定义邻接表类型，包含头结点数组、顶点数、弧数和图的类型
typedef struct {
    AdjList vertices; //头结点数组
    int vexnum,arcnum; //顶点数和弧数
    GraphKind kind; //图的类型（有向图、无向图等）
} ALGraph;

//定义图集合类型，包含一个结构体数组，每个结构体包含图的名称和邻接表
typedef struct {
    struct {
        char name[30]; //图的名称
        ALGraph G; //对应的邻接表
    }elem[30]; //图的个数
    int length; //图集合中图的数量
}Graphs;

Graphs graphs;  //图的集合的定义
int currentGraphIdx = -1;  // 当前操作的图索引

//基本函数声明
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]);  // 创建图
status DestroyGraph(ALGraph &G);  // 销毁图
int LocateVex(ALGraph G,KeyType u);  // 查找顶点
status PutVex(ALGraph &G,KeyType u,VertexType value);  // 顶点赋值
int FirstAdjVex(ALGraph G,KeyType u);  // 获得第一邻接点
int NextAdjVex(ALGraph G,KeyType v,KeyType w);  // 获得下一邻接点
status InsertVex(ALGraph &G,VertexType v);  // 插入顶点
status DeleteVex(ALGraph &G,KeyType v);  // 删除顶点
status InsertArc(ALGraph &G,KeyType v,KeyType w);  // 插入弧
status DeleteArc(ALGraph &G,KeyType v,KeyType w);  // 删除弧
status DFSTraverse(ALGraph &G,void (*visit)(VertexType));  // 深度优先搜索遍历
status BFSTraverse(ALGraph &G, void (*visit)(VertexType));  // 广度优先搜索遍历

//附加功能函数声明
status VerticesSetLessThanK(ALGraph G, KeyType v, int k);  // 距离小于k的顶点集合
int ShortestPathLength(ALGraph G, KeyType v, KeyType w);  // 顶点间最短路径长度
int ConnectedComponentsNums(ALGraph G);  // 图的连通分量个数
status SaveGraph(ALGraph G, char FileName[]);  // 保存图到文件
status LoadGraph(ALGraph &G, char FileName[]);  // 从文件加载图

// 新增算法函数声明
int HasCycle(ALGraph G);  // 判断是否有环
status MST_Prim(ALGraph G, KeyType start);  // Prim算法求最小生成树
status MST_Kruskal(ALGraph G);  // Kruskal算法求最小生成树
int Degree(ALGraph G, KeyType v);  // 顶点度数（无向图）
int GetVerticesCount(ALGraph G);  // 返回顶点数
int GetEdgesCount(ALGraph G);  // 返回边数
status DisplayGraph(ALGraph G);  // 展示图的邻接表
status IsReachable(ALGraph G, KeyType v, KeyType w);  // 判断v到w是否存在路径

//图管理函数声明
status AddGraph(Graphs &L, char name[]);  // 添加图
status RemoveGraph(Graphs &L, char name[]);  // 移除图
int FindGraph(Graphs L, char name[]);  // 查找图
status ShowGraph(Graphs L);  // 显示所有图

//辅助函数声明
const char* GraphKindStr(GraphKind kind);  // 图类型转字符串
void PrintVertex(VertexType v);  // 打印顶点
void InitGraphManager();  // 初始化图管理器
ALGraph& GetCurrentGraph();  // 获取当前图

status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //整体思路是先建立顶点，在建立边，主要是将G的每个成员都正确赋值

    //首先定义图的类型
    G.kind = UDG;

    //初始化顶点数和弧数
    G.vexnum = 0;
    G.arcnum = 0;

    //数组的初始检查
    if(V[0].key == -1 || (V[1].key == -1 && VR[0][0] != -1))
    {
        return ERROR;
    }

    //初始化做好之后进行顶点数组的建立
    for(int i=0; V[i].key != -1; i++)   //以-1收尾
    {
        //判断是否溢出
        if(i >= MAX_VERTEX_NUM)
        {
            return ERROR;
        }

        //判断是否有重复的关键字
        for(int j=0; j<i; j++)
        {
            if(V[j].key == V[i].key)
            {
                return ERROR;
            }
        }

        //保存顶点
        G.vertices[i].data = V[i];
        G.vertices[i].firstarc = NULL;  //因为这里还没有建立第一条弧所以先置空
        //更新顶点数
        G.vexnum++;
    }

    //顶点数组建立好之后开始建立弧，主要是找到弧 V1->V2 对应的两个相关顶点
    //首先遍历弧数组
    for(int i=0;; i++) //i来控制顶点的数目
    {
        // 正常结束
        if(VR[i][0] == -1 && VR[i][1] == -1)
        {
            break;
        }

        // 非法关系对
        if(VR[i][0] == -1 || VR[i][1] == -1)
        {
            return ERROR;
        }
        
        int v1 = -1;
        int v2 = -1;

        //扫描图，进行匹配
        for(int j = 0; j<G.vexnum; j++)
        {
            if(G.vertices[j].data.key == VR[i][0])  //注意是VR[i][0]对应头节点
            {
                v1 = j; //此处直接使用对应的序号相当于编号
            }

            if(G.vertices[j].data.key == VR[i][1])
            {
                v2 = j;
            }
        }

        //如果有不存在的顶点
        if(v1 == -1 || v2 == -1)
        {
            return ERROR;
        }

        //忽略自环边
        if(v1 == v2)
        {
            return ERROR;  
        }

        //找到对应的v1和v2之后，进行弧的建立
        //首先进行去重,判断v1->v2这一条边是否已经存在
        ArcNode *p; 
        int is_exist = 0;

        //检查V1->v2
        p = G.vertices[v1].firstarc;
        
        while(p)    //非空时扫描该节点的子链表
        {
            if(p->adjvex == v2)
            {
                is_exist = 1;
                break;
            }
            p = p->nextarc;
        }

        //检查V2->V1
        p = G.vertices[v2].firstarc;
        while(p)    //非空时扫描该节点的子链表
        {
            if(p->adjvex == v1)
            {
                is_exist = 1;
                break;
            }
            p = p->nextarc;
        }

        if(is_exist)    //查重成功那么返回错误
        {
            return ERROR;  
        }

        //所有检查通过后，再更新弧数
        G.arcnum++;

        //现在进行头插法插入相关节点
        //插入V1->v2
        //首先创建相关节点
        ArcNode *s1;
        s1 = (ArcNode*)malloc(sizeof(ArcNode));
        s1->adjvex = v2;
        //首插法
        s1->nextarc = G.vertices[v1].firstarc;
        G.vertices[v1].firstarc = s1;

        //插入V2->V1
        ArcNode *s2;
        s2 = (ArcNode*)malloc(sizeof(ArcNode));
        s2->adjvex = v1;

        s2->nextarc = G.vertices[v2].firstarc;
        G.vertices[v2].firstarc = s2;
    }
    return OK;
    /********** End **********/
}

status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //遍历每一个表头节点
    for(int i=0; i<G.vexnum; i++)
    {
        //保存第一条弧指针的位置
        ArcNode *p = G.vertices[i].firstarc;
        //将头节点的弧置空
        G.vertices[i].firstarc = NULL;
        //扫描所有的弧
        while(p)
        {
            ArcNode *temp = p;
            p = p->nextarc;
            free(temp);
        }
    }

    G.vexnum = 0;
    G.arcnum = 0;

    return OK;
    /********** End **********/
}

int LocateVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //扫描顶点数组
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data.key == u)
        {
            return i;
        }
    }
    return -1;
    /********** End **********/
}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //扫描顶点
    int is_found=0; //标记是否找到对应的顶点 
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data.key == u)
        {
            is_found = 1;
            for(int j=0; j<G.vexnum; j++)   //去重处理
            {
                if(G.vertices[j].data.key == value.key && j != i)
                {
                    return ERROR;
                }
            }
            G.vertices[i].data = value; //整体赋值
            break;
        }
    }
    if(!is_found)
    {
        return ERROR;
    }
    return OK;
    /********** End **********/
}

int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //扫描顶点数组
    int pos = -1;

    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data.key == u) 
        {
            pos = i;
            break;
        }
    }

    //如果没有找到相应的值或者是没有邻接点
    if(pos == -1 || G.vertices[pos].firstarc == NULL)
    {
        return -1;
    }

    return G.vertices[pos].firstarc->adjvex;
    /********** End **********/
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //扫描顶点数组,定位v
    int is_foundv = 0;
    int i;
    for(i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            is_foundv = 1;
            break;
        }
    }

    //没有找到对应的v顶点
    if(!is_foundv)
    {
        return -1;
    }

    //扫描顶点数组，定位w
    int is_foundw = 0;
    int j;
    for(j = 0; j<G.vexnum; j++)
    {
        if(G.vertices[j].data.key == w)
        {
            is_foundw = 1;
            break;
        }
    }

    //没有找到对应的w顶点
    if(!is_foundw)
    {
        return -1;
    }

    //扫描表头节点对应的表节点，定位w
    ArcNode *p = G.vertices[i].firstarc;
    if(!p)
    {
        return -1;
    }
    while(p)
    {
        if(p->adjvex == j)
        {
            if(p->nextarc == NULL)
            {
                return -1;
            }
            return p->nextarc->adjvex;
        }
        p = p->nextarc;
    }

    //遍历完了都没找到
    return -1;
    /********** End **********/
}

status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //注意V是顶点；

    //判断顶点个数是否已满
    if(G.vexnum >= MAX_VERTEX_NUM)
    {
        return ERROR;
    }

    //判断关键字是否重复
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v.key)
        {
            return ERROR;
        }
    }

    //插入节点
    G.vertices[G.vexnum].data = v;
    G.vertices[G.vexnum].firstarc = NULL;   //此时注意数组的逻辑序号和个数之间的关系
    G.vexnum++;

    //插入成功返回OK
    return OK;
    /********** End **********/
}

status DeleteVex(ALGraph &G,KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int k = -1;

    //查找顶点位置
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            k = i;
            break;
        }
    }

    //没有查找到
    if(k == -1)
    {
        return ERROR;
    }

    if(G.vexnum == 1)
    {
        return ERROR;
    }

    int delArc = 0;
    ArcNode *p, *q; //设置两个弧指针

    //删除其他顶点中指向k的边
    for(int i=0; i<G.vexnum; i++)
    {
        if(i == k) continue;
        p = G.vertices[i].firstarc;
        q = NULL;

        while(p)
        {
            if(p->adjvex == k)
            {
                //可能需要修改头节点所以需要讨论是否为头节点，不可以直接将头节点free掉了！
                if(q)
                {
                    q->nextarc = p->nextarc;
                }
                else
                {
                    G.vertices[i].firstarc = p->nextarc;
                }

                ArcNode *tmp = p;
                p = p->nextarc;
                free(tmp);

                //更新删除边的计数
                delArc++;
            }
            else
            {
                q = p;
                p = p->nextarc;
            }
        }
    }

    //删除顶点k自己的邻接表
    p = G.vertices[k].firstarc;
    while(p)
    {
        ArcNode *tmp = p;
        p = p->nextarc;
        free(tmp);
    }

    //调整所有邻接点编号
    for(int i = 0; i<G.vexnum; i++)
    {
        if(i == k) continue;

        p = G.vertices[i].firstarc;
        while(p)
        {
            if(p->adjvex > k)
            {
                p->adjvex--;
            }
            p = p->nextarc;
        }
    }

    //删除之后需要顶点数组前移
    for(int i = k; i<G.vexnum-1; i++)
    {
        G.vertices[i] = G.vertices[i+1];
    }

    G.vexnum--;

    //更新边数
    G.arcnum -= delArc;

    return OK;
    /********** End **********/
}

status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int iv = -1, iw = -1;

    //开始查找两个顶点的位置
    for(int i = 0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            iv = i;
        }
        if(G.vertices[i].data.key == w)
        {
            iw = i;
        }
    }

    //判断顶点不存在的情况
    if(iv == -1 || iw == -1)
    {
        return ERROR;
    }

    //检查边是否存在
    ArcNode *p = G.vertices[iv].firstarc;
    while(p)
    {
        if(p->adjvex == iw)
        {
            return ERROR;
        }
        p = p->nextarc;
    }

    //首插法插入 iv->iw
    ArcNode *s = (ArcNode *)malloc(sizeof(ArcNode));
    s->adjvex = iw;
    s->weight = 0;  // 初始化权值为0
    s->nextarc = G.vertices[iv].firstarc;
    G.vertices[iv].firstarc = s;

    //无向图中还需要插入iw->iv
    ArcNode *t = (ArcNode *)malloc(sizeof(ArcNode));
    t->adjvex = iv;
    t->weight = 0;  // 初始化权值为0
    t->nextarc = G.vertices[iw].firstarc;
    G.vertices[iw].firstarc = t;

    //更新弧的总数
    G.arcnum++;

    //插入成功返回OK
    return OK;
    /********** End **********/
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int iv = -1, iw = -1;

    //查找顶点位置
    for(int i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            iv = i;
        }
        if(G.vertices[i].data.key == w)
        {
            iw = i;
        }
    }

    //如果顶点不存在
    if(iv == -1|| iw == -1)
    {
        return ERROR;
    }

    ArcNode *p, *q;
    int found =0;

    //删除iv->iw
    p = G.vertices[iv].firstarc;
    q = NULL;

    while(p)
    {
        if(p->adjvex == iw)
        {
            if(q)
            {
                q->nextarc = p->nextarc;
            }
            else
            {
                G.vertices[iv].firstarc = p->nextarc;
            }
            free(p);
            found = 1;
            break;
        }

        q = p;
        p = p->nextarc;
    }

    if(!found)
    return ERROR;

    //删除iw->iv
    p = G.vertices[iw].firstarc;
    q = NULL;

    while(p)
    {
        if(p->adjvex == iv)
        {
            if(q)
            {
                q->nextarc = p->nextarc;
            }
            else
            {
                G.vertices[iw].firstarc = p->nextarc;
            }
            free(p);
            break;
        }
        q = p;
        p = p->nextarc;
    }

    //更新节点数目
    G.arcnum--;

    return OK;

    /********** End **********/
}

int visited[MAX_VERTEX_NUM];

void DFS(ALGraph &G, int v, void (*visit)(VertexType))
{
    visited[v] = 1;

    visit(G.vertices[v].data);

    ArcNode *p = G.vertices[v].firstarc;

    while(p)
    {
        //每一个输入的都是顶点，所以可以访问表节点实现DFS
        if(!visited[p->adjvex])
        {
            DFS(G, p->adjvex, visit);
        }

        p = p->nextarc;
    }
}

status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    
    //首先对于每一个顶点进行初始化
    for(int i = 0; i<G.vexnum; i++)
    {
        visited[i] = 0;
    }
    for(int i = 0; i<G.vexnum; i++)
    {
        if(!visited[i])
        {
            DFS(G,i,visit);
        }
    }

    return OK;
    /********** End **********/
}

status BFSTraverse(ALGraph &G, void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    //首先定义一个队列
    int Q[MAX_VERTEX_NUM];
    int front = 0;
    int rear = 0;
    
    //首先标记访问数组
    int visited_bfs[MAX_VERTEX_NUM] = {0};
    
    //扫描顶点
    for(int i=0; i<G.vexnum; i++)
    {
        if(!visited_bfs[i])
        {
            //访问节点
            visit(G.vertices[i].data);
            visited_bfs[i] = 1;

            //首节点入队
            Q[rear++] = i;

            //现在对队列进行处理
            while(front < rear)//对应队列非空
            {
                //先出队
                int u = Q[front++];
                //访问u的邻接点,需要扫描指针
                ArcNode *p = G.vertices[u].firstarc;
                while(p)
                {
                    if(!visited_bfs[p->adjvex])
                    {
                        visit(G.vertices[p->adjvex].data);
                        visited_bfs[p->adjvex] = 1;
                        //邻接点入队
                        Q[rear++] = p->adjvex;
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    return OK;
}

status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    FILE * fp = fopen(FileName,"w");  //打开文件，只可写入
    if(fp == NULL)
    {
        return ERROR;  //如果无法打开文件，返回错误
    }

    //先写入 顶点数、边数 和 图的类型
    fprintf(fp,"%d %d %d\n",G.vexnum,G.arcnum,G.kind);  //写入顶点数、边数和图的类型
    // 再写入顶点
    for(int k = 0;k<G.vexnum;k++)   //遍历每一个顶点
    {
        fprintf(fp,"%d %s\n",G.vertices[k].data.key,G.vertices[k].data.others);  //写入顶点的key和others
    }
    //下面输入每个结点对应的边

    for(int i = 0;i< G.vexnum ;i++)  //遍历每一个结点
    {
        ArcNode * p = G.vertices[i].firstarc;  //从顶点的第一条边开始遍历
        while (p)
        {
            fprintf(fp,"%d ",p->adjvex);  //写入边的邻接点编号
            p = p->nextarc;  //遍历下一条边
        }
        fprintf(fp,"-1\n");  //一条边结束后写入-1
    }

    fclose(fp);  //关闭文件
    return OK;  //返回成功

    /********** End 1 **********/
}

status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    FILE *fp = fopen(FileName,"r");  //打开文件，只可读取

    if(fp == NULL)
    {
        return ERROR;  //如果无法打开文件，返回错误
    }

    int graphKind;
    fscanf(fp,"%d %d %d\n",&G.vexnum,&G.arcnum,&graphKind);  //读取顶点数、边数和图的类型
    G.kind = (GraphKind)graphKind;

    //先对顶点进行建立
    for(int i = 0;i<G.vexnum ;i++)  //遍历每一个顶点
    {
        fscanf(fp,"%d %s\n",&G.vertices[i].data.key,G.vertices[i].data.others);  //读取顶点的key和others
        G.vertices[i].firstarc = NULL;  //顶点的第一条边先初始化为NULL
    }

    for(int k = 0;k<G.vexnum ;k++)  //遍历每一个结点
    {
        ArcNode *p = G.vertices[k].firstarc;  //从顶点的第一条边开始遍历

        ArcNode *newnode = (ArcNode *)malloc(sizeof(ArcNode));  //新建一个结点
        fscanf(fp,"%d ",&newnode->adjvex);  //读取新结点的邻接点编号
        newnode->nextarc = NULL;  //将新结点的下一条边设为NULL
        while (newnode->adjvex != -1)  //如果读取的邻接点编号不是-1
        {
            if(G.vertices[k].firstarc == NULL)  //如果当前顶点的第一条边为NULL
            {
                G.vertices[k].firstarc = newnode;  //将新结点设为该顶点的第一条边
                p = G.vertices[k].firstarc;  //令p指向该顶点的第一条边
            }
            else{
                p->nextarc = newnode;  //将新结点接到p指向的边的后面
                p = newnode;  //令p指向新结点
            }
            newnode = (ArcNode * ) malloc(sizeof(ArcNode));   //新建一个结点
            fscanf(fp,"%d ",&newnode->adjvex);  //读取新结点的邻接点编号
            newnode->nextarc = NULL;  //将新结点的下一条边设为NULL
        }

    }

    fclose(fp);  //关闭文件

    return OK;  //返回成功

    /********** End 2 **********/
}

// 图的类型的字符串表示
const char* GraphKindStr(GraphKind kind)
//返回图类型的字符串表示
{
    switch(kind)
    {
        case DG:  return "DG(Directed)";
        case DN:  return "DN(Directed-Net)";
        case UDG: return "UDG(Undirected)";
        case UDN: return "UDN(Undirected-Net)";
        default:  return "Unknown";
    }
}

// 打印顶点信息
void PrintVertex(VertexType v)
//访问顶点v，输出顶点信息
{
    printf("%d(%s) ", v.key, v.others);
}

// 初始化图管理器
void InitGraphManager()
//初始化图集合，将length置0
{
    graphs.length = 0;
    for(int i = 0; i < 30; i++)
    {
        strcpy(graphs.elem[i].name, "0");
        graphs.elem[i].G.vexnum = 0;
        graphs.elem[i].G.arcnum = 0;
    }
}

// 获取当前操作的图
ALGraph& GetCurrentGraph()
//返回当前正在操作的图的引用
{
    static ALGraph emptyGraph;
    emptyGraph.vexnum = 0;
    emptyGraph.arcnum = 0;
    
    if(currentGraphIdx >= 0 && currentGraphIdx < graphs.length)
        return graphs.elem[currentGraphIdx].G;
    
    return emptyGraph;
}

// 添加图
status AddGraph(Graphs &L, char name[])
//在图集合中添加新图，成功返回OK，失败返回ERROR
{
    // 检查是否已满
    if(L.length >= 30)
        return ERROR;
    
    // 检查名称是否重复
    for(int i = 0; i < L.length; i++)
    {
        if(strcmp(L.elem[i].name, name) == 0)
            return ERROR;
    }
    
    // 添加新图
    strcpy(L.elem[L.length].name, name);
    L.elem[L.length].G.vexnum = 0;
    L.elem[L.length].G.arcnum = 0;
    L.length++;
    
    return OK;
}

// 移除图
status RemoveGraph(Graphs &L, char name[])
//从图集合中移除指定名称的图，成功返回OK，失败返回ERROR
{
    int pos = -1;
    
    // 查找图的位置
    for(int i = 0; i < L.length; i++)
    {
        if(strcmp(L.elem[i].name, name) == 0)
        {
            pos = i;
            break;
        }
    }
    
    if(pos == -1)
        return ERROR;
    
    // 销毁图
    DestroyGraph(L.elem[pos].G);
    
    // 前移后续元素
    for(int i = pos; i < L.length - 1; i++)
    {
        L.elem[i] = L.elem[i + 1];
    }
    
    L.length--;
    strcpy(L.elem[L.length].name, "0");
    
    return OK;
}

// 查找图
int FindGraph(Graphs L, char name[])
//在图集合中查找指定名称的图，找到返回位置，否则返回-1
{
    for(int i = 0; i < L.length; i++)
    {
        if(strcmp(L.elem[i].name, name) == 0)
            return i;
    }
    return -1;
}

// 显示所有图
status ShowGraph(Graphs L)
//显示图集合中所有图的信息
{
    printf("\n  => All graphs in collection:\n");
    if(L.length == 0)
    {
        printf("  => No graphs exist.\n");
        return ERROR;
    }
    
    for(int i = 0; i < L.length; i++)
    {
        printf("  [%d] Name: %s, Type: %s, Vertices: %d, Arcs: %d\n",
               i + 1, L.elem[i].name, GraphKindStr(L.elem[i].G.kind),
               L.elem[i].G.vexnum, L.elem[i].G.arcnum);
    }
    
    return OK;
}

// 距离小于k的顶点集合
status VerticesSetLessThanK(ALGraph G, KeyType v, int k)
//返回与顶点v距离小于k的顶点集合，成功返回OK，失败返回ERROR
{
    // 查找顶点v的位置
    int start = -1;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            start = i;
            break;
        }
    }
    
    if(start == -1)
    {
        printf("  => Vertex %d not found!\n", v);
        return ERROR;
    }
    
    // BFS计算最短距离
    int dist[MAX_VERTEX_NUM];
    int Q[MAX_VERTEX_NUM];
    int front = 0, rear = 0;
    
    // 初始化距离数组
    for(int i = 0; i < G.vexnum; i++)
        dist[i] = -1;
    
    dist[start] = 0;
    Q[rear++] = start;
    
    while(front < rear)
    {
        int u = Q[front++];
        
        ArcNode *p = G.vertices[u].firstarc;
        while(p)
        {
            if(dist[p->adjvex] == -1)
            {
                dist[p->adjvex] = dist[u] + 1;
                if(dist[p->adjvex] < k)
                    Q[rear++] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    
    // 输出距离小于k的顶点
    printf("  => Vertices with distance < %d from %d:\n", k, v);
    int found = 0;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(dist[i] >= 0 && dist[i] < k)
        {
            printf("    %d(%s) [dist=%d]\n", G.vertices[i].data.key, G.vertices[i].data.others, dist[i]);
            found = 1;
        }
    }
    
    if(!found)
        printf("  => No vertices found.\n");
    
    return OK;
}

// 顶点间最短路径长度
int ShortestPathLength(ALGraph G, KeyType v, KeyType w)
//返回顶点v与顶点w的最短路径长度，如果不可达返回-1
{
    // 查找两个顶点的位置
    int start = -1, end = -1;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
            start = i;
        if(G.vertices[i].data.key == w)
            end = i;
    }
    
    if(start == -1 || end == -1)
        return -1;
    
    if(start == end)
        return 0;
    
    // BFS求最短路径
    int dist[MAX_VERTEX_NUM];
    int Q[MAX_VERTEX_NUM];
    int front = 0, rear = 0;
    
    for(int i = 0; i < G.vexnum; i++)
        dist[i] = -1;
    
    dist[start] = 0;
    Q[rear++] = start;
    
    while(front < rear)
    {
        int u = Q[front++];
        
        if(u == end)
            return dist[end];
        
        ArcNode *p = G.vertices[u].firstarc;
        while(p)
        {
            if(dist[p->adjvex] == -1)
            {
                dist[p->adjvex] = dist[u] + 1;
                Q[rear++] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    
    return -1;  // 不可达
}

// 连通分量计数
int ConnectedComponentsNums(ALGraph G)
//返回图G的连通分量个数
{
    int visited_cc[MAX_VERTEX_NUM] = {0};
    int count = 0;
    int Q[MAX_VERTEX_NUM];
    
    for(int i = 0; i < G.vexnum; i++)
    {
        if(!visited_cc[i])
        {
            count++;
            
            // BFS遍历一个连通分量
            int front = 0, rear = 0;
            visited_cc[i] = 1;
            Q[rear++] = i;
            
            while(front < rear)
            {
                int u = Q[front++];
                
                ArcNode *p = G.vertices[u].firstarc;
                while(p)
                {
                    if(!visited_cc[p->adjvex])
                    {
                        visited_cc[p->adjvex] = 1;
                        Q[rear++] = p->adjvex;
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    
    return count;
}

// 判断是否有环
int HasCycle(ALGraph G)
// 判断图G中是否存在环，存在返回1，否则返回0
{
    int visited[MAX_VERTEX_NUM] = {0};
    int parent[MAX_VERTEX_NUM];
    int Q[MAX_VERTEX_NUM];
    
    for(int i = 0; i < G.vexnum; i++)
    {
        if(!visited[i])
        {
            // BFS检测环
            int front = 0, rear = 0;
            visited[i] = 1;
            parent[i] = -1;
            Q[rear++] = i;
            
            while(front < rear)
            {
                int u = Q[front++];
                
                ArcNode *p = G.vertices[u].firstarc;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        visited[p->adjvex] = 1;
                        parent[p->adjvex] = u;
                        Q[rear++] = p->adjvex;
                    }
                    else if(p->adjvex != parent[u])
                    {
                        // 找到已访问的邻接点且不是父节点，说明有环
                        return 1;
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    
    return 0;
}

// Prim算法求最小生成树
status MST_Prim(ALGraph G, KeyType start)
// 使用Prim算法从start顶点开始构造最小生成树
{
    if(G.kind != UDN)
    {
        printf("  => Prim algorithm is only for Undirected Network.\n");
        return ERROR;
    }
    
    int startIdx = -1;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == start)
        {
            startIdx = i;
            break;
        }
    }
    
    if(startIdx == -1)
    {
        printf("  => Vertex %d not found.\n", start);
        return ERROR;
    }
    
    int lowcost[MAX_VERTEX_NUM];  // 最小权值
    int adjvex[MAX_VERTEX_NUM];   // 对应的顶点
    int visited_mst[MAX_VERTEX_NUM] = {0};
    
    // 初始化
    for(int i = 0; i < G.vexnum; i++)
    {
        lowcost[i] = INFINITY;
        adjvex[i] = -1;
    }
    
    lowcost[startIdx] = 0;
    
    printf("  => MST (Prim) starting from %d:\n", start);
    int totalWeight = 0;
    int u;  // 声明在外层
    
    for(int i = 0; i < G.vexnum; i++)
    {
        // 选择最小权值的顶点
        int min = INFINITY;
        u = -1;
        for(int j = 0; j < G.vexnum; j++)
        {
            if(!visited_mst[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                u = j;
            }
        }
        
        if(u == -1)
        {
            printf("  => Graph is not connected.\n");
            return ERROR;
        }
        
        visited_mst[u] = 1;
        
        if(adjvex[u] != -1)
        {
            printf("    Edge: %d(%s) -- %d(%s), weight: %d\n",
                   G.vertices[adjvex[u]].data.key, G.vertices[adjvex[u]].data.others,
                   G.vertices[u].data.key, G.vertices[u].data.others,
                   lowcost[u]);
            totalWeight += lowcost[u];
        }
        
        // 更新lowcost
        ArcNode *p = G.vertices[u].firstarc;
        while(p)
        {
            int v = p->adjvex;
            if(!visited_mst[v] && p->weight < lowcost[v])
            {
                lowcost[v] = p->weight;
                adjvex[v] = u;
            }
            p = p->nextarc;
        }
    }
    
    printf("  => Total weight: %d\n", totalWeight);
    return OK;
}

// Kruskal算法求最小生成树
// 边结构
typedef struct {
    int u, v;
    int weight;
} Edge;

// 并查集查找
int FindSet(int parent[], int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = FindSet(parent, parent[x]);
}

// 并查集合并
void UnionSet(int parent[], int x, int y)
{
    int rootX = FindSet(parent, x);
    int rootY = FindSet(parent, y);
    if(rootX != rootY)
        parent[rootX] = rootY;
}

status MST_Kruskal(ALGraph G)
// 使用Kruskal算法构造最小生成树
{
    if(G.kind != UDN)
    {
        printf("  => Kruskal algorithm is only for Undirected Network.\n");
        return ERROR;
    }
    
    // 收集所有边
    Edge edges[MAX_VERTEX_NUM * MAX_VERTEX_NUM];
    int edgeCount = 0;
    
    for(int i = 0; i < G.vexnum; i++)
    {
        ArcNode *p = G.vertices[i].firstarc;
        while(p)
        {
            // 只添加u < v的边，避免重复
            if(i < p->adjvex)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = p->adjvex;
                edges[edgeCount].weight = p->weight;
                edgeCount++;
            }
            p = p->nextarc;
        }
    }
    
    // 按权值排序（简单选择排序）
    for(int i = 0; i < edgeCount - 1; i++)
    {
        int minIdx = i;
        for(int j = i + 1; j < edgeCount; j++)
        {
            if(edges[j].weight < edges[minIdx].weight)
                minIdx = j;
        }
        if(minIdx != i)
        {
            Edge temp = edges[i];
            edges[i] = edges[minIdx];
            edges[minIdx] = temp;
        }
    }
    
    // Kruskal算法
    int parent[MAX_VERTEX_NUM];
    for(int i = 0; i < G.vexnum; i++)
        parent[i] = i;
    
    printf("  => MST (Kruskal):\n");
    int totalWeight = 0;
    int edgeNum = 0;
    
    for(int i = 0; i < edgeCount && edgeNum < G.vexnum - 1; i++)
    {
        int rootU = FindSet(parent, edges[i].u);
        int rootV = FindSet(parent, edges[i].v);
        
        if(rootU != rootV)
        {
            UnionSet(parent, rootU, rootV);
            printf("    Edge: %d(%s) -- %d(%s), weight: %d\n",
                   G.vertices[edges[i].u].data.key, G.vertices[edges[i].u].data.others,
                   G.vertices[edges[i].v].data.key, G.vertices[edges[i].v].data.others,
                   edges[i].weight);
            totalWeight += edges[i].weight;
            edgeNum++;
        }
    }
    
    if(edgeNum < G.vexnum - 1)
    {
        printf("  => Graph is not connected.\n");
        return ERROR;
    }
    
    printf("  => Total weight: %d\n", totalWeight);
    return OK;
}

// 顶点度数（无向图）
int Degree(ALGraph G, KeyType v)
// 无向图：返回顶点v的度数
{
    int idx = -1;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
        {
            idx = i;
            break;
        }
    }
    
    if(idx == -1)
    {
        printf("  => Vertex %d not found.\n", v);
        return -1;
    }
    
    // 计算邻接表中的边数
    int degree = 0;
    ArcNode *p = G.vertices[idx].firstarc;
    while(p)
    {
        degree++;
        p = p->nextarc;
    }
    
    return degree;
}

// 返回顶点数
int GetVerticesCount(ALGraph G)
// 返回图G的顶点数
{
    return G.vexnum;
}

// 返回边数
int GetEdgesCount(ALGraph G)
// 返回图G的边数
{
    int count = 0;
    
    for(int i = 0; i < G.vexnum; i++)
    {
        ArcNode *p = G.vertices[i].firstarc;
        while(p)
        {
            count++;
            p = p->nextarc;
        }
    }
    
    // 无向图的边数需要除以2（因为每条边存储了两次）
    if(G.kind == UDG || G.kind == UDN)
        count /= 2;
    
    return count;
}

// 展示图的邻接表
status DisplayGraph(ALGraph G)
// 以邻接表格式展示图的结构
{
    if(G.vexnum == 0)
    {
        printf("  => Graph is empty.\n");
        return ERROR;
    }
    
    printf("  => Adjacency List:\n");
    for(int i = 0; i < G.vexnum; i++)
    {
        // 输出顶点关键字和其他信息
        printf("  %d %s", G.vertices[i].data.key, G.vertices[i].data.others);
        
        // 输出所有邻接顶点的关键字
        ArcNode *p = G.vertices[i].firstarc;
        while(p)
        {
            printf(" %d", G.vertices[p->adjvex].data.key);
            p = p->nextarc;
        }
        printf("\n");
    }
    
    return OK;
}

// 判断v到w是否存在路径
status IsReachable(ALGraph G, KeyType v, KeyType w)
// 使用BFS判断从顶点v到顶点w是否存在路径
{
    // 查找两个顶点的位置
    int start = -1, end = -1;
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v)
            start = i;
        if(G.vertices[i].data.key == w)
            end = i;
    }
    
    if(start == -1 || end == -1)
    {
        printf("  => Vertex not found.\n");
        return ERROR;
    }
    
    if(start == end)
    {
        printf("  => %d is reachable to %d (same vertex).\n", v, w);
        return OK;
    }
    
    // BFS搜索
    int visited[MAX_VERTEX_NUM] = {0};
    int Q[MAX_VERTEX_NUM];
    int front = 0, rear = 0;
    
    visited[start] = 1;
    Q[rear++] = start;
    
    while(front < rear)
    {
        int u = Q[front++];
        
        ArcNode *p = G.vertices[u].firstarc;
        while(p)
        {
            if(p->adjvex == end)
            {
                printf("  => %d is reachable to %d.\n", v, w);
                return OK;
            }
            
            if(!visited[p->adjvex])
            {
                visited[p->adjvex] = 1;
                Q[rear++] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    
    printf("  => %d is NOT reachable to %d.\n", v, w);
    return ERROR;
}

int main()
{
    // 初始化图管理器
    InitGraphManager();
    
    int op = 1;

    // 首次运行打印菜单
    printf("  ==============================================\n");
    printf("  |  Graph On Adjacency List Structure         |\n");
    printf("  |   Author: Peng Wanru (U202514699)          |\n");
    printf("  ==============================================\n");
    printf("  --- Graph Management ---\n");
    printf("  30.AddGraph   31.RemoveGraph 32.FindGraph\n");
    printf("  33.SwitchGraph 34.ShowAll     35.ClearAll\n");
    printf("  --- Basic Operations ---\n");
    printf("   1.Create      2.Destroy      3.LocateVex\n");
    printf("   4.PutVex      5.FirstAdjVex  6.NextAdjVex\n");
    printf("   7.InsertVex   8.DeleteVex    9.InsertArc\n");
    printf("  10.DeleteArc  11.DFSTraverse 12.BFSTraverse\n");
    printf("  --- Algorithm Functions ---\n");
    printf("  13.Vertices<K 14.ShortestPath 15.ConnectedComp\n");
    printf("  16.SaveFile   17.LoadFile   18.HasCycle\n");
    printf("  19.PrimMST    20.KruskalMST 21.Degree\n");
    printf("  22.VerticesCnt 23.EdgesCnt  24.DisplayGraph\n");
    printf("  25.IsReachable\n");
    printf("  --------------------------------------------\n");
    printf("   0.Exit\n\n");

    while(op)
    {
        printf("=> ");
        scanf("%d", &op);
        getchar();  // 吸收回车符

        /* 获取当前活动图 */
        ALGraph &curG = GetCurrentGraph();

        /* 根据用户选择执行相应操作 */
        switch(op)
        {
            case 30: {  // 添加新图
                char name[30];
                printf("  => Enter new graph name: ");
                scanf("%s", name); getchar();
                
                if(AddGraph(graphs, name) == OK)
                {
                    currentGraphIdx = graphs.length - 1;
                    printf("  => Graph '%s' added & selected!\n", name);
                }
                else
                    printf("  => Add failed! Name exists or full.\n");
                break;
            }

            case 31: {  // 移除图
                char name[30];
                printf("  => Enter graph name to remove: ");
                scanf("%s", name); getchar();
                int pos = FindGraph(graphs, name);
                if(RemoveGraph(graphs, name) == OK)
                {
                    printf("  => Graph '%s' removed!\n", name);
                    if(currentGraphIdx == pos)
                        currentGraphIdx = (graphs.length > 0) ? 0 : -1;
                    else if(currentGraphIdx > pos)
                        currentGraphIdx--;
                }
                else
                    printf("  => Remove failed! Not found.\n");
                break;
            }

            case 32: {  // 查找图
                char name[30];
                printf("  => Enter graph name to find: ");
                scanf("%s", name); getchar();
                int pos = FindGraph(graphs, name);
                if(pos >= 0)
                    printf("  => Found at position: %d\n", pos + 1);
                else
                    printf("  => Not found!\n");
                break;
            }

            case 33: {  // 切换图
                char name[30];
                printf("  => Enter graph name to switch: ");
                scanf("%s", name); getchar();
                int pos = FindGraph(graphs, name);
                if(pos >= 0)
                {
                    currentGraphIdx = pos;
                    printf("  => Switched to '%s'!\n", name);
                }
                else
                    printf("  => Switch failed! Not found.\n");
                break;
            }

            case 34:  // 显示所有图
                ShowGraph(graphs);
                break;

            case 35: {  // 清空所有图
                printf("  => Clear ALL graphs? (y/n): ");
                char confirm;
                scanf(" %c", &confirm); getchar();
                if(confirm == 'y' || confirm == 'Y')
                {
                    for(int i = 0; i < graphs.length; i++)
                        DestroyGraph(graphs.elem[i].G);
                    graphs.length = 0;
                    currentGraphIdx = -1;
                    printf("  => All graphs cleared!\n");
                }
                else
                    printf("  => Cancelled.\n");
                break;
            }

            case 1: {  // 创建图
                if(curG.vexnum > 0) {
                    printf("  => Graph already exists. Destroy first? (y/n): ");
                    char c; scanf(" %c", &c); getchar();
                    if(c == 'y' || c == 'Y') DestroyGraph(curG);
                    else {  break; }
                }
                
                printf("  => Enter vertices (key others, -1 to end):\n");
                printf("  => Example: 1 A 2 B 3 C -1 x\n");
                
                VertexType V[MAX_VERTEX_NUM];
                int vCount = 0;
                
                while(vCount < MAX_VERTEX_NUM)
                {
                    printf("  => Vertex %d (key others): ", vCount + 1);
                    char line[100];
                    fgets(line, 100, stdin);
                    
                    char *token = strtok(line, " \n");
                    if(token == NULL) continue;
                    
                    int key = atoi(token);
                    if(key == -1) break;
                    
                    V[vCount].key = key;
                    token = strtok(NULL, " \n");
                    if(token != NULL)
                        strcpy(V[vCount].others, token);
                    else
                        strcpy(V[vCount].others, "null");
                    
                    vCount++;
                }
                V[vCount].key = -1; strcpy(V[vCount].others, "x");  // 终止符
                
                printf("  => Enter arcs (v1 v2, -1 -1 to end):\n");
                printf("  => Example: 1 2 2 3 -1 -1\n");
                
                KeyType VR[MAX_VERTEX_NUM * MAX_VERTEX_NUM][2];
                int eCount = 0;
                
                while(eCount < MAX_VERTEX_NUM * MAX_VERTEX_NUM)
                {
                    printf("  => Arc %d (v1 v2): ", eCount + 1);
                    int v1, v2;
                    scanf("%d %d", &v1, &v2); getchar();
                    
                    if(v1 == -1 && v2 == -1) break;
                    
                    VR[eCount][0] = v1;
                    VR[eCount][1] = v2;
                    eCount++;
                }
                VR[eCount][0] = -1; VR[eCount][1] = -1;  // 终止符
                
                if(CreateCraph(curG, V, VR) == OK)
                    printf("  => Graph created successfully!\n");
                else
                    printf("  => Create failed!\n");
                break;
            }

            case 2:  // 销毁当前图
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                if(DestroyGraph(curG) == OK)
                    printf("  => Graph destroyed!\n");
                else
                    printf("  => Destroy failed!\n");
                 break;

            case 3: {  // 查找顶点
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType u;
                printf("  => Enter key to search: "); scanf("%d", &u); getchar();
                int pos = LocateVex(curG, u);
                if(pos >= 0)
                    printf("  => Found at position: %d\n", pos + 1);
                else
                    printf("  => Not found!\n");
                 break;
            }

            case 4: {  // 顶点赋值
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType u, newKey; char others[20];
                printf("  => Enter key to modify: "); scanf("%d", &u); getchar();
                printf("  => Enter new key: "); scanf("%d", &newKey); getchar();
                printf("  => Enter new others: "); scanf("%s", others); getchar();
                
                VertexType value; value.key = newKey; strcpy(value.others, others);
                if(PutVex(curG, u, value) == OK)
                    printf("  => Assigned!\n");
                else
                    printf("  => Assign failed!\n");
                 break;
            }

            case 5: {  // 获得第一邻接点
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType u;
                printf("  => Enter key: "); scanf("%d", &u); getchar();
                int pos = FirstAdjVex(curG, u);
                if(pos >= 0)
                    printf("  => First adjacent: %d(%s)\n", curG.vertices[pos].data.key, curG.vertices[pos].data.others);
                else
                    printf("  => No adjacent vertex!\n");
                 break;
            }

            case 6: {  // 获得下一邻接点
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType v, w;
                printf("  => Enter vertex v: "); scanf("%d", &v); getchar();
                printf("  => Enter adjacent w: "); scanf("%d", &w); getchar();
                int pos = NextAdjVex(curG, v, w);
                if(pos >= 0)
                    printf("  => Next adjacent: %d(%s)\n", curG.vertices[pos].data.key, curG.vertices[pos].data.others);
                else
                    printf("  => No next adjacent vertex!\n");
                 break;
            }

            case 7: {  // 插入顶点
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType key; char others[20];
                printf("  => Enter new vertex key: "); scanf("%d", &key); getchar();
                printf("  => Enter others: "); scanf("%s", others); getchar();
                
                VertexType v; v.key = key; strcpy(v.others, others);
                if(InsertVex(curG, v) == OK)
                    printf("  => Inserted!\n");
                else
                    printf("  => Insert failed!\n");
                 break;
            }

            case 8: {  // 删除顶点
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType v;
                printf("  => Enter key to delete: "); scanf("%d", &v); getchar();
                if(DeleteVex(curG, v) == OK)
                    printf("  => Deleted!\n");
                else
                    printf("  => Delete failed!\n");
                 break;
            }

            case 9: {  // 插入弧
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType v, w;
                printf("  => Enter vertex v: "); scanf("%d", &v); getchar();
                printf("  => Enter vertex w: "); scanf("%d", &w); getchar();
                if(InsertArc(curG, v, w) == OK)
                    printf("  => Arc inserted!\n");
                else
                    printf("  => Insert failed!\n");
                 break;
            }

            case 10: {  // 删除弧
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType v, w;
                printf("  => Enter vertex v: "); scanf("%d", &v); getchar();
                printf("  => Enter vertex w: "); scanf("%d", &w); getchar();
                if(DeleteArc(curG, v, w) == OK)
                    printf("  => Arc deleted!\n");
                else
                    printf("  => Delete failed!\n");
                 break;
            }

            case 11:  // 深度优先遍历
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                printf("  => DFS: "); DFSTraverse(curG, PrintVertex); printf("\n");
                 break;

            case 12:  // 广度优先遍历
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                printf("  => BFS: "); BFSTraverse(curG, PrintVertex); printf("\n");
                 break;

            case 13: {  // 距离小于k的顶点
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType v; int k;
                printf("  => Enter vertex key: "); scanf("%d", &v); getchar();
                printf("  => Enter distance k: "); scanf("%d", &k); getchar();
                VerticesSetLessThanK(curG, v, k);
                 break;
            }

            case 14: {  // 最短路径长度
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType v, w;
                printf("  => Enter vertex v: "); scanf("%d", &v); getchar();
                printf("  => Enter vertex w: "); scanf("%d", &w); getchar();
                int dist = ShortestPathLength(curG, v, w);
                if(dist >= 0)
                    printf("  => Shortest path length: %d\n", dist);
                else
                    printf("  => No path exists!\n");
                 break;
            }

            case 15: {  // 连通分量个数
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                int count = ConnectedComponentsNums(curG);
                printf("  => Connected components: %d\n", count);
                 break;
            }

            case 16: {  // 保存到文件
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                char fileName[50];
                printf("  => Enter filename: "); scanf("%s", fileName); getchar();
                if(SaveGraph(curG, fileName) == OK)
                    printf("  => Saved to %s\n", fileName);
                else
                    printf("  => Save failed!\n");
                 break;
            }

            case 17: {  // 从文件加载
                if(curG.vexnum > 0) {
                    printf("  => Graph exists. Overwrite? (y/n): ");
                    char c; scanf(" %c", &c); getchar();
                    if(c != 'y' && c != 'Y') {  break; }
                    DestroyGraph(curG);
                }
                char fileName[50];
                printf("  => Enter filename: "); scanf("%s", fileName); getchar();
                if(LoadGraph(curG, fileName) == OK)
                {
                    printf("  => Loaded! Vertices: %d, Arcs: %d\n", curG.vexnum, curG.arcnum);
                    printf("  => DFS: "); DFSTraverse(curG, PrintVertex); printf("\n");
                }
                else
                    printf("  => Load failed!\n");
                 break;
            }

            case 18: {  // 判断是否有环
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                if(HasCycle(curG))
                    printf("  => The graph has cycle(s).\n");
                else
                    printf("  => The graph has no cycle.\n");
                 break;
            }

            case 19: {  // Prim算法
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType start;
                printf("  => Enter start vertex key: "); scanf("%d", &start); getchar();
                MST_Prim(curG, start);
                 break;
            }

            case 20: {  // Kruskal算法
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                MST_Kruskal(curG);
                 break;
            }

            case 21: {  // 顶点度数
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType v;
                printf("  => Enter vertex key: "); scanf("%d", &v); getchar();
                int deg = Degree(curG, v);
                if(deg >= 0)
                    printf("  => Degree of %d: %d\n", v, deg);
                 break;
            }

            case 22: {  // 返回顶点数
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                printf("  => Vertices count: %d\n", GetVerticesCount(curG));
                 break;
            }

            case 23: {  // 返回边数
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                printf("  => Edges count: %d\n", GetEdgesCount(curG));
                 break;
            }

            case 24: {  // 展示图的邻接表
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                DisplayGraph(curG);
                 break;
            }

            case 25: {  // 判断v到w是否存在路径
                if(curG.vexnum == 0) { printf("  => Error: No graph selected!\n");  break; }
                KeyType v, w;
                printf("  => Enter vertex v: "); scanf("%d", &v); getchar();
                printf("  => Enter vertex w: "); scanf("%d", &w); getchar();
                IsReachable(curG, v, w);
                 break;
            }

            case 0:
                printf("  => Exit system. Bye!\n");
                break;

            default:
                printf("  => Invalid option!\n");
                break;
        }
        
    }

    return 0;
}
