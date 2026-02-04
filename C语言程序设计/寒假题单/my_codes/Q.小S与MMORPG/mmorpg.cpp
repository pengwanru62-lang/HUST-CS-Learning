#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
	return strcmp(*(const char **)a,*(const char **)b);
}

int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	
	char **yesterday=(char **)malloc(n*sizeof(char *));
	char **found=(char **)malloc(m*sizeof(char *));
	char **new_found=(char **)malloc(k*sizeof(char *));
	int i;
	for(i=0;i<n;i++){
		yesterday[i]=(char *)malloc(11*sizeof(char));
	}
	for(i=0;i<m;i++){
		found[i]=(char *)malloc(11*sizeof(char));
	}
	for(i=0;i<k;i++){
		new_found[i]=(char *)malloc(11*sizeof(char));
	}
	for(i=0;i<n;i++){
		scanf("%s",yesterday[i]);
	}
	for(i=0;i<m;i++){
		scanf("%s",found[i]);
	}
	for(i=0;i<k;i++){
		scanf("%s",new_found[i]);
	}
	
	qsort(found, m, sizeof(char *), cmp);
	char **explore=(char **)malloc((n+k)*sizeof(char *));
	for(i=0;i<n+k;i++){
		explore[i]=(char *)malloc(11*sizeof(char));
	}
	
	int q=0;
	for(i=0;i<n;i++){
		char **result=(char **)bsearch(&yesterday[i],found,m,sizeof(char *),cmp);
		if(result==NULL){
			strcpy(explore[q++],yesterday[i]);
		}
	}
	
	for(i=0;i<k;i++){
		 strcpy(explore[q++], new_found[i]);
	}
	
	int len=q;
	
	qsort(explore,q,sizeof(char *),cmp);
	
	for(i=0;i<len;i++){
		printf("%s\n",explore[i]);
	}
	
	
	for(i=0;i<n;i++)free(yesterday[i]);
	for(i=0;i<m;i++)free(found[i]);
	for(i=0;i<k;i++)free(new_found[i]);
	for(i=0;i<k+n;i++)free(explore[i]);
	free(yesterday);
	free(found);
	free(new_found);
	free(explore);
	
	return 0;
}
