#include <stdio.h>

int main(void){
	
	char str[40]="computer" ;
	char *p=str;
	printf("�ַ���:%s\n",str);
	printf("������:");
	while(*p!='\0'){
		printf("%c",*p);
		p+=2;
	}

	return 0;
} 
