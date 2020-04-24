#include <stdio.h>
struct NODE{
	char name;
	int date;
};
int main(void){
	struct NODE node;
	FILE *fp = fopen("b.txt","r");

	fread(&node,sizeof(NODE),1,fp);
    printf("%c %d \n", node.name, node.date);
    
	fclose(fp);
	return 0;
}
