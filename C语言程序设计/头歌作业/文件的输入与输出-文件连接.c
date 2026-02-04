#include<stdio.h>

/*********************************************************************************
  完成函数，连接filename1、filename2 和 filename3 三个文件的内容到 filename 文件中
  先连接file1，再连接file2，最后连接file3
  ********************************************************************************/
void connect(char *filename,char *filename1,char *filename2,char *filename3)
{
	FILE *fp1(filename,"w");
    if(fp==NULL) return;

    char *files[3]={filename1,filename2,filename3};
    char line[500];

    for(int i=0;i<3;i++){
        FILE *fp2=fopen(files[i],"r");
        if(fp2==NULL) continue;

        while(fgets(line,sizeof(line),fp2)!=NULL){
            fputs(line,fp1);
        }

        fclose(fp2);
    }
    fclose(fp1);
    return;
}