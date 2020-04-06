#include <stdio.h>
void input_array(int a[][4],int row,int col);
void output_Main_diagonal(int a[][4],int row,int col);
void output_counter_diagonal(int a[][4],int row,int col);
int main(void){
	
	int a[4][4]; 
	int i=4,j=4;
	
	printf("请输入16个数字：\n");
	input_array(a,i,j);
	printf("主对角线上的元素：");
	output_Main_diagonal(a,i,j);
	printf("副对角线上的元素：");
	output_counter_diagonal(a,i,j);
	
	return 0;
} 
void input_array(int a[4][4],int row,int col){
	
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			scanf("%d",&a[i][j]); 
		}
	}
}
void output_Main_diagonal(int a[4][4],int row,int col){

	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(i==j){
				printf("%d ",a[i][j]); 	
			}
		}
	}
	printf("\n");
} 
void output_counter_diagonal(int a[4][4],int row,int col){

	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(i+j==row-1){
				printf("%d ",a[i][j]); 	
			}
		}
	}
	printf("\n");
} 
