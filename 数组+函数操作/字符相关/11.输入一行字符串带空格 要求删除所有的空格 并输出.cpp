#include <stdio.h>

int main(){

	char str[40]={'0'};
	char c;
	int len=40;
	int i;
	
	printf("��������ո���ַ�����");
	for(i=0;i<len-1;i++){
		c=getchar();
		if(c!='\n'&&c!=' '){
			str[i]=c;
		}
		else if(c==' '){
			 i--;
		}
		else{
			break;
		}
	}
	printf("���ɾ���ո���ַ�����"); 
	printf("%s",str);
	
	return 0;
} 
