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