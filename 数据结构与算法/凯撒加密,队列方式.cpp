#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{

    int data;
    struct node *next;

}NODE;
typedef struct queue{

    NODE *head;
    NODE *rear;

}QUEUE;

QUEUE* createQueue (){

    QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
    if (queue == NULL){
        exit(0);
    }

    queue->head = NULL;
    queue->rear = NULL;


    return queue;
}
int isEmptyQueue(QUEUE *queue){

    if (queue->head == NULL && queue->rear == NULL){
        return 1;
    }
    return 0;
}

void addQueue(QUEUE *queue, int data){

    NODE *pnew= (NODE *)malloc(sizeof(NODE));
    if (pnew == NULL){
        exit(0);
    }
    pnew->data = data;
    pnew->next = NULL;

    if(isEmptyQueue(queue)){

        queue->head = pnew;
        queue->rear = pnew;
    }
    else {
        queue->rear->next = pnew;
        queue->rear = pnew;
    }
}

void delQueue(QUEUE *queue){
    NODE *p;
    if(!isEmptyQueue(queue)){
        if (queue->head == queue->rear){
            queue->rear = NULL;
        }
        p = queue->head;
        queue->head = p->next;
        free(p);
    }

}
void displayQueue(QUEUE *queue){

    if(!isEmptyQueue(queue)){

        NODE *p = queue->head;
        while(p != NULL){

            printf("%d ", p->data);
            p = p->next;
        }
    }

}
int getHeadQueue(QUEUE *queue){

    if (!isEmptyQueue(queue)){
        return queue->head->data;
    }
    return -9990;
}
void clrQueue(QUEUE *queue){

    while (!isEmptyQueue(queue)){
        delQueue(queue);
    }

}
void destryQueue(QUEUE **queue){

    clrQueue(*queue);
    free(*queue);
    *queue = NULL;
}

int main(){

    QUEUE *queue = createQueue();
    char *str = "helloworld";
    char str2[20] = {'\0'};
    char str3[20] = {'\0'};
    int key;
    int i;
    addQueue(queue, 1);
    addQueue(queue, 7);
    addQueue(queue, 3);
    addQueue(queue, 8);
    for (i = 0; i < strlen(str); i++){ //¼ÓÃÜ
		key = getHeadQueue(queue);
    	displayQueue(queue);
    	
        str2[i] = 'a' + (str[i] - 'a'+ key) % 26;
        printf("%d ", str2[i]);
        delQueue(queue);
		addQueue(queue, key);
		
        printf("\n");
    }
  
    printf("%s\n", str2);
    
    clrQueue(queue);
    addQueue(queue, 1);
    addQueue(queue, 7);
    addQueue(queue, 3);
    addQueue(queue, 8);
    for (i = 0; i < strlen(str2); i++){ //½âÃÜ
		key = getHeadQueue(queue);
    	displayQueue(queue);

        str3[i] = str2[i] - key;
        if (str3[i] < 'a'){
			str3[i] += 26;
        }
        printf("%d ", str2[i]);
        delQueue(queue);
		addQueue(queue, key);

        printf("\n");
    }
    
    printf("%s", str3);
    
    
	destryQueue(&queue);
    return 0;
}

