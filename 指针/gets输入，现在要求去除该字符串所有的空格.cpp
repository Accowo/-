#include <stdio.h>
void del_space(char *src);
int main(void){

	char str[100];
	printf("�������ַ���:");
	gets(str);
	
	del_space(str);
	
	printf("ɾ���ո��:%s",str);
	return 0;
} 
void del_space(char *src){
	
	char *p;
	while(*src!='\0'){
		if(*src==' '){
			p=src; //��ǵ�һ���ո�λ 
			src++;
			while(*src==' '){
				src++;
			}
			*p=*src;  //�ո���һ�����ֵĲ��ǿո���ַ�����֮ǰ�Ŀո�λ 
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
