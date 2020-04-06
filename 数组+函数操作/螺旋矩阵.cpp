#include <stdio.h>
void output(int a[][7],int row,int col);
int main(void){
	
	int a[11][7]; 
	int row=11,col=7;
	int layer;
	int c=1;
	int i=0,j=0;
	
	for(layer=0;layer<=col/2;layer++){
		while(j<col-layer){
			a[i][j++]=c++;
		}
		j--;
		i++;
		while(i<row-layer){
			a[i++][j]=c++;
		}
		i--;
		j--;
		while(j>=layer){
			a[i][j--]=c++;
		}
		j++;
		i--;
		if(layer<col/2){
			while(i>layer){
				a[i--][j]=c++;
			}
			i++;
			j++;	
		}
	} 
	printf("ÂİĞı¾ØÕó:\n");
	output(a,row,col);
	return 0;
} 
void output(int a[][7],int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%3d ",a[i][j]);
		}
		printf("\n");
	}
}
