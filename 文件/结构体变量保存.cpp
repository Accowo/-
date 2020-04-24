#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct NODE{
	char *name;
	int date;
};
int main(void){
////	struct NODE node ={'A',2};
//	struct NODE node;
//	struct NODE *index = &node;
//	node.name =(char *)malloc(2);
//	strcmp(node.name,"B");
//	
//	FILE *fp = fopen("b.txt","w");
//	
//	fwrite(index,sizeof(node),1,fp);
////	fread(index,16,1,fp);
////	printf("%d", node.date);

	FILE *fp = fopen("b.txt","r");
	struct NODE node;
	node.name =(char *)malloc(100);
	fseek(fp,0,SEEK_SET);
	fread(&node,sizeof(node),1,fp);
	
	printf("%d",sizeof(node));
	fclose(fp);
//	free(node.name);
	return 0;
}
