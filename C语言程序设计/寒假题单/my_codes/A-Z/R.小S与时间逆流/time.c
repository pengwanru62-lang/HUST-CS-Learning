#include <stdio.h>
#include <string.h>

int main(){
    char s[100005];
    scanf("%s",s);
    int p=-1;
    int i;
    int n=strlen(s);
    for(i=0;i<n;i++){
        if(s[i]=='1'){
            p=i;
            break;
        }
    }
    if(p==-1){
        printf("%s",s);
        return 0; 
    }
    int bestr=-1;
    for(i=n-1;i>=p;i--){
        if(s[i]=='0'){
            if(bestr==-1){
                bestr=i;
            }else{
                int a=i,b=bestr;
                while(a>=p&&b>=p){
                    if(s[a]!=s[b]){
                        if(s[a]<s[b]){
                            bestr=i;
                        }
                        break;
                    }
                    a--;
                    b--;
                }
            }
        }
    }
    if(bestr==-1){
        printf("%s",s);
    }else{
        for(i=0;i<p;i++)printf("%c",s[i]);
        for(i=bestr;i>=p;i--)printf("%c",s[i]);
        for(i=bestr+1;i<n;i++)printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
