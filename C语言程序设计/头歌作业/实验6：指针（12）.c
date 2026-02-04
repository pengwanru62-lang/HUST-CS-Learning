#include <stdio.h>
void task0(void) {
	printf("task0 is called!\n");
}
void task1(void) {
	printf("task1 is called!\n");
}
void task2(void) {
	printf("task2 is called!\n");
}
void task3(void) {
	printf("task3 is called!\n");
}
void task4(void) {
	printf("task4 is called!\n");
}
void task5(void) {
	printf("task5 is called!\n");
}
void task6(void) {
	printf("task6 is called!\n");
}
void task7(void) {
	printf("task7 is called!\n");
}
void execute(void(*p)()) {
	p();
}
void scheduler(void(*p)(),char c) {
	switch(c-'0') {
		case 0:
			p=task0;
			break;
		case 1:
			p=task1;
			break;
		case 2:
			p = task2;
			break;
		case 3:
			p = task3;
			break;
		case 4:
			p = task4;
			break;
		case 5:
			p = task5;
			break;
		case 6:
			p = task6;
			break;
		case 7:
			p = task7;
			break;
		default:
			break;
	}
	execute(p);
}
int main() {
	char c;
	void (*p)(void);
	while((c=getchar())!=EOF) { //结合性问题，需要先用括号！！！
		scheduler(p,c);//用char和while循环从而可以接收多个字符
	}
	return 0;
}
