#include <stdio.h>
int array(int a[],int len); 
int binary_search(int a[],int low,int high,int num,int *p); 
int main(void){
	
	int a[100];
	int n;
	int t;
	int count=0; 
	array(a,100);
	printf("������Ҫ���ҵ���:");
	scanf("%d",&n);
	t = binary_search(a , 0 , 99 , n , &count); 
	if(t == -1){
		printf("û���ҵ�!��������%d��", count);
	}
	else{
		printf("�ҵ���!�±���%d,��������%d��", t , count);
	}
	return 0;
} 
int array(int a[],int len){
	
	int i;
	for(i = 0;i < len;i++){
		a[i] = 2 * (i + 1);
	}
}
int binary_search(int a[],int low,int high,int num,int *p){
	
	int mid;
	if(low > high){
		return -1;
	}
	
	mid = (high + low) / 2; 
	(*p)++;
	if(a[mid] == num){
		return mid;
	}
	
	else if(a[mid] > num){
		return binary_search(a,low,mid-1,num,p);
	}
	
	else if(a[mid] < num){
		return binary_search(a,mid+1,high,num,p);
	}
	
}
