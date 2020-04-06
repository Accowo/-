#include <stdio.h>

int main(){

	char str[40]={'0'};
	char c;
	int n;
	int len=40;
	int i;
	
	printf("请输入不超过40个字符的字符串：");
	for(i=0;i<len-1;i++){
		c=getchar();
		if(c!='\n'){
			str[i]=c;
		}
		else{
			break;
		}
	}
	printf("请输入需要删除的位：");
	scanf("%d",&n); 
	for(i=n-1;str[i]!='\0';i++){
		str[i]=str[i+1];
	}
	
	printf("输出删除指定位的字符串："); 
	printf("%s",str);
	
	return 0;
} 

