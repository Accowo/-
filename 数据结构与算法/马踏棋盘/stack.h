#ifndef QUEUE_H
#define QUEUE_H
/**********************************
包含头文件
**********************************/
#include <stdio.h>
#include <stdlib.h>
/**********************************
结构体定义
**********************************/
typedef struct coordinate{

	int x;
	int y;

}COORDINATE;

typedef struct node{

    COORDINATE coordinate;
	int step;
	int number;
	int lastnumber;
	int direction;
    struct node *next;

}NODE;

typedef struct stack{

    NODE *top;

}STACK;

/**********************************
函数声明
**********************************/
extern STACK *createStack();
extern int isEmptyStack(STACK *stack);
extern void pushStack(STACK *stack, NODE *p);
extern void popStack(STACK *stack);
extern void displayStack(STACK *stack);
extern NODE *getTopStack(STACK *stack);
extern void clrStack(STACK *stack);
extern void destroyStack(STACK **stack);


#endif
