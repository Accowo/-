#include <stdio.h>

int main(void){
	
	char str[40]="computer" ;
	char *p=str;
	printf("×Ö·û´®:%s\n",str);
	printf("¼ä¸ôÊä³ö:");
	while(*p!='\0'){
		printf("%c",*p);
		p+=2;
	}

	return 0;
} 
