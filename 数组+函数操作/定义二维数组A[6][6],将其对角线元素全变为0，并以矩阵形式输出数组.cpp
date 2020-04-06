#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void rand_array(int a[][6],int row,int col);
void output_array(int a[][6],int row,int col);
int main(void){
	
	int a[6][6];
	int row=6,col=6;
	srand(time(NULL));
	int i,j;
	
	rand_array(a,row,col);
	printf("原数组：\n");
	output_array(a,row,col);
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(i==j||i+j==row-1){   //对角线清零 
				a[i][j]=0;
			}
		}
	}
	printf("对角线清零：\n");
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



