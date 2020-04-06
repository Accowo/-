#include <stdio.h>
void order_print(int n);
int main(){
	
	int n;
	printf("请输入一个正整数:");
	scanf("%d",&n); 
	printf("正序打印:\n"); 
	order_print(n);
	
	return 0;
} 
void order_print(int n){
    if (n <= 0){
        return ;
    } 
	order_print(n / 10);
    printf("%d\n", n % 10);                                  //上下两行交换位置，即可实现正序逆序打印 
}
