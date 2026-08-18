status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //整体思路是先建立顶点，在建立边，主要是将G的每个成员都正确赋值

    //首先定义图的类型
    G.kind = UDG;

    //初始化顶点数和弧数
    G.vexnum = 0;
    G.arcnum = 0;

    //数组的初始检查
    if(V[0].key == -1 || (V[1].key == -1 && VR[0][0] != -1))
    {
        return ERROR;
    }

    //初始化做好之后进行顶点数组的建立
    for(int i=0; V[i].key != -1; i++)   //以-1收尾
    {
        //判断是否溢出
        if(i >= MAX_VERTEX_NUM)
        {
            return ERROR;
        }

        //判断是否有重复的关键字
        for(int j=0; j<i; j++)
        {
            if(V[j].key == V[i].key)
            {
                return ERROR;
            }
        }

        //保存顶点
        G.vertices[i].data = V[i];
        G.vertices[i].firstarc = NULL;  //因为这里还没有建立第一条弧所以先置空
        //更新顶点数
        G.vexnum++;
    }

    //顶点数组建立好之后开始建立弧，主要是找到弧 V1->V2 对应的两个相关顶点
    //首先遍历弧数组
    for(int i=0;; i++) //i来控制顶点的数目
    {
        // 正常结束
        if(VR[i][0] == -1 && VR[i][1] == -1)
        {
            break;
        }

        // 非法关系对
        if(VR[i][0] == -1 || VR[i][1] == -1)
        {
            return ERROR;
        }
        
        int v1 = -1;
        int v2 = -1;

        //扫描图，进行匹配
        for(int j = 0; j<G.vexnum; j++)
        {
            if(G.vertices[j].data.key == VR[i][0])  //注意是VR[i][0]对应头节点
            {
                v1 = j; //此处直接使用对应的序号相当于编号
            }

            if(G.vertices[j].data.key == VR[i][1])
            {
                v2 = j;
            }
        }

        //如果有不存在的顶点
        if(v1 == -1 || v2 == -1)
        {
            return ERROR;
        }

        //忽略自环边
        if(v1 == v2)
        {
            return ERROR;  
        }

        //找到对应的v1和v2之后，进行弧的建立
        //首先进行去重,判断v1->v2这一条边是否已经存在
        ArcNode *p; 
        int is_exist = 0;

        //检查V1->v2
        p = G.vertices[v1].firstarc;
        
        while(p)    //非空时扫描该节点的子链表
        {
            if(p->adjvex == v2)
            {
                is_exist = 1;
                break;
            }
            p = p->nextarc;
        }

        //检查V2->V1
        p = G.vertices[v2].firstarc;
        while(p)    //非空时扫描该节点的子链表
        {
            if(p->adjvex == v1)
            {
                is_exist = 1;
                break;
            }
            p = p->nextarc;
        }

        if(is_exist)    //查重成功那么返回错误
        {
            return ERROR;  
        }

        //所有检查通过后，再更新弧数
        G.arcnum++;

        //现在进行头插法插入相关节点
        //插入V1->v2
        //首先创建相关节点
        ArcNode *s1;
        s1 = (ArcNode*)malloc(sizeof(ArcNode));
        s1->adjvex = v2;
        //首插法
        s1->nextarc = G.vertices[v1].firstarc;
        G.vertices[v1].firstarc = s1;

        //插入V2->V1
        ArcNode *s2;
        s2 = (ArcNode*)malloc(sizeof(ArcNode));
        s2->adjvex = v1;

        s2->nextarc = G.vertices[v2].firstarc;
        G.vertices[v2].firstarc = s2;
    }
    return OK;
    /********** End **********/
}