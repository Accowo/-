#include <stdio.h>
#include <string.h>
void reverse(char str[]);
int main(void){
	
	char str[]="abcdefg";
	printf("�ַ���:%s\n",str);
	
	reverse(str);
	printf("��ת�ַ���:%s",str); 
	
	return 0;
} 
void reverse(char str[]){
	
	int len = strlen(str);
	int i;
	char t;
	for(i = 0;i < len/2;i++){
		t = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = t;
	}
} 
