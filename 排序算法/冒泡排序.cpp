#include <stdio.h>

int main(){
	
	int i;						// i���ڼ��� 
	int j;						//j:  �ڼ��� 
	int n=11;
	int a[n]={1,2,3,5,3,35,3,13,4,6,11}; 
	int temp;
	
	for(i=0;i<n-1;i++){			//n����������n-1������ 
		for(j=0;j<n-i-1;j++){	// ��i�ˣ�����n-i�������Ƚ� ,���j�ĳ�ʼֵ��0�Ļ�,�߽���n-i-1, 
			if(a[j+1]<a[j]){  	//��һ����ǰһ��С������ 
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
