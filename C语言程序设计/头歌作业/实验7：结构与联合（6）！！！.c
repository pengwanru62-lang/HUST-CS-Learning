#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生成绩结构体（链表节点）
typedef struct Grade{
	char num[20];
	char name[20];
	int English;
	int Math;
	int Physics;
	int Programming;
	struct Grade *next;
}Grade; 

// 添加学生（在链表尾部追加若干学生，返回新的头指针）
Grade *addStudent(Grade *head){
	int n;
	scanf("%d",&n);

	// 找到当前链表的尾结点（tail 指向最后一个节点）
	Grade *tail=head;
	while(tail && tail->next){
		tail=tail->next;
	}

	int i; 
	for(i=0;i<n;i++){
		// 为新学生动态分配内存
		Grade *stdt=(Grade *)malloc(sizeof(Grade));
		if(stdt==NULL) return head;   // 分配失败，直接返回原链表头

		// 依次输入：学号、姓名、四门课成绩
		scanf("%s %s %d %d %d %d",
		      stdt->num, stdt->name,
		      &stdt->English, &stdt->Math,
		      &stdt->Physics, &stdt->Programming);
		stdt->next=NULL; // 新结点的 next 先置为空

		if(head==NULL){   // 如果原来链表为空，新结点作为头结点
			head=stdt;
		}else{   // 否则接到当前尾结点之后
			tail->next=stdt;
		}
		tail=stdt;  // 更新尾指针为新结点
	}
	return head;  // 返回新的头指针
}

// 按平均分从小到大对链表进行冒泡排序（交换结点中的数据）
void sortByAverage(Grade *head){
	// 链表为空或只有一个结点时，无需排序
	if(head==NULL||head->next==NULL){
		return;
	}
	int flag;    // 标记一轮循环中是否发生交换
	Grade *p1,*p2;// p1、p2 指向待比较的两个相邻结点
	
	do{
		flag=0;
		p1=head;
		// 从头到尾依次比较相邻的两个结点
		while(p1->next!=NULL){
			p2=p1->next;
			// 计算两个结点各自的平均分
			double avg1=(p1->English+p1->Math+p1->Physics+p1->Programming)/4.0;
			double avg2=(p2->English+p2->Math+p2->Physics+p2->Programming)/4.0;
			
			// 如果前一个结点平均分大于后一个，则交换两者的数据域
			if(avg1>avg2){
				char tmpNum[20], tmpName[20];
                int tmpEnglish, tmpMath, tmpPhysics, tmpProgramming;
                
				// 先把 p1 的数据备份到临时变量中
				strcpy(tmpNum, p1->num);
				strcpy(tmpName, p1->name);
				tmpEnglish = p1->English;
				tmpMath = p1->Math;
				tmpPhysics = p1->Physics;
				tmpProgramming = p1->Programming;
				 
				// 把 p2 的数据拷贝到 p1 中
				strcpy(p1->num, p2->num);
                strcpy(p1->name, p2->name);
                p1->English = p2->English;
                p1->Math = p2->Math;
                p1->Physics = p2->Physics;
                p1->Programming = p2->Programming;
                
                // 再把临时变量中的数据拷贝回 p2，实现两结点数据交换
                strcpy(p2->num, tmpNum);
                strcpy(p2->name, tmpName);
                p2->English = tmpEnglish;
                p2->Math = tmpMath;
                p2->Physics = tmpPhysics;
                p2->Programming = tmpProgramming;
                
				flag=1; // 标记本轮发生过交换
			}
			p1=p1->next; // 继续比较下一对相邻结点
		}
	}while(flag); // 若本轮有交换，则继续下一轮；否则排序结束
} 

// 按平均分排序后，输出每个学生的各科成绩
void displayStudent(Grade *head){
	sortByAverage(head);  // 先排序
	Grade *p=head;
	while(p){    // 依次遍历链表输出
		printf("%s %s %d %d %d %d\n",
		       p->num,p->name,
		       p->English,p->Math,p->Physics,p->Programming);
		p=p->next;
	}
}

// 按学号查找指定学生，并修改其某一门课的成绩
void changeStudent(Grade *head){
	char  id[20];  // 要修改成绩的学号
	int item,score;    
	scanf("%s %d %d",id,&item,&score);
	Grade *p=head;
	while(p){
		// 找到学号匹配的学生
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
}

void averageStudent(Grade *head){
	sortByAverage(head);
	Grade *p=head;
	while(p){
		double aver=(p->English+p->Math+p->Physics+p->Programming)/4.0;
		printf("%s %s %.2lf\n",p->num,p->name,aver);
		p=p->next;
	}
	return;
}

// 按平均分排序后，输出每个学生的总分和平均分
void OutputAll(Grade *head){
	sortByAverage(head);
	Grade *p=head;
	while(p){
		int total=(p->English+p->Math+p->Physics+p->Programming);
		double aver=(p->English+p->Math+p->Physics+p->Programming)/4.0;
		printf("%s %s %d %.2lf\n",p->num,p->name,total,aver);
		p=p->next;
	}
	return;
}

// 释放整个链表（防止内存泄漏）
void freeList(Grade **head){
	Grade *p=*head;
	while(p){
		Grade *temp=p; // 暂存当前结点地址
		p=p->next; // 先后移，再释放当前结点
		free(temp);
	}
	*head=NULL;  // 头指针置空，防止出现野指针
}

int main(){
	int choice;  // 用户菜单选择
	Grade *head=NULL; // 链表头指针，初始为空
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
