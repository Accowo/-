#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void randshuzu(int a[][5],int n);
int row_max(int a[5][5],int i);
int column_min(int a[5][5],int j);
void outputshuzu(int a[5][5]);
int main(void){
	
	int a[5][5];
	int b[5][5];
	int i,j;
	
	randshuzu(a,5);
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			b[i][j]=(row_max(a,i)+column_min(a,j))/2;	
		}
	}
	printf("a:\n");
	outputshuzu(a);
	
	printf("\n");
	
	printf("b:\n");
	outputshuzu(b);
	
	return 0;
} 
void randshuzu(int a[][5],int n){
	
	srand(time(NULL));
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<n;j++){
			a[i][j]=rand()%100;
		}
	}
}
int row_max(int a[5][5],int i){
	
	int max=a[i][0];
 	int j;
		for(j=0;j<5;j++){	
			if(a[i][j]>max){
				max=a[i][j];
			}
		}	
	return max;
}
	
int column_min(int a[5][5],int j){
	
	int min=a[0][j];
	int i;
	for(i=0;i<5;i++){	
		if(a[i][j]<min){
			min=a[i][j];
		}
	}
	return min;
}
void outputshuzu(int a[5][5]){
	
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%5d",a[i][j]);
			if(j==4){
				printf("\n");
			}
		}
	
	}
}



