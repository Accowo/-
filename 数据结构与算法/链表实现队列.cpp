#include <stdio.h>
#include <stdlib.h>
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

    int i;

    for (i = 0; i < 10; i++){
        addQueue(queue, i);
    }
    printf("队列:");
    displayQueue(queue);
    printf("队头:%d\n", getHeadQueue(queue));

    printf("出队\n");
    delQueue(queue);
    displayQueue(queue);
    printf("队头:%d\n", getHeadQueue(queue));

    printf("清空队列\n");
    clrQueue(queue);

    if (isEmptyQueue(queue)){
        printf("clear\n");
    }

    destryQueue(&queue);
    return 0;
}

