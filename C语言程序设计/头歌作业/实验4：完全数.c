#include<stdio.h>
void isPerfect(int n)
//请完成isPerfect函数，判断整数n是否为完全数
{
/**********   Begin   **********/
int sum=0;
int i;
int a[100]={0};
int cnt=0;
for(i=1;i<n;i++){
    if(n%i==0){
        sum+=i;
        a[cnt]=i;
        cnt++;
    }
}
if(sum!=n)printf("%d is not a perfect number",n);
else if(sum==n){
    printf("%d=1",n);
    for(int k=1;k<cnt;k++){
        printf("+%d",a[k]);
    }
}


/**********    End    **********/
}
