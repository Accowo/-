#include <stdio.h>
#include <string.h>
int only_num_points(char buf[]);
int islength_ok(char buf[]);
int isthree_points(char buf[]);
int noAdjacent_points(char buf[]);
int no_first_last_points(char buf[]);
int Correct_scope(int a,int b,int c,int d,int e[]);
int main(void){
	
	char buf[]="192.168.2.1";
	int a,b,c,d;
	sscanf(buf,"%d.%d.%d.%d",&a,&b,&c,&d);
	int e[4]={a,b,c,d};
	int i;
	int flag;
	printf("IP:%s\n",buf);
	if(only_num_points(buf) == 0){
		flag=0;
	}
	else if(islength_ok(buf) == 0){
		flag=0;
	}
	else if(isthree_points(buf) == 0){
		flag=0;
	}
	else if(noAdjacent_points(buf) == 0){
		flag=0;
	}
	else if(no_first_last_points(buf) == 0){
		flag=0;
	}
	else if(Correct_scope(a,b,c,d,e) == 0){
		flag=0;
	}
	else{
		flag=1;
	}
	if(flag == 1){
		printf("正确IP表达式!");
	}		
	else{
		printf("错误IP表达式!");
	}
	return 0;
} 
int only_num_points(char buf[]){
	int len=strlen(buf);
	int i;
	for(i=0;i<len-1;i++){
		if ( buf[i]!='.' && (buf[i]<'0' || buf[i]>'9') ){
			return 0;
		}
	}
	return 1;
}
int islength_ok(char buf[]){
	int len=strlen(buf);
	if(len<7 &&len>15){
		return 0; 
	}
	return 1; 
}
int isthree_points(char buf[]){
	int len=strlen(buf);
	int i;
	int count=0; 
	for(i=0;i<len-1;i++){
		if(buf[i]=='.'){
			count++;
		}
	}
	if(count!=3){
		return 0;
	}
	return 1;
}
int noAdjacent_points(char buf[]){
	int len=strlen(buf);
	int i;
	for(i=0;i<len-2;i++){
		if(buf[i]=='.' && buf[i+1]=='.'){
			return 0;
		}
	}
	return 1;
}
int no_first_last_points(char buf[]){
	int len=strlen(buf);
	int i;
	if(buf[0]=='.' || buf[len-1]=='.'){
		return 0;
	}
	return 1;
}
int Correct_scope(int a,int b,int c,int d,int e[]){
	int i;
	for(i=0;i<4;i++){
		if(e[i]>255){
			return 0; 
		} 
	}
	return 1; 
}
