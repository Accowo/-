#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void randarray(int a[],int len); 
int max(int a[],int len);
int min(int a[],int len);
int sum(int a[],int len);
float average(int sum,int len);

int main(void){
	
	int a[10];	
	int len=10;
	srand(time(NULL));
	randarray(a,len); 
	int i;
	
	printf("������飺");
	for(i=0;i<len;i++){
		printf("%d ",a[i]);
	}
	printf("\n"); 
	printf("���ֵ��%d\n",max(a,len));
	printf("��Сֵ��%d\n",min(a,len));
	printf("�ܺͣ�%d\n",sum(a,len));
	printf("ƽ��ֵ��%f\n",average(sum(a,len),len));
	return 0;
} 
void randarray(int a[],int len){
	
	int i;
	for(i=0;i<len;i++){
		a[i]=rand()%len;
	}
}
int max(int a[],int len){
	
	int i;
	int max=a[0];
	for(i=0;i<len;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	return max;
}

int min(int a[],int len){
	
	int i;
	int min=a[0];
	for(i=0;i<len;i++){
		if(a[i]<min){
			min=a[i];
		}
	}
	return min;
}

int sum(int a[],int len){
	
	int i;
	int sum=0;
	for(i=0;i<len;i++){
		sum+=a[i];
	}
	return sum;
}

float average(int sum,int len){
	
	return sum/(len*1.0);
}
