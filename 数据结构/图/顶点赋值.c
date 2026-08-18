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
