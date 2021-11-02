#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>

int main (void){
    struct dirent *tk;
	DIR *directory;
    directory = opendir("./");
	printf("List of files: \n");
	while ((tk = readdir(directory)) != NULL){
		printf("%s\n", tk->d_name);
	}
	printf("\n");
	closedir(directory);
	return (-1);
}