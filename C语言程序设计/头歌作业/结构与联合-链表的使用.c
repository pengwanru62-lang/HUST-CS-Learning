#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
}Node;

Node *createList();
void traversePrint(Node *head);
char *listToString(Node *head);
void deleteNode(Node **head,char x);
Node *findClosest(Node *head,char x);
void insertAfter(Node *closest,char x);

int main(){

    Node *head=createList();

    traversePrint(head);

    char *s=listToString(head);
    printf("%s\n",s);

    char x;
    scanf("%c",&x);
    int found=0;
    Node *p=head;
    while(p!=NULL){
        if(p->data==x){
            found=1;
            break;
        }
        p=p->next;
    }
    if(found){
        deleteNode(&head,x);
    }else{
        Node *closest=findClosest(head,x);
        insertAfter(closest,x);
    }

    char *c=listToString(head);
    printf("%s",c);

    return 0;
}

Node *createList(){
    Node *head=NULL,*tail=NULL;
    char c;
    while((c=getchar())!='\n'){
        Node *p=(Node *)malloc(sizeof(Node));
        p->data=c;
        if(head==NULL){
            head=p;
        }else{
            tail->next=p;
        }
        tail=p;
    }
    if(tail!=NULL){
        tail->next=NULL;
    }
    return head;
}

void traversePrint(Node *head){
    Node *p=head;
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

char *listToString(Node *head){
    Node *p=head;
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    char *s=(char *)malloc(len+1);
    int i;
    p=head;
    for(i=0;i<len;i++){
        s[i]=p->data;
        p=p->next;
    }
    s[i]='\0';
    return s;
}
//返回“目标节点的前驱”，如果不存在前驱，就返回 NULL。
Node *findPre(Node *head,char x){//
    Node *p=head;
    Node *pre=NULL;
    while(p!=NULL){
        if(p->data==x) return pre;
        pre=p;
        p=p->next;
    }
    return NULL;
}

void deleteNode(Node **head,char x){
    Node *pre=findPre(*head,x);

    if(pre==NULL){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }else{
        Node *del=pre->next;
        pre->next=del->next;
        free(del);
    }
}

Node *findClosest(Node *head,char x){
    Node *p=head;
    Node *best=head;
    int bestNum=abs(p->data-x);

    p=p->next;
    while(p!=NULL){
        int Diff=abs(p->data-x);
        if(Diff<bestNum){
            best=p;
            bestNum=Diff;
        }
        p=p->next;
    }
    return best;
}

void insertAfter(Node *closest,char x){
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=x;
    p->next=closest->next;
    closest->next=p;
}


