#include <stdio.h>
int is_odd(int n);
int main(void){
	int i;
	int sum=0;
	for(i=1;i<=100;i++){
		if(is_odd(i)==1){
			sum+=i;	
		}
	}
	printf("1~100所有奇数的和:%d",sum); 
	return 0;
} 
int is_odd(int n){
	if(n%2!=0){
		return 1; 
	} 
	else{
		return 0; 	
	} 
} 
