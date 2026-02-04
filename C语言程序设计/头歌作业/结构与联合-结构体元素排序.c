#include<stdio.h>
#include<string.h>
struct web { /*  设计表示网址的结构  */
	/**********  Begin  **********/
	char shname[30];
	char name[30];
	char url[100];
	/**********   End   **********/
} webs[4];

#define N  4      /*  网址表大小  */
void sort(struct web webs[],int n);
int main() {
	/**********  Begin  **********/
	int i;
	for(i=0; i<N; i++) {
		scanf("%s %s %s",webs[i].shname,webs[i].name,webs[i].url);
	}

	sort(webs,N);

	char goal[10];
	scanf("%s",goal);

	for(i=0; i<N; i++) {
		printf("%s %s %s\n",webs[i].shname,webs[i].name,webs[i].url);
	}

	int flag=0;
	for(i=0; i<N; i++) {
		if(strcmp(webs[i].shname,goal)==0) {
			printf("%s",webs[i].url);
			flag=1;
			break;
		}
	}

	if(flag==0)printf("未找到搜寻的网址");

	/**********   End   **********/
	return 0;
}

void sort(struct web webs[],int n) {
	/**********  Begin  **********/
	int i,j;
	struct web temp;
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-1-i; j++) {
			if(strcmp(webs[j].shname,webs[j+1].shname)>0) {
				temp=webs[j];
				webs[j]=webs[j+1];
				webs[j+1]=temp;
			}
		}
	}
	return;
	/**********   End   **********/
}
