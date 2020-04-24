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
typedef struct node{

    int x;
    int y;
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
extern void pushStack(STACK *stack, int x, int y);
extern void popStack(STACK *stack);
extern void displayStack(STACK *stack);
extern NODE *getTopStack(STACK *stack);
extern void clrStack(STACK *stack);
extern void destroyStack(STACK **stack);



#endif
