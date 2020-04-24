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
void pushStack(STACK *stack, NODE *p){

    NODE *pnew= (NODE *)malloc(sizeof(NODE));
    if (pnew == NULL){
        exit(0);
    }
    pnew->coordinate.x = p->coordinate.x;
    pnew->coordinate.y = p->coordinate.y;
    pnew->step = p->step;
    pnew->number = p->number;
    pnew->lastnumber = p->lastnumber;
    pnew->direction = p->direction;

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

            printf("(%d,%d)", p->coordinate.x, p->coordinate.y);
            printf("step:%d ", p->step);
            printf("number:%d ", p->number);
            printf("lastnumber:%d ", p->lastnumber);
            printf("direction:%d \n", p->direction);

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
