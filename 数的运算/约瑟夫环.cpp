#include <stdio.h>
void array(int a[],int N);
void output(int b[],int N);
void Fall_out(int a[],int b[],int N,int K,int M);
int isall_out(int a[],int N);
int main(void){
	
	int N;
	int K;
	int M;
	printf("		Լɪ��\n����������N:");
	scanf("%d",&N); 
	printf("�����뿪ʼ�����˵ı��K:");
	scanf("%d",&K); 
	printf("������Ҫ��������M:"); 
	scanf("%d",&M); 
	int a[N];
	int b[N];
	array(a,N);
	Fall_out(a,b,N,K,M);

	output(b,N);
	
	return 0;
} 
void array(int a[],int N){
	
	int i;
	int k=0;
	for(i=1;i<=N;i++){
		a[k++]=i;
	}
} 
void output(int b[],int N){
	
	int i;
	for(i=0;i<N;i++){
		printf("%d ",b[i]);
	}
}
void Fall_out(int a[],int b[],int N,int K,int M){
	
	int i=K-1; 
	int x=0;
	int j=0; 
	do{		
		if(a[i]!=0){
			x++;  	//���� 
		}
		if(x==M){   //����  M 
			x=0;   //��������
			 
			b[j++]=a[i];
			a[i]=0;
		} 
		i++;    //���� 

		if(i==N){
			i=0;
		}
	}while(isall_out(a,N) != 1);
}
int isall_out(int a[],int N){
	
	int i;
	for(i=0;i<N;i++){
		if(a[i]!=0){
			return 0;
		}
	}
	return 1;
}


