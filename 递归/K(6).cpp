#include <stdio.h>
int series_k(int n); 
int main(void){
	
	int n,i;
	printf("请输入n:");scanf("%d",&n); 
	printf("数列:");
	for (i = 1;i <= n;i++){
		printf("%d ",series_k(i));
	}
	printf("\n所以第%d项是%d",n,series_k(n));
	return 0;
} 
int series_k(int n){
	
	if (n == 1){
		return 1;
	}
	else if(n%2==0){
		return series_k(n-1)*2;
	}
	else{
		return series_k(n-1)*3;
	}
}
