#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum { false, true } bool;

struct page {
	int ID;
	unsigned int memory; 
};

int main() {
	int n;
    unsigned int page_response = 0;
	unsigned int hit = 0;
	unsigned int miss = 0;
    unsigned int minimum = INT_MAX;
	unsigned int index = INT_MAX;

	printf("N:");
	scanf("%d", &n);
	FILE *fptr = fopen("Lab_09_Inputs.txt", "r");
	struct page* pages = malloc(n * sizeof(struct page));

    //Initializing pages
	for(int i = 0; i < n; i++) {
		struct page tmp_page;
		tmp_page.ID = NULL;
        tmp_page.memory = 0;
		*(pages + i) = tmp_page;
	}

    while (fscanf(fptr, "%d", &page_response) == 1){
        bool exists = false;
        for(int i = 0; i < n; i++) {
        	if((pages + i)->ID == page_response) {
        		hit += 1;
        		exists = true;
        		break;
			}
		}
		if(!exists) {
            miss += 1;
			bool dom = false;
			for(int i = 0; i < n; i++) {
				if((pages + i)->ID == NULL) {
                    dom = true;
					struct page n;
					n.ID = page_response;
					n.memory = 0;
					*(pages + i) = n; 
					break;
				}
			}
			if(!dom) {
				for(int i = 0; i < n; i++) {
					if(minimum > (pages + i)->memory) {
                        index = i;
						minimum = (pages + i)->memory;
					}
				}
                struct page n;
				n.ID = page_response;
				n.memory = 0;
				*(pages + index) = n;
			}
		}
		for(int i = 0; i < n; i++) {
			(pages + i)->memory = (pages + i)->memory >> 1;
			if(exists && page_response == (pages + i)->ID) {
				(pages + i)->memory =  (pages + i)->memory | 1 << 31;
			}
		}
    }
   	printf("Hits = %u\n", hit);
   	printf("Misses = %u\n", miss);
   	printf("Hits / Misses ratio = %f\n", ((float) hit / (float) miss));
    free(pages);
   	fclose(fptr);
	return 0;
}