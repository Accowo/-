#include <stdio.h>

int main(void){
	
	int a = 10;
	int b = 4;
	FILE* fp = fopen("test_fprinf","w");
	
	
	fprintf(fp, "%d", a);
	fwrite(&a,sizeof(int),1,fp);
	
	fclose(fp);

//	int a ;
//	FILE* fp = fopen("test_fprinf","r");
//
//
//	fscanf(fp, "%d", &a);
//
//	printf("%d", a);
//	fclose(fp);






	return 0;
}
