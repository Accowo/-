#include <stdio.h>
#include <string.h>
int max(char str[10][20],int row); 
int main(void){
	
	char str[10][20];
	int i;
	int k;
	printf("������10���ַ�����\n"); 
	for(i=0;i<10;i++){
		scanf("%s",str[i]);
	}
	k=max(str,10); 
	printf("�����ַ�����%s",str[k]);
	return 0;
}
int max(char str[10][20],int row){
	
	int k,i;
	k=0;
	for(i=0;i<row;i++){
		if(strcmp(str[i],str[k])==1){
			k=i;
		}
	}
	return k;
} 







