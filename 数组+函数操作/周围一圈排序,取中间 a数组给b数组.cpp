#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void array(int a[][5],int row,int col);
int getdate(int a[][5],int x,int y,int c[]);
void sort(int c[],int n); 
int getmid(int c[],int len);
int legal(int i,int j);
void output_array(int a[][5],int row,int col);
int main(void){
	
	int a[5][5];
	int b[5][5];
	int c[8];
	int row=5;
	int col=5;
	int i,j;
	int len;
	
	array(a,row,col);
	printf("a:\n");
	output_array(a,row,col);

	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			len=getdate(a,i,j,c);
			sort(c,len);
			b[i][j]=getmid(c,len);
		}
	}
	printf("\n");
	
	printf("b:\n");
	output_array(b,row,col);
	
	return 0;
} 
void array(int a[][5],int row,int col){
	
	srand(time(NULL));
	int i,j;
	int c=1; 
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			a[i][j]=c++;
		}
	}
}
int getdate(int a[][5],int x,int y,int c[]){
	
	int i,j;
	int k=0;
	for(i=x-1;i<=x+1;i++){
		for(j=y-1;j<=y+1;j++){
			if(legal(i,j) == 1){
				if( i == x && j == y); 
				else{
					c[k++]=a[i][j];
				} 
			}
		}
	}
	return k; 
}
int legal(int i,int j){
	
	if(i < 0 || i >= 5){
		return 0;
	}
	else if(j < 0 ||j >= 5){
		return 0;
	} 
	else{
		return 1;
	}
}
void sort(int c[],int n){
	
	int i,j;
	int temp;
	for(i=0;i<n-1;i++){			
		for(j=0;j<n-i-1;j++){	 
			if(c[j+1]<c[j]){  	
				temp=c[j+1];
				c[j+1]=c[j];
				c[j]=temp;
			}
		}
	}
}
int getmid(int c[],int len){
	
	return c[len/2];
}
void output_array(int a[5][5],int row,int col){
	
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



