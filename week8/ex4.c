#include <stdlib.h>
#include <stdio.h>
#include <sys/resource.h>

int main(){
  int *pointer = NULL;
  struct rusage use;
  int mb = 1024 * 1024;
  size_t memory = 0;
  for(int i = 0; i < 10; i++){
    memory += 10*mb;
    pointer = realloc(pointer,memory);
    memset(pointer,0,memory);
    getrusage(RUSAGE_SELF, &use);
    printf("Memory in process: %ld\n", use.ru_maxrss);
    printf("Soft page faults = %ld\n", use.ru_minflt);
    printf("Hard page faults = %ld\n", use.ru_majflt);
    printf("\n");
    sleep(1);
  }
  free(pointer);
  printf("DONE");
}
