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