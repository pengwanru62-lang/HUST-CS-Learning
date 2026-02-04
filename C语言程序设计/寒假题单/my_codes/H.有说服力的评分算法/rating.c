#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    int max=-1,min=11;
    for(int i=0;i<n;i++){
        int score;
        scanf("%d",&score);
        if(score>max)max=score;
        if(score<min)min=score;
        sum+=score;
    }
    double ave=(double)(sum-max-min)/(n-2);
    printf("%.2f",ave);
    return 0;
}