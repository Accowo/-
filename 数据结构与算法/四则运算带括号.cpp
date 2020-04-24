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
//�������ȼ�,����Խ�����ȼ�Խ��
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
//�ж��ǲ��������
int isOperator(char a){

	if (a == '+' ||  a == '-' || a == '*' || a == '/'){
		return 1;
    }
	return 0;

}
//����
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

int houZui_TO_Result(char *str){

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
        	//����������͵�����Ӧ��������,������ٰѽ����ջ
			oper = ch;
			num1 = getTopStack(resStack);
			popStack(resStack);
			num2 = getTopStack(resStack);
			popStack(resStack);
			//����
			res = calculate(num1, num2, oper);
            //�ѽ����ջ
        	pushStack(resStack, res);
		}
	}

    destroyStack(&resStack);

    return res;
}
int main(){

	char str[] = "(2*(9+9/3-5)+4)";
	char str2[40] = {0};
	
    STACK *operStack = createStack();

	int i;
	int index = 0;
	char oper;
	char ch;
	int res;
	
    for (i = 0; i < strlen(str) ;i++){
    	ch = str[i];
    	if (isNumber(ch)){
    		//������,ֱ�����.
			str2[index++] = ch;
		}
		else if (ch == '('){
			//������,ֱ��ѹ���ջ
			pushStack(operStack, ch);
		}
		else if (ch == ')'){
			//������,(��ζ�������ѽ���)���ϵ���ջ������������ֱ������������(�����������)
			while (getTopStack(operStack) != '('){
				oper = getTopStack(operStack);
				popStack(operStack);
				str2[index++] = oper;
			}
			popStack(operStack);
		}
    	else if (isOperator(ch)){
			while(1){
	    		if (isEmptyStack(operStack)){
				//�������ջΪ��ֱ����ջ
	    			pushStack(operStack, ch);
	    			break;
				}
				else {
				//�������ջ��Ϊ��
					oper = getTopStack(operStack);
					//�����,���������ch��ջ�������oper���бȽ�,
					if (getPriority(ch) > getPriority(oper)){
					//���ȼ�����ջ�������ֱ����ջ
						pushStack(operStack, ch);
						break;
					}
					else {
						str2[index++] = oper;
						popStack(operStack);
						
	                }
				}
			}
		}
	}
	//���������,��˳�򵯳������ջ�����������
    while (1){
    	if (isEmptyStack(operStack)){
    		break;
		}
		oper = getTopStack(operStack);
		str2[index++] = oper;
		popStack(operStack);
    }
	
	res = houZui_TO_Result(str2);
		
	printf("%d", res);
		
    destroyStack(&operStack);

    return 0;
}

