#include <stdio.h>
#include <string.h>
#define CHANGE 0

int main(void)
{	
	char a[1000];
	fgets(a,sizeof(a),stdin);
    #if CHANGE
    int i;
    for(i=0;i<sizeof(a)&&a[i]!='\0';i++){
    	if((a[i]>='A')&&(a[i]<='Z')){
    		a[i]='a'+(a[i]-'A');
		}else if((a[i]>='a')&&(a[i]<='z')){
    		a[i]='A'+(a[i]-'a');
		}
	}
	printf("%s",a);
    #else 
    printf("%s",a);
	#endif 
    return 0;
}
