#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>

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
	int max_n = 1000, n;
	int bt[max_n], at[max_n], ct[max_n], wt[max_n], tat[max_n];
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
	
    int current_time_process = at[0];
	for(i = 0; i < n; i++) {
		int shortest_bt = INT_MAX;
		int shortest_bt_id = INT_MAX;
		for(int j = 0; j < n; j++) {
			if(current_time_process >= at[j] && shortest_bt > bt[j] && bt[j] != -1) {
                shortest_bt_id = j;
				shortest_bt = bt[j];
			}	
		}
		current_time_process += bt[shortest_bt_id];
		ct[shortest_bt_id] = current_time_process;
		tat[shortest_bt_id] = ct[shortest_bt_id] - at[shortest_bt_id];
		wt[shortest_bt_id] = tat[shortest_bt_id] - bt[shortest_bt_id];
		bt[shortest_bt_id] = -1;
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