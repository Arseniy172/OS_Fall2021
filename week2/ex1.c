#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void){
	int x = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	printf("Maximum value of type INT: %d\n",x);
	printf("Maximum value of type FLOAT: %f\n",f);
	printf("Maximum value of type DOUBLE: %f\n\n",d);
	printf("Size of the maximum value of type INT: %lu\n",sizeof(x));
	printf("Size of the maximum value of type FLOAT: %lu\n",sizeof(f));
	printf("Size of the maximum value of type DOUBLE: %lu\n",sizeof(d));
	return 0;
}