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

	char str[] = "700+3*4/2-10";
	
    STACK *numStack = createStack();
    STACK *operStack = createStack();

	int i;
	int index1 = 0;
	char ch;
	char oper;
	int num1;
	int num2;
	int num3;
	int res;
	char strnum[10] = {0};
    for (i = 0; i < strlen(str) ;i++){
    	ch = str[i];
    	if (isNumber(ch)){
    		strnum[index1++] = ch;
            //探测下一位是不是数字
	        ch = str[i + 1];
			while(isNumber(ch)){
			   	strnum[index1++] = ch;
	        	i++;
	        	ch = str[i + 1];
            }
			num3 = strTOnum(strnum);
			pushStack(numStack, num3);
    		memset(strnum, 0, sizeof(strnum));
    		index1 = 0;
		}
    	else if (isOperator(ch)){
    		if (isEmptyStack(operStack)){
			//如果符号栈为空直接入栈
    			pushStack(operStack, ch);
			}
			else {
			//如果符号栈不为空
					oper = getTopStack(operStack);
					if (getPriority(ch) > getPriority(oper)){
					//优先级大于栈顶运算符直接入栈
						pushStack(operStack, ch);
					}
					else {
						oper = getTopStack(operStack);
						popStack(operStack);
						num1 = getTopStack(numStack);
						popStack(numStack);
						num2 = getTopStack(numStack);
						popStack(numStack);
						res = calculate(num1, num2, oper);
						//运算结果入数栈
						pushStack(numStack, res);
						//当前操作符ch入栈
						pushStack(operStack, ch);
	                }
			}
    		
            
		}

	}
    while (1){
    	if (isEmptyStack(operStack)){
    		break;
		}
		oper = getTopStack(operStack);
		popStack(operStack);
		num1 = getTopStack(numStack);
		popStack(numStack);
		num2 = getTopStack(numStack);
		popStack(numStack);
		res = calculate(num1, num2, oper);
		//运算结果入数栈
		pushStack(numStack, res);
    	
    }

	printf("%d", res);

    destroyStack(&numStack);
    destroyStack(&operStack);

    return 0;
}

