#include <stdio.h>
void array(int a[],int N);
void output(int b[],int N);
void Fall_out(int a[],int b[],int N,int K,int M);
int isall_out(int a[],int N);
int main(void){
	
	int N;
	int K;
	int M;
	printf("		约瑟夫环\n请输入人数N:");
	scanf("%d",&N); 
	printf("请输入开始报数人的编号K:");
	scanf("%d",&K); 
	printf("请输入要数到的数M:"); 
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
			x++;  	//报数 
		}
		if(x==M){   //报到  M 
			x=0;   //报数清零
			 
			b[j++]=a[i];
			a[i]=0;
		} 
		i++;    //轮流 

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


