#include <stdio.h>
struct man{
	int number; 
	char name[20];
	int piao;
};
int main(void){

	struct man peo[3]={{1,"力元君",0},{2,"徐大虾",0},{3,"啊吗粽",0}};
	int i;
	int vote; 
	int max; 
	
	for (i = 0; i < 10; i++){
		printf("请%d号评委投票:", i+1); 
		scanf("%d", &vote);
		switch (vote){
			case 1:peo[0].piao++;break;
			case 2:peo[1].piao++;break;
			case 3:peo[2].piao++;break;
		} 
	}
	
	for (i = 0; i < 3 ; i++){
		printf("%s的总票数是%d票\n", peo[i].name, peo[i].piao);
	} 
	
	max = peo[0].piao;
	for (i = 1; i < 3; i++){
		if (max < peo[i].piao){
			max = peo[i].piao; 
		} 
	} 
	for (i = 0; i < 3; i++){
		if (max==peo[i].piao){
			printf("得票最高的是:%s,一共%d票", peo[i].name,peo[i].piao); 
			break; 
		} 
	} 
	 
	return 0;
} 

