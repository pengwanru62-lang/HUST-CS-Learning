/******************  begin *********************/
#include <stdio.h>
#define R
#define PY 3.14159
int integer_fraction(float x){
	int i=(int)(x+0.5);
	return i;
}
int main(){
	float r,s;
	int s_integer=0;
	scanf("%f",&r);
	#ifdef R
	s=PY*r*r;
	s_integer=integer_fraction(s);
	//assert((s-s_integer)<0.5);
	printf("The integer fraction of area is %d",s_integer);
	#endif
	return 0;
}



/******************   end  *********************/
