#include <stdio.h>
#include <stdlib.h>

int main(){
  int *pointer = NULL;
  int mb = 1024*1024;
  size_t memory = 0;
  for(int i = 0; i< 10; i++){
    memory += 10 * mb;
    pointer = realloc(pointer,memory);
    memset(pointer,0,memory);
    printf("Current memory size: %lu \n", (memory/mb));
    sleep(1);
  }
  free(pointer);
  printf("DONE\n");
  return 0;
}

/*
Ex2:

During the launch of the program in the background and running a
command 'vm_stat 1' size of memory was increasing, while program was adding
10 MB per second. There was no swapped memory

Ex3:

By launching a command 'top -d 1' parameter "active" was increasing as program
requires more memory every second
*/
