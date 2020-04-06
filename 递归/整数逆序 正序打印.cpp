#include <stdio.h>
void print(int n);
int main(){
	
	int n;
	printf("请输入一个正整数:");scanf("%d",&n); 
	print(n);
	
	return 0;
} 
void print(int n){
    if (n <= 0){
        return ;
    } 
	printf("%d\n", n % 10);
    print(n / 10);                  //上下两行交换位置，即可实现正序逆序打印 
  
}
