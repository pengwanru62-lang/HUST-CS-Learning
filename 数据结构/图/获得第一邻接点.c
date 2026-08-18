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
