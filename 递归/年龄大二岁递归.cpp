#include <stdio.h>
int age(int n);
int main(){
	printf("第五个人的岁数:"); 
	printf("%d",age(5));
	
	return 0;
} 
int age(int n){
	
	if(n==1){
		return 12;
	}
	else{
		return 2+age(n-1);
	}
}

