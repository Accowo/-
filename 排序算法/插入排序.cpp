#include <stdio.h>

int main(void){
	
	int i;						 
	int j;	
	int min;				
	int n=10;
	int a[n]={6,5,4,2,3,35,3,13,4,6};  
	int temp;
	
	for(i=1;i<n;i++){	
		temp=a[i];				//待排序数中第一个数 
		for(j=i;j>0;j--){		
			if(a[j-1]>temp){    //前数大于后数，后数等于前数，实现后移 
				a[j]=a[j-1];
			}
			else{				//前数小于等于后数 
				a[j]=temp;
				break;
			}
		}
		if(j==0){				//到已排序的第一个数了，前面没有数字比较了 
			a[j]=temp;
		}

	}
	
	for(i=0;i<n;i++){			//输出 
		printf("%d ",a[i]);
	}
	
	return 0;
} 
