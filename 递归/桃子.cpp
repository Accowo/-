#include <stdio.h>
int taozi(int n);
int main(){
	
	printf("��һ��ժ��������:"); 
	printf("%d",taozi(1));
	
	return 0;
} 
int taozi(int n){
	
	if(n==10){
		return 1;
	}
	else{
		return (taozi(n+1)+1)*2;
	}
}

