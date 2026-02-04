#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode;

void push(StackNode **top,int x){
    StackNode *p=(StackNode *)malloc(sizeof(StackNode));
    p->data=x;
    p->next=*top;
    *top=p;
}//入栈:将元素x放在最上面

int pop(StackNode **top){
    int x=(*top)->data;
    StackNode *temp=*top;
    *top=(*top)->next;
    free(temp);
    return x;
}//出栈:删除最上面的元素并返回其值

int main(){
    StackNode *top=NULL; //初始化栈顶指针为空，否则会出现野指针
    char token[20];

    while(scanf("%s",token)!=EOF){

        if(strlen(token)==1 && (token[0]=='+' || token[0]=='-' || token[0]=='*' || token[0]=='/')){
            int right=pop(&top);//注意先弹出右操作数
            int left=pop(&top);//再弹出左操作数
            int result;
            switch(token[0]){
                case '+': 
                    result=left+right; 
                    break;
                case '-': 
                    result=left-right; 
                    break;
                case '*': 
                    result=left*right; 
                     break;
                case '/': 
                    result=left/right; 
                    break;
            }
            push(&top,result);
        }
        else{
            push(&top,atoi(token));//将操作数转换为整数后入栈
        }
        if(getchar()=='\n'){
            break;
        }
    }
    printf("%d\n",pop(&top));
    
    return 0;
}