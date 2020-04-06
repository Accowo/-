#include <stdio.h>
int is_even(int n); 
void output(int a[],int len); 
int main(void){
	
	int a[10]={1,2,3,4,5,6,7,8,9,10}; 
	int n=10;
	int c=0;
	int i;
	for(i=0;i<10;i++){
		if(is_even(i)==1){
			c++;
		}
	}
	printf("数组:"); 
	output(a,n);
	printf("偶数的个数:%d",c);
	return 0;
} 
int is_even(int n){
	if(n%2==0){
		return 1;
	}
	else{
		return 0;
	}
} 
void output(int a[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
