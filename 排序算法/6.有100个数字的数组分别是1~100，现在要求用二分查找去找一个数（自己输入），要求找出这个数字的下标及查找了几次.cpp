#include <stdio.h>
void array_1_to_n(int a[],int n);
int main(void){
	
	int a[100];
	int len=100;
	int num;
	int i=0;
	int low,high,mid;
	array_1_to_n(a,100);
	
	printf("������1-100��һ����:");
	scanf("%d",&num); 

	low=0;
	high=len-1; 
	while(1){
		if(low>high){
			printf("�����ҵ�,����涨��Χ�ڵ�����!"); 
			break;
		}	
		mid=(low+high)/2;	
		i++; 
		if(a[mid]==num){
			printf("�������±�:%d\n",mid);
			printf("���ҵĴ���:%d\n",i);
			break; 
		}
		else if(a[mid]>num){
			high=mid-1;
		}
		else if(a[mid]<num){
			low=mid+1;
		}
	}
	return 0;
}
void array_1_to_n(int a[],int n){

	int i;
	for(i=0;i<n;i++){
		a[i]=i+1;
	} 
} 
