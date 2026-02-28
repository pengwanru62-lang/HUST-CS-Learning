#include <stdio.h>
int main(){
    double s;
    scanf("%lf",&s);
    double step=2.0;
    int cnt=0;
    for(;s>0;cnt++){
        s-=step;
        step*=0.98;
    }
    printf("%d",cnt);
}