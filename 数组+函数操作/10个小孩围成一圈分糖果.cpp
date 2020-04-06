#include <stdio.h>
int check(int a[],int n);
void array_candy_share(int a[],int b[],int n); 
void output(int a[],int n);
int main(){
	
	int a[10]={12,2,8,22,16,4,10,6,14,20};
	int b[10]={0};
	int n=10;
	int i;		
	int count=0;
	
	printf("开始时各个小朋友的糖果数:");
	output(a,n);
	while(check(a,n)!=1){
		array_candy_share(a,b,n);
		for(i=0;i<10;i++){
			a[i]+=b[i];
			if(a[i]%2!=0){
				a[i]++;
			}
		}
		count++;
		printf("第%d次分饼干后各个小朋友的糖果数:",count); 
		output(a,n);
	}
	printf("糖果一样多时,调整的次数:%d\n",count); 
	printf("每人糖果数:%d",a[0]);
	return 0;
} 
int check(int a[],int n){
	int i;
	for(i=0;i<n-1;){
		if(a[i]==a[i+1]){
			i++;
		}
		else{
			break;
		}
	}
	if(i==n-1){
		return 1;
	}
	else{
		return 0;
	}
}
void array_candy_share(int a[],int b[],int n){
	
	int i;
	for(i=0;i<n;i++){
		if(i==0){
			b[i]=a[n-1]/=2;
		}
		else{
			b[i]=a[i-1]/=2;
		}
	}
}
void output(int a[],int n){
	
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
} 
