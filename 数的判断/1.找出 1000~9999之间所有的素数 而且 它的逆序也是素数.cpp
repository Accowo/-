#include <stdio.h>
#include <math.h> 
int isprime(int n);
int reverse(int n);
int sum=0;
int j=3; 
int main(void){
	
	int i;
	int r; 
	printf("1000~9999之间的素数,且它的逆序也是素数:\n");
	for(i=1000;i<=9999;i++){
		if(isprime(i)==1){
		 	sum=0;
			j=3; 
			r=reverse(i); 
			if(isprime(r)==1){
				printf("%d ",i);
			} 
		}
	}
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
int reverse(int n){

	if(n==0){
		return sum;
	} 
	else{	
		sum+=(n%10)*pow(10,j--);
		reverse(n/10);
	}
} 

