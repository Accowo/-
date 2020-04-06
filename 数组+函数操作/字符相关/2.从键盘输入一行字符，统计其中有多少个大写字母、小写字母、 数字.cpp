#include <stdio.h>
#include <string.h>
int isCapital(char c);
int islower_ease(char c);
int isnumber(char c);
int main(){
	
	char str[20]={0};
	printf("请输入字符：");scanf("%s",str);
	int len=strlen(str);
	int x=0,y=0,z=0;
	int i;
	
	for(i=0;i<len;i++){
		if(isCapital(str[i])==1){
			x++;
		}
		else if(islower_ease(str[i])==1){
			y++;
		}
		else if(isnumber(str[i])==1){
			z++;	
		}
		else{
			;
		}	
	} 
	printf("大写字母：%d个\n小写字母：%d个\n数字：%d个\n",x,y,z);
	return 0;
} 
int isCapital(char c){
	
	if(c>='A'&&c<='Z'){
		return 1;
	}
	return 0;
}
int islower_ease(char c){
	
	if(c>='a'&&c<='z'){
		return 1;
	}
	return 0;
}
int isnumber(char c){
	
	if(c>='0'&&c<='9'){
		return 1;
	}
	return 0;
}





