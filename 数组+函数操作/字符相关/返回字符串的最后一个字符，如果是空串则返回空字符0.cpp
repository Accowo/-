#include <stdio.h>
#include <string.h>
char last_character(char str[]);
int main(void){
	
	char str[20]={'\0'};
	printf("�������ַ���:"); 
	scanf("%s",str); 
	printf("�������һ���ַ�:%c",last_character(str));
	return 0;
} 
char last_character(char str[]){
	
	int len = strlen(str);
	if(len==0){
		return '\0';
	}
	else{
		return str[len-1];
	}
}
