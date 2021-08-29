#include <stdio.h>
#include <string.h>
int main(void){
    char input_string[] = "";
	printf("Enter any string: \n");
    gets(input_string);
    printf("Your reversed string is: ");
    for (int i = 0; i < strlen(input_string); i++){
        printf("%c",input_string[strlen(input_string)-i-1]);
    }
	return 0;
}