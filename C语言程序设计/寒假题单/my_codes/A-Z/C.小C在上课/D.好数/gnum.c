#include <stdio.h>
struct isLike{
    unsigned int duoluoluo:1;
    unsigned int yazhi:1;
    unsigned int years600:1;
    unsigned int gaiya:1;
}p={0,0,0,0};

int main(){
    unsigned int x;
    scanf("%u",&x);
    int flag1=0,flag2=0;
    if(x%2==0)flag1=1;
    if(x>4&&x<=12)flag2=1;
    
    if(flag1&&flag2) p.duoluoluo=1;
    if(flag1||flag2) p.yazhi=1;
    if((flag1 == 1 && flag2 == 0) || (flag1 == 0 && flag2 == 1)) p.years600=1;
    if(flag1==0&&flag2==0) p.gaiya=1;

    printf("%d %d %d %d", p.duoluoluo, p.yazhi, p.years600, p.gaiya);

}