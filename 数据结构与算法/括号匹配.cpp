#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	printf("\n");
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


	char *str = "((";
	int top;
	int i = 0;
	for (i = 0; i < strlen(str) ;i++){
		
		if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
			pushStack(stack, str[i]);
			displayStack(stack);
		}
            
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}'){
			
			top = getTopStack(stack);
			if( top == '(' && str[i] == ')'){
				popStack(stack);
				displayStack(stack);
				continue;
			}
			else if (top == '[' && str[i] == ']'){
				popStack(stack);
				displayStack(stack);
				continue;
			}
			else if (top == '{' && str[i] == '}'){
				popStack(stack);
				displayStack(stack);
				continue;
			}
			else {
				printf("²»Æ¥Åä");
				destroyStack(&stack);
				return 0;
			}
		}

		else {
			continue;
		}
		
 	}
	if (isEmptyStack(stack)){
		
		printf("Æ¥Åä\n");
	}
	else {
		printf("²»Æ¥Åä\n");
	}

    destroyStack(&stack);

    return 0;
}

