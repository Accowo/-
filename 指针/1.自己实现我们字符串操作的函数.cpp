#include <stdio.h>

char *mystrcopy(char *dst,char *src); 

int main(void){
	
	char dst[10]="hello"; 
	char src[10]="wor";

	printf("dst:%s\n",dst);
	
	printf("src:%s\n",src);
	
	mystrcopy(dst,src);
	
	printf("dst:%s\n",dst);
		
	return 0;
} 
char *mystrcopy(char *dst,char *src){
	
	char *p=dst;
	while(*src!='\0'){
		*dst++=*src++;
	} 
	*dst='\0'; 
	return p;
}

