#include <stdio.h>
#include <stdlib.h>

void read_string(char *equation){
    int i=0;
    char ch;
    do{
        ch=getchar();
    }while(ch==' '||ch=='\n'||ch=='\t');

    while(ch!='\n'&&ch!=EOF){
        equation[i++]=ch;
        ch=getchar();
    }
    equation[i]='\0';
    return;
}

void parse_equation(char *equation,long long *a,long long *b,long long *c){
    int sign=1;
    *a=0;
    *b=0;
    *c=0;
    int i=0;

    if(equation[i]=='-'){
        sign=-1;
        i++;
    }
    while(equation[i]!='x'){
        *a=*a*10+(equation[i]-'0');
        i++;
    }
    if(sign==-1){
        *a=sign*(*a);
    }
    i++;

    sign=1;
    if(equation[i]=='-'){
        sign=-1;
        i++;
    }else if(equation[i]=='+'){
        i++;
    }
     while(equation[i]!='='){
        *b=*b*10+(equation[i]-'0');
        i++;
    }
    if(sign==-1){
        *b=sign*(*b);
    }
    i++;
    
    sign=1;
    if (equation[i] == '-') {
        sign = -1;
        i++;
    }
    while (equation[i] != '\0') {
        *c = *c * 10 + (equation[i] - '0');
        i++;
    }
    if(sign==-1){
        *c=sign*(*c);
    }
  return;  
}

int compare(const void *a,const void *b){
    long long x = *(int*)a;
    long long y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int lower_bound(int arr[],int n,int target){
    int left=0,right=n;
    while(left<right){
        int mid=left+(right-left)/2;
        if(arr[mid]<target){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return left;
}

int upper_bound(int arr[],int n,int target){
    int left=0,right=n;
    while(left<right){
        int mid=left+(right-left)/2;
        if(arr[mid]<=target){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return left;
}

int main(){
    int n,Q;
    scanf("%d %d",&n,&Q);
    getchar();

    int *solutions=(int *)malloc(n*sizeof(int));
    int cnt=0;

    for(int i=0;i<n;i++){
        char equation[100];
        read_string(equation);

        long long a,b,c;
        parse_equation(equation,&a,&b,&c);

        long long fenzi=c-b;
        if(a!=0 && fenzi%a==0){
            int x=(int)(fenzi/a);
            if(x>0){
                solutions[cnt++]=x;
            }
        }
    }

    if(cnt==0){
        for(int i=0;i<Q;i++){
            int L,R;
            scanf("%d %d",&L,&R);
            printf("0\n");
            free(solutions);
            return 0;
        }
    }

    qsort(solutions,cnt,sizeof(int),compare);

    int real_cnt=1;
    for(int i=1;i<cnt;i++){
        if(solutions[i]!=solutions[i-1]){
            solutions[real_cnt++]=solutions[i];
        }
    }

    for(int i=0;i<Q;i++){
        int L,R;
        scanf("%d %d",&L,&R);

        int left=lower_bound(solutions,real_cnt,L);
        int right=upper_bound(solutions,real_cnt,R);

        printf("%d\n",right-left);
    }
    free(solutions);
    return 0;
}