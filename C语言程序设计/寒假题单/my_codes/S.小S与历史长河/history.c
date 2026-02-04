#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char S[1005];
	char T[1005];
	scanf("%s",S);
	scanf("%s",T);
	
	int Q;
	scanf("%d",&Q);
	
	int i;
	for(i=0;i<Q;i++){
		int ls,rs,lt,rt;
		scanf("%d %d %d %d",&ls,&rs,&lt,&rt);
		
		ls--;
		rs--;
		lt--;
		rt--;
		
		char temp_s[1005];
		char temp_t[1005];
		
		int j;
		int a=ls,b=lt;
		for(j=0;j<rs-ls+1;j++){
			temp_s[j]=S[a++];
		}
		temp_s[j]='\0';
		for(j=0;j<rt-lt+1;j++){
			temp_t[j]=T[b++];
		}
		temp_t[j]='\0';
		
		if(strcmp(temp_s,temp_t)<0){
			printf("yifusuyi\n");
		}else if(strcmp(temp_s,temp_t)>0){
			printf("erfusuer\n");
		}else{
			printf("ovo\n");
		}
	}
	return 0;
}
