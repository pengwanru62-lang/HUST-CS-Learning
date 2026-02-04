#include <stdio.h>
int main(){
	enum month {
	Jan=1,Feb,Mar,Apr,May,Jun,
	Jul,Aug,Sep,Oct,Nov,Dec
	};
	
	int year;
	scanf("%d",&year);
	
	int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
	
	if((year%4==0)&&(year%100!=0)||(year%400==0)){
	days[Feb]=29;			
	}
	
	enum month m=Jan;
	for (m;m<=Dec;m++){
		switch(m){
			case Jan:printf("Jan: %d\n",days[m]);break;
			case Feb:printf("Feb: %d\n",days[m]);break;
			case Mar:printf("Mar: %d\n",days[m]);break;
			case Apr:printf("Apr: %d\n",days[m]);break;
			case May:printf("May: %d\n",days[m]);break;
			case Jun:printf("Jun: %d\n",days[m]);break;
			case Jul:printf("Jul: %d\n",days[m]);break;
			case Aug:printf("Aug: %d\n",days[m]);break;
			case Sep:printf("Sep: %d\n",days[m]);break;
			case Oct:printf("Oct: %d\n",days[m]);break;
			case Nov:printf("Nov: %d\n",days[m]);break;
			case Dec:printf("Dec: %d\n",days[m]);break;
		}
			
	}
	return 0;
}
