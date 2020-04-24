#include <stdio.h>
#include "stack.h"

#define ROW (8)
#define COL (8)

int map[ROW][COL] = {0};
int number = 0;

int isLegalCoordinate(int x, int y){

	if (x < 0 || x >= COL || y < 0 || y >= ROW){
		return 0;
	}
	else if (map[x][y] == 2){
		return 0;
	}
	else {
		return 1;
	}
}

void explorPoint(STACK *stack, int x, int y){

	NODE *top = getTopStack(stack);

	if (isLegalCoordinate(x,y)){

		NODE *p = (NODE *)malloc(sizeof(NODE));
		
		map[x][y] = 2;
		p->coordinate.x = x;
		p->coordinate.y = y;
		p->step = top->step + 1;
		p->number = number++;
		p->direction = 0;
		p->lastnumber = top->number;
		pushStack(stack, p);
		free(p);
	}
}

void outputArray(){
	
	int i;
	int j;
	for (i = 0; i < ROW; i++){
		for(j = 0; j < COL; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	
}
int main(){

    STACK *stack = createStack();

    int START_Point_X;
    int START_Point_Y;

    printf("请输入起点行列坐标:");
    scanf("%d %d", &START_Point_X, &START_Point_Y);


	NODE *start = (NODE *)malloc(sizeof(NODE));
	start->coordinate.x = START_Point_X;
	start->coordinate.y = START_Point_Y;
	start->step = 0;
	number = 1;
	start->number = number++;
	start->lastnumber = 0;
	start->direction = 0;
	map[START_Point_X][START_Point_Y] = 2;
 
    pushStack(stack, start);
	NODE *top;
	int x;
	int y;
    while (1){
    	top = getTopStack(stack);
		x = top->coordinate.x;
		y = top->coordinate.y;
		
	   	top->direction++;
    	
		if (top->direction <= 8){
			
			switch(top->direction){

				case 1:
					explorPoint(stack, x-2, y+1);
					break;
				case 2:
					explorPoint(stack, x-1, y+2);
					break;
				case 3:
					explorPoint(stack, x+1, y+2);
					break;
				case 4:
					explorPoint(stack, x+2, y+1);
					break;
				case 5:
					explorPoint(stack, x+2, y-1);
					break;
				case 6:
					explorPoint(stack, x+1, y-2);
					break;
				case 7:
					explorPoint(stack, x-1, y-2);
					break;
		        case 8:
		        	explorPoint(stack, x-2, y-1);
		        	break;
		        default :
		        	break;
			}
			
			if (top->step == ROW*COL-1){
				outputArray();
				displayStack(stack);
				break;
			}
		}
		else {
			map[top->coordinate.x][top->coordinate.y] = 0;
			popStack(stack);
		}
	}


    destroyStack(&stack);

    return 0;
}

