//首先标记访问数组
int visited[MAX_VERTEX_NUM]={0};

status BFSTraverse(ALGraph &G, void (*visit)(VertexType))
{
    //首先定义一个队列
    int Q[MAX_VERTEX_NUM];
    int front = 0;
    int rear = 0;
    
    //扫描顶点
    for(int i=0; i<G.vexnum; i++)
    {
        if(!visited[i])
        {
            //访问节点
            visit(G.vertices[i].data);
            visited[i] = 1;

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
                    if(!visited[p->adjvex])
                    {
                        visit(G.vertices[p->adjvex].data);
                        visited[p->adjvex] = 1;
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