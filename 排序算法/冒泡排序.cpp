#include <stdio.h>

int main(){
	
	int i;						// i：第几趟 
	int j;						//j:  第几次 
	int n=11;
	int a[n]={1,2,3,5,3,35,3,13,4,6,11}; 
	int temp;
	
	for(i=0;i<n-1;i++){			//n个数，进行n-1趟排序 
		for(j=0;j<n-i-1;j++){	// 第i趟，进行n-i次两两比较 ,如果j的初始值是0的话,边界是n-i-1, 
			if(a[j+1]<a[j]){  	//后一个比前一个小，交换 
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
} 
