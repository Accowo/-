#ifndef QUEUE_H
#define QUEUE_H
/**********************************
����ͷ�ļ�
**********************************/
#include <stdio.h>
#include <stdlib.h>
/**********************************
�ṹ�嶨��
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
��������
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
