#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define BUFFRE_SIZE 10

int get_lines(){
    FILE *fp;
    int count = 0;
    char c;
    fp = fopen("ex3.txt", "r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;
    return count;
}

void write_to_buffer(){
   FILE *fp;
   fp = fopen("ex3.txt", "a");
   fprintf(fp, "INSERTED_DATA\n");
   fclose(fp);
}

void remove_from_buffer(){
    FILE *ifp;
    char word[] = {'I','N','S','E','R','T','E','D','_','D','A','T','A'}, ch, read[1000], replace[] = "";
    int word_len, i, p = 0;
    ifp = fopen("ex3.txt", "r");
    rewind(ifp);
    fscanf(ifp, "%s", read);
    if (strcmp(read, word) == 0) {
        strcpy(read, replace);
    }
}

void *producer(void *thread_id){
    long tid;
    tid = (long)thread_id;
    if(get_lines() < BUFFRE_SIZE){
        printf("Inserting data to buffer -- producer\n");
        write_to_buffer();
    }else{
        printf("Producer is going to sleep\n");
        pthread_exit(NULL);
    }
    return NULL;
}

void *consumer(void *thread_id){
    long tid;
    tid = (long)thread_id;
    if(get_lines() > 0){
        printf("Deleting data to buffer -- consumer\n");
        remove_from_buffer();
    }else{
        printf("Consumer is going to sleep\n");
        pthread_exit(NULL);
    }
    return NULL;
}

int main(int argc, char const *argv[]){
    pthread_t producer_thread;
    pthread_t consumer_thread;
    while(1==1){
        pthread_create(&producer_thread, NULL, producer, NULL); 
        pthread_join(producer_thread, NULL);
        pthread_create(&consumer_thread, NULL, consumer, NULL); 
        pthread_join(consumer_thread, NULL);
        sleep(1);
    }

    return 0;
}
