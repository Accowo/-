#include <stdio.h>
#include <string.h>
void move(char buf[],char str[],int n); 
int main(void){
	
	char buf[]="abcdefg";
	char str[20]={'\0'};
	int n;
	printf("字符串:%s\n",buf);
	printf("请输入右移位数n:");
	scanf("%d",&n); 
	
	move(buf,str,n);
	printf("移动后:%s",buf);
	return 0;
} 
void move(char buf[],char str[],int n){
	
	int len=strlen(buf);
	int i=0;
	int j=0;
	n=n%len;
	for(i=len-n;i<len;i++){
		str[j++]=buf[i];
	}
	for(i=0;i<len-n;i++){
		str[j++]=buf[i];
	}
	for(i=0;i<len;i++){
		buf[i]=str[i];
	}
} 
