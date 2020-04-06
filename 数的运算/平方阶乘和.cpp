#include <stdio.h>

int main(){
	
	int a=2;
	int b=3;
	
	c=jiecheng(pingfang(a));
	d=jiecheng(pingfang(b));
	
	
	return 0;
} 
int pingfang(int n){
	
	int num;
	num=n*n;
	return num;
}

int plus(int a,int b){
	
	int sum;
	sum=a+b;
	return sum;
}

int jiecheng(int n){
	
	int i;
	int num=0;
	for(i=1;i<=n;i++){
		num*=i;
	}
	
	return num;
}




