#include <stdio.h>
#include <stdlib.h>

int main(){
	int* alloc;
	int n, i;
	printf("Enter number of elements:");
	scanf("%d",&n);
	alloc = (int*)malloc(n * sizeof(int));
    printf("Memory is allocated\n");
    for (i = 0; i < n; ++i) {
        alloc[i] = i;
    }
	printf("The elements of the array are: ");
	for (i = 0; i < n; ++i) {
        if(i < n-1)
		    printf("%d, ", alloc[i]);
        else
            printf("%d \n", alloc[i]);
	}
    free(alloc);
    printf("Memory is deallocated\n");
	return 0;
}
