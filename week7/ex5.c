#include <stdio.h>
#include <stdlib.h>
int main(){
    //memory allocation is missed in that code
	char **s = malloc(sizeof(char*));
	char foo[] = "Hello World";
	*s = foo;
    //print string as *s
	printf("s is %s\n", *s); 
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	return 0;
}
