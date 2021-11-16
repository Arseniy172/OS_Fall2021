#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int inspect(int A[3], int R[3]){
	for (int j = 0; j < 3; j++){
		if (A[j] < R[j])
			return 0;
	}
	return 1;
}

int main (void){
	FILE *fptr;
	fptr = fopen("input.txt", "r");
    int proceed = 1;
    int p_foregoing[5] = {0, 0, 0, 0, 0};
	int E[3];
	int A[3];
	int C[5][3];
	int R[5][3];
	int P[5] = {0, 0, 0, 0, 0};
	fscanf(fptr, "%d %d %d \n \n%d %d %d \n", &E[0], &E[1], &E[2], &A[0], &A[1], &A[2]);
	for (int i = 0 ; i < 5; i++){
		for (int j = 0; j < 3; j++){
			fscanf(fptr, "%d", &C[i][j]);
		}
	}
	for (int i = 0 ; i < 5; i++){
		for (int j = 0; j < 3; j++){
			fscanf(fptr, "%d", &R[i][j]);
		}
	}
	while (proceed){
		for (int i = 0; i<5; i++){
			int is_able_end = inspect(A, R[i]);
			printf("i -> %d, process is finished -> %d, result of inspect function - > %d\n", i, P[i], is_able_end);
			if (is_able_end){
				for (int j = 0; j < 3; j++){
					A[j] += C[i][j];
				}
				P[i] = 1;
			}
		}
		proceed = 0;
		for (int i = 0; i < 5; i++){
			if (P[i] != p_foregoing[i]){
				proceed = 1;
				p_foregoing[i] = P[i]; 
			}
		}
		printf("\n");
	}
	fclose(fptr);
	fptr = fopen("output.txt", "w");
	int deadlock_alive = 0;
	for (int i = 0; i < 5; i++){
		if (P[i] == 0){
			deadlock_alive += 1;
		}
	}
	if (deadlock_alive == 0)
		fprintf(fptr, "No procces deadloked");
	if (deadlock_alive == 1){
		fprintf(fptr, "Process");
		for (int i = 0; i < 5; i++)
			if (P[i] == 0)
				fprintf(fptr, " %d deadlocked", i);
	}
	if (deadlock_alive > 1){
		fprintf(fptr, "Processes");
		for (int i = 0; i < 5; i++)
			if (P[i] == 0)
				fprintf(fptr, " %d", i);
		fprintf(fptr, " deadlocked");
	}
	fclose(fptr);
	return 0;
}