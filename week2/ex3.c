#include <stdio.h>
int main(int argc, char *argv[]){
    int n, spaces, stars_start, stars_end;
	sscanf(argv[1], "%d", &n);
	int target = (2*n-1)/2+1;
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= (2*n-1); i++){
			spaces = (2*n-1)-(2*k-1);
			stars_start = n-(2*k-2)/2;
			stars_end = n+(2*k-2)/2;
			if(i >= stars_start && i <= stars_end)
				printf("*");
			else
				printf(" ");
			
		}
		printf("\n\n");
	}
	return 0;
}