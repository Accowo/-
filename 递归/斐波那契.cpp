#include <stdio.h>
int Fibonacci(int n); 
int main(void){
	
	int n,i;
	printf("������n:"); 
	scanf("%d",&n); 
	printf("쳲���������:"); 
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
