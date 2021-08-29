#include <stdio.h>

void swap(int *i1,int *i2){
    int p1 = *i1;
    *i1 = *i2;
    *i2 = p1;
}

int main(void){
    int i1, i2;
	printf("Enter two integers: ");
    scanf("%i %i", &i1, &i2);
    swap(&i1,&i2);
    printf("Integers afer swapping: %i %i", i1, i2);
	return 0;
}