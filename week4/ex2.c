#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    for(int i = 0; i < 5; i++){
        fork();
        sleep(5);
    }
    return 0;
}
//Comments 
// By running "pstree" command every 5 seconds, while program is processing fork(), 
// we can detect a new process with new PID. Overall amount of processes, which I got, is 62.  