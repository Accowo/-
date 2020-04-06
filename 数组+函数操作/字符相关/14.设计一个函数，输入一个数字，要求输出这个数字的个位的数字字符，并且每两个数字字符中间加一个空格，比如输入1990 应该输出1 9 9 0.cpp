#include <stdio.h>
void print(int n); 
int j=0; 
int main(void){
	
	int n;
	
	printf("ÇëÊäÈëÊı×Ö:");scanf("%d",&n);
	print(n); 

	return 0;
} 
void print(int n){
	
    if(n<=0){
        return;
    } 
    print(n/10);    
    if(j==0){
		printf("%d",n%10);
		j=1; 
	} 
	else{
		printf(" %d",n%10);
	} 	
}
