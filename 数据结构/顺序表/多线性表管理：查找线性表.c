int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //查找是否存在名称匹配的线性表
    int found = -1; //found=-1表示没找到，否则为匹配到的相应下标
    for(int i=0; i<Lists.length; i++)
    {
        //依次比较两个字符串是否相等
        int j = 0;
        int flag = 1;   //标记是否匹配
        while(ListName[j]!='\0' && Lists.elem[i].name[j]!='\0')
        {
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
    
    //返回逻辑下标
    return found + 1;

    /********** End **********/
}
