#include <stdio.h>
#include <string.h>

int main(){

    char cmd1[20],cmd2[20];
    FILE *fp;
    int lineNum;
    char line[100];
    char ch;
    char filename[100];

    if(fscanf(stdin,"%s",cmd1)!=1){
        return 0;
    }
    if(strcmp(cmd1,"type_c")!=0){
        printf("指令错误");
        return 0;
    }

    fscanf(stdin,"%s",cmd2);
    fscanf(stdin,"%s",filename);

    if(strcmp(cmd2,"/p")!=0){
        fp=fopen("src/step1_1/test1.c","r");
        if(fp==NULL){
            return 0;
        }

        lineNum=1;
        while(fgets(line,sizeof(line),fp)!=NULL){//fgets读取的时候包括了换行符
            fprintf(stdout,"%d  %s",lineNum++,line);
        }
        fclose(fp);
    }
    else{
        fp=fopen("src/step1_1/test1.c","r");
        if(fp==NULL){
            return 0;
        }
        do{
            int cnt=0;
            lineNum=1;

            while(cnt<10 && fgets(line,sizeof(line),fp)){
                fprintf(stdout,"%d  %s",lineNum++,line);
                cnt++;
            }

            if(cnt<10){
                break;
            }
        
            fscanf(stdin," %c",&ch);//注意此时缓存区还有filename没有被处理
        }while(ch=='q');
        fclose(fp);
    }
    return 0;
}