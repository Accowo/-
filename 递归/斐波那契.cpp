#include <stdio.h>
int Fibonacci(int n); 
int main(void){
	
	int n,i;
	printf("请输入n:"); 
	scanf("%d",&n); 
	printf("斐波那契数列:"); 
	for(i=0;i<n;i++){
		printf("%d ",Fibonacci(i)); 	
	}
	return 0;
}
int Fibonacci(int n){
	
	int t;
	if(n==0||n==1){
		return 1;
	}
	else{
		t=Fibonacci(n-1)+Fibonacci(n-2);
		return t;	
	}
} 
