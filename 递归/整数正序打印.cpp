#include <stdio.h>
void order_print(int n);
int main(){
	
	int n;
	printf("������һ��������:");
	scanf("%d",&n); 
	printf("�����ӡ:\n"); 
	order_print(n);
	
	return 0;
} 
void order_print(int n){
    if (n <= 0){
        return ;
    } 
	order_print(n / 10);
    printf("%d\n", n % 10);                                  //�������н���λ�ã�����ʵ�����������ӡ 
}
