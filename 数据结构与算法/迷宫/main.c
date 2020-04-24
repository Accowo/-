#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define ROW (10)
#define COL (10)

int map[ROW][COL] = {0};
int number = 0;

void initMap(){

	map[0][4] = 1;
	map[2][1] = 1;
	map[2][2] = 1;
	map[3][3] = 1;
	map[4][0] = 1;
	map[5][9] = 1;
}

int isLegalCoordinate(int x, int y){

	if (x < 0 || x >= COL || y < 0 || y >= ROW){
		return 0;
	}
	else if (map[x][y] == 1){
		return 0;
	}
	else {
		return 1;
	}
}

void explorPoint(QUEUE *explorationTeam, int x, int y){

	NODE *head = getHeadQueue(explorationTeam);

	if (isLegalCoordinate(x,y) && map[x][y] != 2){

		NODE *p = (NODE *)malloc(sizeof(NODE));

		map[x][y] = 2;
		p->coordinate.x = x;
		p->coordinate.y = y;
		p->step = head->step + 1;
		p->number = number++;
		p->lastnumber = head->number;
		addQueue(explorationTeam, p);
		free(p);
	}
}
void outputArray(){
	
	int i;
	int j;
	for (i = 0; i < ROW; i++){
		for ( j = 0; j < COL; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
    }
}

int main(void){

	initMap();
	outputArray();
	QUEUE *explorationTeam = createQueue();
	QUEUE *overTeam = createQueue();

    int START_Point_X;
    int START_Point_Y;
    int End_Point_X;
    int End_Point_Y;
    printf("请输入起点行列坐标:");
    scanf("%d %d", &START_Point_X, &START_Point_Y);
    printf("请输入终点点行列坐标:");
    scanf("%d %d", &End_Point_X, &End_Point_Y);
    
    
	NODE *start = (NODE *)malloc(sizeof(NODE));
	start->coordinate.x = START_Point_X;
	start->coordinate.y = START_Point_Y;
	start->step = 0;
	number = 1;
	start->number = number++;
	start->lastnumber = 0;
	map[START_Point_X][START_Point_X] = 2;

	addQueue(explorationTeam, start);

	int x;
	int y;

	NODE *p;
	
	while(1){
        p = getHeadQueue(explorationTeam);
		x = p->coordinate.x;
		y = p->coordinate.y;

		explorPoint(explorationTeam, x - 1, y);//上
		explorPoint(explorationTeam, x, y + 1);//右
		explorPoint(explorationTeam, x + 1, y);//下
		explorPoint(explorationTeam, x, y - 1);//左

		addQueue(overTeam, p);
		delQueue(explorationTeam);

		p = getRearQueue(overTeam);

		if (p->coordinate.x == End_Point_X  && p->coordinate.y == End_Point_Y){
			break;
		}
	}

	memset(map, 0, sizeof(map));
	initMap();
	p = getRearQueue(overTeam);
	
	while (1){
		
		x = p->coordinate.x;
		y = p->coordinate.y;
		map[x][y] = 2;
		if(x == start->coordinate.x && y == start->coordinate.y){
			break;
		}
		p = findQueue(overTeam, p->lastnumber);
 	}

	printf("路线图:\n");
	outputArray();
	displayQueue(overTeam);

	free(start);
	destryQueue(&explorationTeam);
	destryQueue(&overTeam);
	return 0;
}
