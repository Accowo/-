#include <stdio.h>
#include <stdlib.h>
typedef struct node{

    int data;
    struct node *next;

}NODE;

typedef struct stack{

    NODE *top;

}STACK;

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
void pushStack(STACK *stack, int data){

    NODE *pnew= (NODE *)malloc(sizeof(NODE));
    if (pnew == NULL){
        exit(0);
    }
    pnew->data = data;

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

            printf("%d ", p->data);
            p = p->next;
        }
    }

}
int getTopStack(STACK *stack){

    if (!isEmptyStack(stack)){
        return stack->top->data;
    }
    return -9999;
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

int main(){

    STACK *stack = createStack();

    int i;

    for (i = 0; i < 10; i++){
        pushStack(stack, i);
    }
    printf("Õ»:");
    displayStack(stack);
    printf("Õ»¶¥:%d\n", getTopStack(stack));

    printf("pop:\n");
    popStack(stack);
    
    displayStack(stack);
    printf("Õ»¶¥:%d\n", getTopStack(stack));

    printf("Çå¿ÕÕ»\n");
    clrStack(stack);

    if (isEmptyStack(stack)){
        printf("clear\n");
    }

    destroyStack(&stack);

    return 0;
}

