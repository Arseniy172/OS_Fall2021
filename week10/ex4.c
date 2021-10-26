#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

#define max 100

struct file_ex{
	char name[max][255]; 
	unsigned int size;
	unsigned long i_node;
};

typedef enum {false, true} bool;

int main(){	
    char dir1[] = ".";
	char dir2[] = "..";
    struct file_ex* fl_exl = malloc(max * sizeof(struct file_ex));
	DIR *directory = opendir("./tmp");
	struct dirent *fl;
	for(int i = 0; i < max; i++) {
		struct file_ex file;
		file.i_node = -1;
		*(i + fl_exl) = file;
	}
	while((fl = readdir(directory)) != NULL) {
        struct stat file_condition;
        bool i_node_condition = false;
        char root[4 + 255] = "tmp/";
		if(strcmp(dir1, fl->d_name) == 0){
            continue;
        } 
		if(strcmp(dir2, fl->d_name) == 0) {
            continue;
        }
		if(file_condition.st_nlink <= 1){ 
            continue; 
        }
		for(int i = 0; i < max; i++) {
			if((i + fl_exl)->i_node == file_condition.st_ino) {
				i_node_condition = true;
				strcat((i + fl_exl)->name[(i + fl_exl)->size], fl->d_name);
				(i + fl_exl)->size += 1;
				break;
			}
		}
		if(!i_node_condition) {
			for(int i = 0; i < max; i++) {
				if((i + fl_exl)->i_node == -1) {
					struct file_ex en;
					en.size = 0;
                    en.i_node = file_condition.st_ino;
					*(i+fl_exl) = en;
					strcat((i + fl_exl)->name[(i + fl_exl)->size], fl->d_name);
					(i + fl_exl)->size += 1;
					break;
				}
			}
		}
	}
	for(int i = 0; i < max; i++){
		if((i + fl_exl)->i_node != -1) {
			printf("i_node's number %lu: ", (i+fl_exl)->i_node);
			for(int j = 0; j < (i+fl_exl)->size; j++) {
				printf("%s ", (i+fl_exl)->name[j]);
			}
		}
	}
	closedir(directory);
	return 0;
}
