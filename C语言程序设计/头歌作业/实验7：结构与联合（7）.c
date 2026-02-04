/*测试程序定义了如下结点类型
typedef struct c_node{
    char data;  struct c_node *next;
} C_NODE;
*******************************/
void createLinkList(C_NODE **headp, char s[]) 
{
/************************************* BEGIN *******************************************/
/* 按字符串 s 顺序创建单链表，每个字符一个结点 */
C_NODE *head;
head=(C_NODE*)malloc(sizeof(C_NODE));
*headp=head;
head->data=s[0];
for(int i=1;s[i]!='\0';i++){
    /* 为后续字符依次追加新结点 */
    head->next=(C_NODE *)malloc(sizeof(C_NODE));
    head=head->next;
    head->data=s[i];
}
head->next=NULL;

   


/************************************* BEGIN *******************************************/
}

void judgePalindrome(C_NODE *head)
{
/************************************* BEGIN *******************************************/
/* 反转拷贝一份链表，再逐节点对比判断是否回文 */
C_NODE *p,*new1,*headp;
p=head;
headp=NULL;
while(p!=NULL){
    /* 头插法生成逆序链表 */
    new1=(C_NODE *)malloc(sizeof(C_NODE));
    new1->data=p->data;
    new1->next=headp;
    headp=new1;
    p=p->next;
}
int a=0;
while(head!=NULL){
    /* 逐节点比较原链表与逆序链表 */
    if(headp->data!=head->data){
        a=1;
        break;
    }
    head=head->next;
    headp=headp->next;
}
if(a==1){
    printf("false");
}
else{
    printf("true");
}



/************************************* BEGIN *******************************************/
}