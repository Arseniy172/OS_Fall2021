#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc/malloc.h>

void* new_realloc_function(void *ptr, size_t new_size) {
	if(ptr == NULL) {
		return malloc(new_size);
	}
	if(new_size == 0) {
		free(ptr);
		return NULL;
	}
	size_t previous_size = malloc_size(ptr);
	void *new_ptr = malloc(new_size);
    size_t minimum;
    if(previous_size < new_size){
        minimum = previous_size;
    }else{
        minimum = new_size;
    }
	memcpy(new_ptr, ptr,minimum);
	free(ptr);
	return new_ptr;
}

int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		*(a1+i)=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ",*(a1+i) );
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = realloc(a1, (n2*sizeof(int)));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	/*
	Fill
	In
	*/
    size_t maximum;
    if(n2 > n1){
        maximum = n2; 
    }else{
        maximum = n2; 
    }
	

	for(i=0; i<maximum;i++){
		//Print each element out (to make sure things look right)
		printf("%d ",*(a1+i));
	}
	printf("\n");

	free(a1);
	return 0;
}