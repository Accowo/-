#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void rand_array(int a[][6],int row,int col);
int max_row(int a[][6],int row,int col);
void sort(int b[],int n);
void output_array2(int a[][6],int row,int col);
void output_array1(int b[],int len); 
int main(void){
	
	int a[7][6];
	int b[7];
	int row=7;
	int col=6; 
	int i;
	srand(time(NULL)); 
	rand_array(a,row,col); 
	printf("数组:\n");
	output_array2(a,row,col);
	
	for (i = 0;i < row;i++){
		b[i] = max_row(a,i,col);
	}
	printf("每一行的最大值:\n"); 
	output_array1(b,row);
	
	sort(b,row);
	printf("每一行的最大值从小到大排序:\n");
	output_array1(b,row);
	return 0;
} 
void rand_array(int a[][6],int row,int col){
	
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			a[i][j]=rand()%(row*col)+1;
		}
	}
}
int max_row(int a[][6],int row,int col){
	
	int max=a[row][0];
	int j;
	for(j=0;j<col;j++){
		if(a[row][j]>max){
			max=a[row][j];
		}
	}
	return max;
}
void sort(int b[],int n){
	
	int i,j;
	int temp;
	for(i=1;i<n;i++){	
		temp=b[i];				
		for(j=i;j>0;j--){		
			if(b[j-1]>temp){    
				b[j]=b[j-1];
			}
			else{			
				b[j]=temp;
				break;
			}
		}
		if(j==0){				
			b[j]=temp;
		}
	}
}
void output_array1(int b[],int len){
	
	int i;
	for (i = 0;i < len;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
}
void output_array2(int a[][6],int row,int col){
	
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%5d",a[i][j]);
			if(j==col-1){
				printf("\n");
			}
		}
	}
}
