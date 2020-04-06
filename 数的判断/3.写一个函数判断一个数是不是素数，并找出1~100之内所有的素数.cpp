#include <stdio.h>
#include <math.h>
int isprime(int n); 
int main(void){
	
	int i;
	printf("1~100之内所有的素数:\n");
	for(i=0;i<=100;i++){
		if(isprime(i)==1){
			printf("%d ",i);
		}
	}
	
	return 0;
} 
int isprime(int n){
	
	int i, j;
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

