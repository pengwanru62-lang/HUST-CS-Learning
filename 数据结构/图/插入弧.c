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
    s->nextarc = G.vertices[iv].firstarc;
    G.vertices[iv].firstarc = s;

    //无向图中还需要插入iw->iv
    ArcNode *t = (ArcNode *)malloc(sizeof(ArcNode));
    t->adjvex = iv;
    t->nextarc = G.vertices[iw].firstarc;
    G.vertices[iw].firstarc = t;

    //更新弧的总数
    G.arcnum++;

    //插入成功返回OK
    return OK;
    /********** End **********/
}