#include <stdio.h>

int main(void){
	
	int i;						 
	int j;	
	int min;				
	int n=10;
	int a[n]={6,5,4,2,3,35,3,13,4,6};  
	int temp;
	
	for(i=1;i<n;i++){	
		temp=a[i];				//���������е�һ���� 
		for(j=i;j>0;j--){		
			if(a[j-1]>temp){    //ǰ�����ں�������������ǰ����ʵ�ֺ��� 
				a[j]=a[j-1];
			}
			else{				//ǰ��С�ڵ��ں��� 
				a[j]=temp;
				break;
			}
		}
		if(j==0){				//��������ĵ�һ�����ˣ�ǰ��û�����ֱȽ��� 
			a[j]=temp;
		}

	}
	
	for(i=0;i<n;i++){			//��� 
		printf("%d ",a[i]);
	}
	
	return 0;
} 
