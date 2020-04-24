#include "stack.h"

STACK *createStack(){

    STACK *stack = (STACK *)malloc(sizeof(STACK));
    if (stack == NULL){
        exit(0);
    }

    stack->top = NULL;

    return stack;

}
int isEmptyStack(STACK *stack){

    if (stack->top == NULL){
        return 1;
    }
    return 0;

}
void pushStack(STACK *stack, int x, int y){

    NODE *pnew= (NODE *)malloc(sizeof(NODE));
    if (pnew == NULL){
        exit(0);
    }
    pnew->x = x;
	pnew->y = y;
	
    pnew->next = stack->top;
    stack->top = pnew;

}
void popStack(STACK *stack){

    NODE *p;
    if(!isEmptyStack(stack)){
        p = stack->top;
        stack->top = p->next;
        free(p);
    }
}
void displayStack(STACK *stack){

    if(!isEmptyStack(stack)){

        NODE *p = stack->top;
        while(p != NULL){

            printf("(%d,%d)\n", p->x, p->y);
            p = p->next;
        }
    }

}
NODE *getTopStack(STACK *stack){

    if (!isEmptyStack(stack)){
        return stack->top;
    }
    return NULL;
}
void clrStack(STACK *stack){

    while (!isEmptyStack(stack)){
        popStack(stack);
    }
}
void destroyStack(STACK **stack){

    clrStack(*stack);
    free(*stack);
    *stack = NULL;
}


