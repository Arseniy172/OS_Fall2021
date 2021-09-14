#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    pid_t pid = fork(); // fork already returns child PID
    printf("Hello from parent %d\n",getppid());
    printf("Hello from child %d\n",pid);
    return 0;
}

//Comments for the output for n = 10:
// If we will run this script 10 times we will see that
// two first processes (child and parent) returns real IDs of them
// but next two IDs are equal to 1 (for parent) and 0 (for child).
// This can be explained in the way that when pid is equal to 1
// then it means that parent process exit without request to its child process for return value.
// When pid is equal to 0, which just a marker, PID of child can be got by getpid(), it means that fork   
// has created a new child process.
