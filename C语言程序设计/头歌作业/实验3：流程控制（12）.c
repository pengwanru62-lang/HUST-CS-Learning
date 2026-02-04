#include<stdio.h>
int main() {
	int x;
	scanf("%d",&x);

	int fenmu;
	for(fenmu=1234; fenmu<98765/x; fenmu++) {
		int flag=1;
		int a[10]= {0};
		int temp=fenmu;
		int cnt_fenmu=0;
		while(temp>0) {
			int num=temp%10;
			if(a[num]) {
				flag=0;
				break;
			} else {
				a[num]=1;
				temp/=10;
				cnt_fenmu++;
			}
		}
		if(!flag) continue;
		if(cnt_fenmu<5) {
			if(a[0])flag=0;
			else a[0]=1;
		}
		if(!flag) continue;

		int fenzi=fenmu*x;
		temp=fenzi;
		int cnt_fenzi=0;
		while(temp>0) {
			int num=temp%10;
			if(a[num]) {
				flag=0;
				break;
			} else {
				a[num]=1;
				temp/=10;
				cnt_fenzi++;
			}
		}
		if(!flag)continue;

		if(cnt_fenzi<5) {
			if(a[0])flag=0;
		}
		if(flag) printf("%05d/%05d=%d\n",fenzi,fenmu,x);
	}
	return 0;
}
