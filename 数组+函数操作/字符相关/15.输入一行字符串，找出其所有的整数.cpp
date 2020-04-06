#include <stdio.h>
int sort(char a[],int n);

int main(void){
	
	int buf[40]="123sgsg1233";
	
	
	return 0;
} 
int sort(char a[],int n){

	for(i=0;i<n-1;i++){			
		for(j=0;j<n-i-1;j++){	
			if(a[j+1]<a[j]){  	
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}
