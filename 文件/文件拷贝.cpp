#include <stdio.h>

int main(int argc, char **argv){
	
	if (argc != 3){
		printf("input error\n");
		return 0;
	}
	FILE *fp1 = fopen(argv[1],"r");
	FILE *fp2 = fopen(argv[1],"w");
	if (fp1 == NULL || fp2 == NULL){
		fclose(fp1);
		fclose(fp2);
	}
	char ch;
	
	while (ch=fgetc(fp1) != EOF){
		fputc(ch,fp2);
	}
	
	fclose(fp1);
	fclose(fp2);
	
	
	return 0;
}
