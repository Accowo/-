#include <stdio.h>
void print(int n);
int main(){
	
	int n;
	printf("������һ��������:");scanf("%d",&n); 
	print(n);
	
	return 0;
} 
void print(int n){
    if (n <= 0){
        return ;
    } 
	printf("%d\n", n % 10);
    print(n / 10);                  //�������н���λ�ã�����ʵ�����������ӡ 
  
}
