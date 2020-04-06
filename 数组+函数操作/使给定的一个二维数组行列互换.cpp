#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
void rand_array(int a[][6],int row,int col);
void output_array(int a[][6],int row,int col);
int main(void){
	
	int N=6;
	int a[6][6];
	int row=N,col=N;
	srand(time(NULL));
	int i,j;
	int temp;
	rand_array(a,row,col);
	printf("原数组：\n");
	output_array(a,row,col);
	
	for(i=0;i<row;i++){
		for(j=0;j<i;j++){
			temp=a[i][j];
			a[i][j]=a[j][i];  //行列互换 
			a[j][i]=temp;
		}
	}
	
	printf("行列互换：\n");
	output_array(a,row,col);
	
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

void output_array(int a[][6],int row,int col){
	
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%5d",a[i][j]);
			if(j==row-1){
				printf("\n");
			}
		}
	}
}
 
