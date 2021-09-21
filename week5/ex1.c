#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_func(void *thread_id){
    long tid;
    tid = (long)thread_id;
    printf("thread %d is in progress... \n",tid);
    pthread_exit(NULL);
    printf("thread %d is dead... \n",tid);
    return NULL;
}

int main(int argc, char const *argv[]){
    char *p;
    int n = strtol(argv[1], &p, 10);
    pthread_t thread_ID[n];
    for(int i = 1; i <= n;i++){
        int res = pthread_create(&thread_ID, NULL, thread_func, (void *)i); 
        if(res == 0){
            printf("Thread with ID %d is in process of creation...\n", i);
        }
        sleep(1);
        pthread_join(thread_ID, NULL);
    }
    return 0;
}


// Explanations:
// To let threads create, execute and exit one-by-one, it is necessary to use pthread_join() function.