status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //查找是否存在名称匹配的线性表
    int found=-1;   //found=-1表示没找到，否则为匹配到的相应下标
    for(int i=0; i<Lists.length; i++)
    {
        int j =0;
        int flag=1; //标记是否匹配
        while(ListName[j]!='\0' && Lists.elem[i].name[j]!='\0')
        {
            //依次比较两个字符串是否相等
            if(ListName[j] != Lists.elem[i].name[j])
            {
                flag = 0;
                break;
            }
            j++;
        }
        //字符串完全相等：内容相同并且同时结束
        if(flag==1 && ListName[j]=='\0' && Lists.elem[i].name[j]=='\0')
        {
            found = i;
            break;
        }
    }

    //如果匹配失败则返回ERROR
    if(found == -1)
    {
        return ERROR;
    }
    
    //匹配成功则销毁相应线性表
    DestroyList(Lists.elem[found].L);

    //移动覆盖删除Lists集合对应部分
    for(int k=found; k<=Lists.length-1; k++)
    {
        Lists.elem[k] = Lists.elem[k+1];
    }

    //更新表长
    Lists.length--;

    return OK;

    /********** End **********/
}
