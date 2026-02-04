#include<stdio.h>
/**********  Begin  **********/
struct date {
	int year;
	int month;
	int day;
};
int main() {
	int y,m,d;
	scanf("%d %d %d",&y,&m,&d);

	struct date current= {y,m,d};

	int days[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

	if((y%4==0)&&(y%100!=0)||(y%400==0)) {
		days[2]=29;
	}

	if((d>days[m])||d<1) {
		printf("不存在这样的日期\n");
		return 0;
	}

	if(m>12||m<1) {
		printf("不存在这样的日期\n");
		return 0;
	}

	if(y<1) {
		printf("不存在这样的日期\n");
		return 0;
	}

	int sum=0;
	int i;
	for(i=1; i<m; i++) {
		sum+=days[i];
	}
	sum+=d;

	printf("%d\n",sum);
	/**********   End   **********/
	return 0;
}
