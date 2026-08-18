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