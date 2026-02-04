 #include <stdio.h>
int main(){
	char a;
	int zi=0,zifu=0,hang=0;
	while((a=getchar())!=EOF){
		if(a=='\n'){
			hang++;
		}
		if(a<0){
			zi++;
			zifu++;
			getchar();
			getchar();
		}
		if((a>='a'&&a<='z')||(a>='A'&&a<='Z')){
			do{
				zifu++;
				a=getchar();
			}while(a!=' '&&a!='\n');
			zi++;
			if(a=='\n'){
				hang++;
			}
		}
	} 
	printf("字数 %d\n",zi);
	printf("字符数 %d   (字符数不计空白符)\n",zifu);
	printf("行数 %d\n",hang);
	return 0;
} 
