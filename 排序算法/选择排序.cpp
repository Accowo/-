#include <stdio.h>

int main(){
	
	int i;						 
	int j;	
	int min;				
	int n=10;
	int a[n]={1,2,3,5,3,35,3,13,4,6};  
	int temp;
	
	for(i=0;i<n-1;i++){		
		min=i;						
		for(j=i;j<n;j++){		//找到待排序数中的最小值的下标 
			if(a[j]<a[min]){
				min=j;
			}
		}
		temp=a[i];				//最小值和待排序数中第一个值交换 
		a[i]=a[min];
		a[min]=temp; 
	}
	
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
} 
