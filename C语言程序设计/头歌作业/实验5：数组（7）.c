# include <stdio.h>
#include <string.h>

void InputInformation();
void SortInformation();
void OutputInformation();

int n;
int score[100];
char name[100][50];
int main() {
	int ctrl;
	do {
		scanf("%d",&ctrl);
		switch(ctrl) {
			case 0:
				return 0;
			case 1:
				InputInformation();
				break;
			case 2:
				SortInformation();
				break;
			case 3:
				OutputInformation();
				break;
			default:
				printf("Invalid input!");
		}
	} while(ctrl);
	return 0;
}

void InputInformation() {
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++) {
		scanf("%s%d",name[i],&score[i]);
	}
	return;
}

void SortInformation() { //Ã°ÅÝÅÅÐò
	int i,j;
	for(i=0; i<n-1; i++) {
		for(j=i+1; j<n; j++) {
			if(score[i]<score[j]||score[j]==score[i]&&(strcmp(name[i],name[j])>0)) {
				int temp=score[i];
				score[i]=score[j];
				score[j]=temp;

				char tempname[50];
				strcpy(tempname,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],tempname);
			}
		}
	}
}
void OutputInformation() {
	int k;
	for(k=0; k<n; k++) {
		printf("%s %d\n",name[k],score[k]);
	}
}
