#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define ROW (5)
#define COL (5)

int map[ROW][COL] = {0};
int number = 0;


void initMap(){
	
	map[0][4] = 1;
	map[2][1] = 1;
	map[2][2] = 1;
	map[3][3] = 1;
	map[4][0] = 1;
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


int main(void){
	
	initMap();
	
	QUEUE *explorationTeam = createQueue();
	QUEUE *overTeam = createQueue();
	
	NODE *start = (NODE *)malloc(sizeof(NODE));
	start->coordinate.x = 0;
	start->coordinate.y = 0;
	start->step = 0;
	number = 1;
	start->lastnumber = 0;
	map[0][0] =2;
	
	addQueue(explorationTeam, start);
	free(start);
	
	int x;
	int y;
	NODE *p;
	while(1){
        p = getHeadQueue(explorationTeam);
		x = p->coordinate.x;
		y = p->coordinate.y;
		
		explorPoint(explorationTeam, x - 1, y);//ио
		explorPoint(explorationTeam, x, y + 1);//ср
		explorPoint(explorationTeam, x + 1, y);//об
		explorPoint(explorationTeam, x, y - 1);//вС
		
		addQueue(overTeam, p);
		delQueue(explorationTeam);
		
		p = getRearQueue(overTeam);
		
		if (p->coordinate.x == 4 && p->coordinate.y == 2){
			
			displayQueue(overTeam);
			break;
		}
		
	}
	
	destryQueue(&explorationTeam);
	destryQueue(&overTeam);
	return 0;
}
