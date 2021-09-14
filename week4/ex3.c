#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
    char user_command[] = {};
    printf("Enter a command: ");
    scanf("%s",user_command);
    system(user_command);
    return 0;
}