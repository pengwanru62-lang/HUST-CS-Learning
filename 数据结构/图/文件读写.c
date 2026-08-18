status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    FILE * fp = fopen(FileName,"w");  //打开文件，只可写入
    if(fp == NULL)
    {
        return ERROR;  //如果无法打开文件，返回错误
    }

    //先写入 结点数 和 边数
    fprintf(fp,"%d %d\n",G.vexnum,G.arcnum);  //写入顶点数和边数
    // 再写入顶点
    for(int k = 0;k<G.vexnum;k++)   //遍历每一个顶点
    {
        fprintf(fp,"%d %s\n",G.vertices[k].data.key,G.vertices[k].data.others);  //写入顶点的key和others
    }
    //下面输入每个结点对应的边

    for(int i = 0;i< G.vexnum ;i++)  //遍历每一个结点
    {
        ArcNode * p = G.vertices[i].firstarc;  //从顶点的第一条边开始遍历
        while (p)
        {
            fprintf(fp,"%d ",p->adjvex);  //写入边的邻接点编号
            p = p->nextarc;  //遍历下一条边
        }
        fprintf(fp,"-1\n");  //一条边结束后写入-1，便于之后的读取标记，否则序号就不固定了
    }

    fclose(fp);  //关闭文件
    return OK;  //返回成功

    /********** End 1 **********/
}

status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    FILE *fp = fopen(FileName,"r");  //打开文件，只可读取

    if(fp == NULL)
    {
        return ERROR;  //如果无法打开文件，返回错误
    }

    fscanf(fp,"%d %d\n",&G.vexnum,&G.arcnum);  //读取顶点数和边数

    //先对顶点进行建立
    for(int i = 0;i<G.vexnum ;i++)  //遍历每一个顶点
    {
        fscanf(fp,"%d %s\n",&G.vertices[i].data.key,G.vertices[i].data.others);  //读取顶点的key和others
        G.vertices[i].firstarc = NULL;  //顶点的第一条边先初始化为NULL
    }

    for(int k = 0;k<G.vexnum ;k++)  //遍历每一个结点
    {
        ArcNode *p = G.vertices[k].firstarc;  //从顶点的第一条边开始遍历

        ArcNode *newnode = (ArcNode *)malloc(sizeof(ArcNode));  //新建一个结点
        fscanf(fp,"%d ",&newnode->adjvex);  //读取新结点的邻接点编号
        newnode->nextarc = NULL;  //将新结点的下一条边设为NULL
        while (newnode->adjvex != -1)  //如果读取的邻接点编号不是-1
        {
            if(G.vertices[k].firstarc == NULL)  //如果当前顶点的第一条边为NULL
            {
                G.vertices[k].firstarc = newnode;  //将新结点设为该顶点的第一条边
                p = G.vertices[k].firstarc;  //令p指向该顶点的第一条边
            }
            else{
                p->nextarc = newnode;  //将新结点接到p指向的边的后面
                p = newnode;  //令p指向新结点
            }
            newnode = (ArcNode * ) malloc(sizeof(ArcNode));   //新建一个结点
            fscanf(fp,"%d ",&newnode->adjvex);  //读取新结点的邻接点编号
            newnode->nextarc = NULL;  //将新结点的下一条边设为NULL
        }

    }

    fclose(fp);  //关闭文件

    return OK;  //返回成功

    /********** End 2 **********/
}
