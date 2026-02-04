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

/* 添加学生信息：读入n个学生的信息，采用尾插法插入链表 */
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
		if(stdt==NULL)return NULL;
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

// 改为接收指向头指针的指针，这样才能改变头指针
void sortByAverage(Grade **head){
	if(*head==NULL||(*head)->next==NULL){
		return;
	}
	int flag;  // 标记本轮是否发生交换
	Grade *p1,*prev,*p2;
	
	do{
		flag=0;
        prev=NULL;  // 前驱结点指针
		p1=*head;  // 从头结点开始
		while(p1->next!=NULL){
			p2=p1->next;  // p2指向p1的后继
			double avg1=(p1->English+p1->Math+p1->Physics+p1->Programming)/4.0;  // 计算p1的平均分
			double avg2=(p2->English+p2->Math+p2->Physics+p2->Programming)/4.0;  // 计算p2的平均分
			
			/*if(avg1>avg2){
				char tmpNum[20], tmpName[20];
                int tmpEnglish, tmpMath, tmpPhysics, tmpProgramming;
                
				strcpy(tmpNum, p1->num);
				strcpy(tmpName, p1->name);
				tmpEnglish = p1->English;
				tmpMath = p1->Math;
				tmpPhysics = p1->Physics;
				tmpProgramming = p1->Programming;
				 
				strcpy(p1->num, p2->num);
                strcpy(p1->name, p2->name);
                p1->English = p2->English;
                p1->Math = p2->Math;
                p1->Physics = p2->Physics;
                p1->Programming = p2->Programming;
                
                
                strcpy(p2->num, tmpNum);
                strcpy(p2->name, tmpName);
                p2->English = tmpEnglish;
                p2->Math = tmpMath;
                p2->Physics = tmpPhysics;
                p2->Programming = tmpProgramming;
                
				flag=1;
			}
			p1=p1->next;
		}这一部分为交换数据域，需要调整成为交换指针域*/
        if(avg1>avg2){
            //交换指针，互换p1和p2的位置
            p1->next=p2->next;
            p2->next=p1;
            if(prev==NULL){
                //交换的是头结点
                *head=p2;//p2成为新的头结点
            }else{
                prev->next=p2;//前驱结点指向p2
        }
        //更新指针，进行下一轮比较
        prev=p2;
        p1=p2->next;
        flag=1;
    }
        else{
        //不交换，继续向后移动
        prev=p1;
        p1=p1->next;
    }
        
	}	
}while(flag);
}

/* 显示所有学生信息（按平均成绩升序） */
void displayStudent(Grade **head){
	sortByAverage(head);  /* 排序后head正确指向新的头结点 */
	Grade *p=*head;
	while(p){
		printf("%s %s %d %d %d %d\n",p->num,p->name,p->English,p->Math,p->Physics,p->Programming);
		p=p->next;
	}
	return;
}

/* 修改指定学生的某科成绩 */
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

/* 输出所有学生的平均成绩（按平均成绩升序） */
void averageStudent(Grade **head){
	sortByAverage(head);  /* 排序后head正确指向新的头结点 */
	Grade *p=*head;
	while(p){
		double aver=(p->English+p->Math+p->Physics+p->Programming)/4.0;
		printf("%s %s %.2lf\n",p->num,p->name,aver);
		p=p->next;
	}
	return;
}

/* 输出所有学生的总分和平均分（按平均成绩升序） */
void OutputAll(Grade **head){
	sortByAverage(head);  /* 排序后head正确指向新的头结点 */
	Grade *p=*head;
	while(p){
		int total=(p->English+p->Math+p->Physics+p->Programming);
		double aver=(p->English+p->Math+p->Physics+p->Programming)/4.0;
		printf("%s %s %d %.2lf\n",p->num,p->name,total,aver);
		p=p->next;
	}
	return;
}

/* 释放整个链表的内存 */
void freeList(Grade **head){
	Grade *p=*head;
	while(p){
		Grade *temp=p;  // 暂存当前结点
		p=p->next; // 移动到下一个结点
		free(temp); // 释放当前结点
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
				displayStudent(&head);  /* 传地址 */
				break;
			case 3:
				changeStudent(head);
				break;
			case 4:
				averageStudent(&head);  /* 传地址 */
				break;
			case 5:
				OutputAll(&head);  /* 传地址 */
				break;
			default:
				break;
		}
	}
	return 0;
}