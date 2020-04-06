#include <stdio.h>
int taozi(int n);
int main(){
	
	printf("第一天摘的桃子数:"); 
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

