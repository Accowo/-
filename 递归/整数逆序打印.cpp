#include <stdio.h>
void reverse_print(int n);
int main(){
	
	int n;
	printf("������һ��������:");
	scanf("%d",&n); 
	printf("�����ӡ:\n"); 
	reverse_print(n);
	
	return 0;
} 
void reverse_print(int n){
    if (n <= 0){
        return ;
    } 
	printf("%d\n", n % 10);
    reverse_print(n / 10);                                   //�������н���λ�ã�����ʵ�����������ӡ 
}
