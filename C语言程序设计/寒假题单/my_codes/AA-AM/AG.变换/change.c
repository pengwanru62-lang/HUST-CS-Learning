#include <stdio.h>
#include <math.h>

double scale[100005];
double angle[100005];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    scale[0]=1.0;
    angle[0]=0.0;

    for(int i=1;i<=n;i++){
        int type;
        double v;
        scanf("%d %lf",&type,&v);
        if(type==1){
            scale[i]=scale[i-1]*v;
            angle[i]=angle[i-1];
        }else{
            scale[i]=scale[i-1];            
            angle[i]=angle[i-1]+v;
        }
    }

    for(int i=0;i<m;i++){
        int l,r;
        double x,y;
        scanf("%d %d %lf %lf",&l,&r,&x,&y);

        double k=scale[r]/scale[l-1];
        double theta = angle[r]-angle[l-1];

        x*=k;
        y*=k;

        double newx = x * cos(theta) - y * sin(theta);
        double newy = x * sin(theta) + y * cos(theta);

        printf("%.3lf %.3lf\n",newx,newy);
    }
    return 0;
}