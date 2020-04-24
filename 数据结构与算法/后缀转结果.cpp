#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
//返回优先级,数字越大优先级越高
int getPriority(char a){

	switch(a){
		case '*':return 2;
		case '/':return 2;
		case '+':return 1;
		case '-':return 1;
		case '(':return 0;
		default :return -1;
	}

}
//判断是不是运算符
int isOperator(char a){

	if (a == '+' ||  a == '-' || a == '*' || a == '/'){
		return 1;
    }
	return 0;

}
//计算
int calculate(int num1, int num2 ,char oper){

	int res = 0;
	switch (oper){
		case '+':
			res = num1 + num2;
			break;
		case '-':
			res = num2 - num1;
			break;
		case '*':
			res = num1 * num2;
			break;
		case '/':
			res = num2 / num1;
			break;
		default :
			break;
	}

	return res;
}

//int compare(char a, char b){
//
//	int i = getPriority(a);
//	int j = getPriority(b);
//	if(i > j ){
//		return 1;
//	}
//	else if (i == j){
//		return 0;
//	}
//	else {
//		return -1;
//	}
//}
//判断是不是数字
int isNumber(char a){

	if (a >= '0' && a <= '9'){
		return 1;
	}
	return 0;
}
int strTOnum(char *str){

	int num = 0;
	int j;
	int i;
	for (i = strlen(str) - 1; i >= 0; i--){
		j = strlen(str) - i - 1;
		num += (str[i] - '0') * pow(10, j);
	}

	return num;
}

int main(){

	char str[] = "34+5*6-";

    STACK *resStack = createStack();

    char ch;
    int num1;
    int num2;
    int res;
    char oper;
    int i;
    for (i = 0; i < strlen(str); i++){
    	ch = str[i];
    	if (isNumber(ch)){
    		pushStack(resStack, ch - '0');
        }
        else {
			oper = ch;
			num1 = getTopStack(resStack);
			popStack(resStack);
			num2 = getTopStack(resStack);
			popStack(resStack);
			res = calculate(num1, num2, oper);
        	
        	pushStack(resStack, res);
		}
	}

	printf("%d", res);

    destroyStack(&resStack);

    return 0;
}

