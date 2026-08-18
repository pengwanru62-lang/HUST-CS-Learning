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
