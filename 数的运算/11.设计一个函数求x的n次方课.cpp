#include <stdio.h>
int option(int x,int n);
int main(void){
	
	int x;
	int n;
	printf("������x:");scanf("%d",&x);
	printf("������n:");scanf("%d",&n);
	printf("x��n�η�:%d",option(x,n)); 
	return 0;
} 
int option(int x,int n){
	int s=1;
	while(n--){
		s*=x;
	}
	return s;
}
