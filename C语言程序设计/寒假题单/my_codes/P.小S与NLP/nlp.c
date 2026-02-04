#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 5005
#define MAXLEN 500005

typedef struct{
    char key[25];
    char val[12];
}Pair;

Pair dict[MAXN];
int n,m;

char * find_value(char *);

int main(){
    scanf("%d %d",&n,&m);
    int i;
    for(i=0;i<n;i++){
        scanf("%s %s",dict[i].key,dict[i].val);
    }
    getchar();
    while(m--){
        char line[MAXLEN];
        fgets(line,MAXLEN,stdin);

        int len=strlen(line);
        for(i=0;i<len;i++){
           if(line[i]=='{'){
               char temp[25];
               int t=0;
               i++;
               while(line[i]!='}'){
                   temp[t++]=line[i++];
               }
               temp[t]='\0';
               printf("%s",find_value(temp));
           }else{
               putchar(line[i]);
           }
        }
    }
    return 0;
}
char * find_value(char *key){
    int i;
    for(i=0;i<n;i++){
        if(strcmp(key,dict[i].key)==0){
            return dict[i].val;
        }
    }
    return " ";
}

