#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char user_command[] = {};
    printf("Enter a command: ");
    gets(user_command);
    int n = strlen(user_command);
    char new_command[] = {};
    // & symbol in Linux means that process has to be run in background
    if(user_command[n-1] == '&'){
        //run process in background
        fork();
        system(user_command);
    }else{
        system(user_command);
    }
    return 0;
}
