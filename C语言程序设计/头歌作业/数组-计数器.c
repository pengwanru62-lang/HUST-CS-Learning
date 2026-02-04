#include<stdio.h>
#include<ctype.h>
int main()
{
	/**********  Begin  **********/
	char str[1024];
    int digit[10]={0};
    int letter[26]={0};
    int others=0;

    fgets(str,sizeof(str),stdin);//fgets»á¶ÁÈë»»ÐÐ·û

    for(int i=0;str[i];i++){
        if(str[i]>='0'&&str[i]<='9'){
            char temp=str[i];
            digit[temp-'0']++;
        }
        else if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            char ch=toupper(str[i]);
            letter[ch-'A']++;
        }
        else if(str[i]!='\n')others++;
    }

    for(int i=0;i<10;i++){
        if(digit[i])printf("%d:%d\n",i,digit[i]);
    }
    for(int i=0;i<26;i++){
        if(letter[i]){
            printf("%c:%d\n",'A'+i,letter[i]);
        }
    }
    if(others){
        printf("others:%d\n",others);
    }

	
	/**********  End  **********/
	return 0; 
}

