#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Grade{
	char num[20];
	char name[20];
	int English;
	int Math;
	int Physics;
	int Programming;
	struct Grade *next;
}Grade; 

Grade *addStudent(Grade *head){
	int n;
	scanf("%d",&n);

	Grade *tail=head;
	while(tail&&tail->next){
		tail=tail->next;
	}//找到表尾便于重新添加 

	int i; 
	for(i=0;i<n;i++){
		Grade *stdt=(Grade *)malloc(sizeof(Grade));
		if(stdt==NULL)return;
		scanf("%s %s %d %d %d %d",stdt->num,stdt->name,&stdt->English,&stdt->Math,&stdt->Physics,&stdt->Programming);
		stdt->next=NULL;
		if(head==NULL){
			head=stdt;
		}else{
			tail->next=stdt;
		}
		tail=stdt;
	}
	return head;
}

void displayStudent(Grade *head){
	Grade *p=head;
	while(p){
		printf("%s %s %d %d %d %d\n",p->num,p->name,p->English,p->Math,p->Physics,p->Programming);
		p=p->next;
	}
	return;
}

void changeStudent(Grade *head){
	char  id[20];
	int item,score;
	scanf("%s %d %d",id,&item,&score);
	Grade *p=head;
	while(p){
		if(strcmp(p->num,id)==0){
			switch(item){
				case 1:p->English=score;break;
				case 2:p->Math=score;break;
				case 3:p->Physics=score;break;
				case 4:p->Programming=score;break;
			}
			return;
		}
		p=p->next;
	}
	return;
}

void averageStudent(Grade *head){
	Grade *p=head;
	while(p){
		double aver=(p->English+p->Math+p->Physics+p->Programming)/4.0;
		printf("%s %s %.2lf\n",p->num,p->name,aver);
		p=p->next;
	}
	return;
}

void OutputAll(Grade *head){
	Grade *p=head;
	while(p){
		int total=(p->English+p->Math+p->Physics+p->Programming);
		double aver=(p->English+p->Math+p->Physics+p->Programming)/4.0;
		printf("%s %s %d %.2lf\n",p->num,p->name,total,aver);
		p=p->next;
	}
	return;
}

void freeList(Grade **head){
	Grade *p=*head;
	while(p){
		Grade *temp=p;
		p=p->next;
		free(temp);
	}
	*head=NULL;
}

int main(){
	int choice;
	Grade *head=NULL;
	while(1){
		scanf("%d",&choice);
		switch(choice){
			case 0:
				freeList(&head);
				return 0;
			case 1:
				head=addStudent(head);
				break;
			case 2:
				displayStudent(head);
				break;
			case 3:
				changeStudent(head);
				break;
			case 4:
				averageStudent(head);
				break;
			case 5:
				OutputAll(head);
				break;
			default:
				break;
		}
	}
	return 0;
}
