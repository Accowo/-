#include <stdio.h>

int main(){

	char str[40]={'0'};
	char c;
	int n;
	int len=40;
	int i;
	
	printf("�����벻����40���ַ����ַ�����");
	for(i=0;i<len-1;i++){
		c=getchar();
		if(c!='\n'){
			str[i]=c;
		}
		else{
			break;
		}
	}
	printf("��������Ҫɾ����λ��");
	scanf("%d",&n); 
	for(i=n-1;str[i]!='\0';i++){
		str[i]=str[i+1];
	}
	
	printf("���ɾ��ָ��λ���ַ�����"); 
	printf("%s",str);
	
	return 0;
} 

