#include <stdio.h>
#include <string.h>
void sort_string(char str[][20],int row); 
int main(void){
	
	char str[10][20]={'0'};
	int i;
	printf("ÇëÊäÈë10¸ö×Ö·û´®£º\n");
	for(i=0;i<10;i++){
		scanf("%s",str[i]);
	}
	
	sort_string(str,10);
	printf("\n");
	printf("ÅÅĞòºó£º\n");
	for(i=0;i<10;i++){
		printf("%s\n",str[i]);
	}
	
	return 0;
}
void sort_string(char str[][20],int row){
	
	int i,j;
	char temp[20];
	for(i=0;i<row-1;i++){
		for(j=0;j<row-i;j++){
			if(strcmp(str[j],str[j+1])==1){
				strcpy(temp,str[j+1]);
				strcpy(str[j+1],str[j]);
				strcpy(str[j],temp); 
			}		
		}
	}
}
