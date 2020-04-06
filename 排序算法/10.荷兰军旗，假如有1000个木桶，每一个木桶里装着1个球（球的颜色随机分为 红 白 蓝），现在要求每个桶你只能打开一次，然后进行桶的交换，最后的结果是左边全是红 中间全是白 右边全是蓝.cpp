#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void rand_color(char a[],int len);
void sort(char a[],int len);
void swap(char a[],int i,int j);
void output(char a[],int len);
int main(void){
	
	char a[1000];
	int len=1000;
	
	rand_color(a,len);
	
	printf("交换前:\n");
	output(a,len);
	
	sort(a,len);
	
	printf("交换后:\n");
	output(a,len);
	return 0;
} 
void rand_color(char a[],int len){
	
	int i,t;
	srand(time(NULL));
	for(i=0;i<len;i++){
		t=rand()%3;
		switch(t){
			case 0:a[i]='r';break;
			case 1:a[i]='w';break;
			case 2:a[i]='b';break;
		}
	} 
} 
void sort(char a[],int len){
	
	int i;
	int low=0;
	int high=len-1;
	for(i=0;i<high;i++){
		switch(a[i]){
			case 'r':swap(a,i,low++);break;
			case 'w':break;
			case 'b':swap(a,i--,high--);break;
		}
	} 
	
}
void swap(char a[],int i,int j){
	
	char t;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void output(char a[],int len){
	
	int i;
	for(i=0;i<len;i++){
		switch(a[i]){
			case 'r':printf("红");break;
			case 'w':printf("白");break;
			case 'b':printf("蓝");break;
		}
		if((i+1)%50==0){
			printf("\n");
		} 
	}
}
