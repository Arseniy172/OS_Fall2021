#include <stdio.h> 
#include <stdlib.h>

void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void bubbleSort(int arr[], int bur_arr[], int n) { 
   for (int i = 0; i < n-1; i++){       
   		for (int j = 0; j < n-i-1; j++){  
        	if (arr[j] > arr[j+1]) {
            	swap(&arr[j], &arr[j+1]); 
            	swap(&bur_arr[j], &bur_arr[j + 1]);
			}
        }
   }
}  

int main() { 
	int mn = 1000, n;
	int bt[mn], at[mn], ct[mn], wt[mn], tat[mn];
    float avt = 0, awt = 0;
	
  	printf("Enter number of processes:");
  	scanf("%d", &n);
    printf("Enter Arrival time and Burst time for each process:\n\n");

  	int i, counter = 1;
  	for(i = 0; i < n*2; i++) {
        if(i % 2 == 0){
  		    printf("Arrival time of process [%d]:", counter);
            scanf("%d", &at[counter-1]);
            printf("\n");
        }else{
  		    printf("Burst time of process [%d]:", counter);
            scanf("%d", &bt[counter-1]);
            printf("\n");
            counter++;
        }
	}
  	
    bubbleSort(at, bt, n);
	
	for(i = 0; i < n; i++) {
		if(i > 0){
            ct[i] = bt[i] + ct[i - 1];
		}else{
			ct[i] = bt[i];
		}
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
	}

	for(i = 0; i < n; i++) {
		avt += tat[i];
		awt += wt[i];
	}
	
	avt /= n;
	awt /= n;

    printf("P#    AT    BT    CT    TAT    WT");
	printf("\n");
	for(i = 0; i < n; i++) {
		printf("\n");
		printf("P%d    %d     %d     %d     %d      %d", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
		printf("\n");
	}
	
	printf("Average Turnaround Time = %f\n", avt);
	printf("Average WT = %f", awt);
  	
    return 0; 
} 