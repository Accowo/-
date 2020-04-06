#include <stdio.h>
#include <string.h>
char last_character(char str[]);
int main(void){
	
	char str[20]={'\0'};
	printf("请输入字符串:"); 
	scanf("%s",str); 
	printf("返回最后一个字符:%c",last_character(str));
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
