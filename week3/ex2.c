#include<stdio.h>

void bubble_sort(int array[], int n){
    int tmp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(array[j] < array[i]){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int main(){
    int array[] = {113, 1, 34, 24, 89, 565, 29, 5, 8, 11, 2532, 431};
    int size = sizeof(array)/sizeof(array[0]);
    bubble_sort(array, size);
    for(int i = 0; i < size; i++){
        printf("%d\n",array[i]);
    }
    return 0;
}