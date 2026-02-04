#include <stdio.h>
// 16½øÖÆ×Ö·û°üÀ¨£º0-9£¬a-f£¬A-F 
int main(){
	char a;
	int ans;
	scanf("%c",a);
	if((a>='0'&&a<='9')||(a>='a'&&a<='z')||(a>='A'&&a<='Z')){
		if (a>='0'&&a<='9'){
			ans=a-'0';			
		} else if(a>='a'&&a<='z'){
			ans=a-'a'+10;
		} else {
			ans=a-'A'+10;
		}
	} else{
		ans=a;
	}
	printf("%d",ans);
	return 0;

	
	
}
