#include <stdio.h>
int option(int x,int n);
int main(void){
	
	int x;
	int n;
	printf("请输入x:");scanf("%d",&x);
	printf("请输入n:");scanf("%d",&n);
	printf("x的n次方:%d",option(x,n)); 
	return 0;
} 
int option(int x,int n){
	int s=1;
	while(n--){
		s*=x;
	}
	return s;
}
