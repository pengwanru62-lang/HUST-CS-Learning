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
