#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define N 100 

void strsort ( char *s[ ],int size )
{ 
    char *temp; 
    int i, j ;
    char **p,**q;
    for(p=s;p<s+size-1;p++){
        for(q=s;q<s+size-1-(p-s);q++){
            if(strcmp(*q,*(q+1))>0){
                temp=*q;
                *q=*(q+1);
                *(q+1)=temp;
            }
        }
    }
 }

int main( )
{ 
    int i;
    int n;
    scanf("%d",&n);
    getchar();
    char **s, t[50]; 

    s=(char **)malloc(n*sizeof(char *));
    if(s==NULL)return 1;
    for(i=0;i<n;i++)   
{
       gets(t);
       s[i] = (char *)malloc(strlen(t)+1);
       if(s[i]==NULL) return 1;

       strcpy(s[i],t); 
    }
    strsort(s,n);    
    for(i=0;i<n;i++)  puts(s[i]);
    return 0;
}


