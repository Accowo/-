#include <stdio.h>
void del_space(char *src);
int main(void){

	char str[100];
	printf("请输入字符串:");
	gets(str);
	
	del_space(str);
	
	printf("删除空格后:%s",str);
	return 0;
} 
void del_space(char *src){
	
	char *p;
	while(*src!='\0'){
		if(*src==' '){
			p=src; //标记第一个空格位 
			src++;
			while(*src==' '){
				src++;
			}
			*p=*src;  //空格后第一个出现的不是空格的字符赋给之前的空格位 
			if(*src=='\0'){
				break;
			}
			*src=' ';
			src=p+1; 
		}
		else{
			src++;
		} 
	}
} 
