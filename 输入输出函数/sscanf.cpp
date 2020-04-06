#include <stdio.h>

int main(void){
	char buf[20];
	
	sscanf("hello, world", "%*s%s", buf);
 
printf("%s\n",buf);

	
	return 0;
} 
