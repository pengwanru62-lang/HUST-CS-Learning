#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);

    char matrix[105][65];

    for(int i=0;i<n;i++){
        char temp[9];//注意字符串末尾的\0
        int index=0;

        for(int row=0;row<8;row++){
            scanf("%s",temp);
            for(int col=0;col<8;col++){
                matrix[i][index++]=temp[col];
            }
        }
        matrix[i][64]='\0';
    }

    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<=i;j++){
            if(strcmp(matrix[i],matrix[j])==0){
                cnt++;
                
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
1. 读取 n 个 8×8 的字符矩阵
2. 将每个 8×8 矩阵展平成长度为 64 的字符串
3. 对每个矩阵，统计它在前面（包括自己）出现的次数
*/