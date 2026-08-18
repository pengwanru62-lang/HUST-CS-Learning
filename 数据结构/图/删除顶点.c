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

    //不允许有空图
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