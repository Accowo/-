#include <stdio.h>

int main(void){

	FILE *fp = fopen("a.txt","w");
    fputs("12345\n",fp);
    fputs("67890\n",fp);
    fputs("\n",fp);

	fclose(fp);
	
	FILE *fp = fopen("a.txt","r");
    char *s[3];
    for (int i = 0; i < 3; i++){
    	fgets(s[i], 6, fp);
    }
	printf("%s", s[0]);


	fclose(fp);
	
	
	
	
	return 0;
}
