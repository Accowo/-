#include <stdio.h>
int unique(int a[],int len);
void output(int a[],int len);
int main(void){
	
	int a[]={2,2,2,3,4,4,5,6,6,6,6,7,7,8,9,9,10,10,10}; 
	int len=sizeof(a)/4; 
	int len2;
	printf("数组:\n");
	output(a,len); 
	len2=unique(a,len);
	
	printf("删除重复数字后的数组:\n");
	output(a,len2); 

	printf("删除后数据个数:%d",len2);
	 
	return 0;
} 
int unique(int a[],int len){
	
	int i,j;
	for(i=0;i<len;i++){
		if(i < len-1){
			if(a[i]==a[i+1]){
			for(j=i+1;j<len-1;j++){
				a[j]=a[j+1];
			}
			i--; 
			len--;
		}	
		}
	}
	return len;
}
void output(int a[],int len){
	
	int i;
	for(i=0;i<len;i++){
		printf("%d ",a[i]);
	}
	printf("\n"); 
}
