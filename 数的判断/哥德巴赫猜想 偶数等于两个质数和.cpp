#include <stdio.h>
#include <math.h> 
int isprime(int n);
void collect_prime(int prime[]);
int main(void){
	
	int i=0;
	int n;
	int t;
	int prime[50000]={0};
	collect_prime(prime);
	printf("请输入4~100000的一个偶数:"); 
	scanf("%d",&n); 
	do{
		t=n-prime[i];
		if(isprime(t) == 1){
			printf("%d=%d+%d\n",n,prime[i],t);
			break;
		} 
		i++;
	}while(n>prime[i]);

	return 0;
} 
int isprime(int n){
	
	int i;
	if(n==1||n==0){
		return 0;;
	}
	else if(n==2){
		return 1;
	}
	else if(n%2==0){
		return 0;
	}
	else {
		for(i=3;i<=sqrt(n);i+=2){
			if(n%i==0){
				return 0;
			}
		}	
	}
	
	return 1;
}
void collect_prime(int prime[]){
	
	int i;
	int j=0;
	for(i=0;i<50000;i++){
		if(isprime(i) == 1){
			prime[j++]=i;
		}
	}
	
}
