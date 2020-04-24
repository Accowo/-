#include "queue.h"

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

void addQueue(QUEUE *queue, NODE *p){

    NODE *pnew= (NODE *)malloc(sizeof(NODE));
    if (pnew == NULL){
        exit(0);
    }
    pnew->coordinate.x = p->coordinate.x;
    pnew->coordinate.y = p->coordinate.y;
    pnew->step = p->step;
    pnew->number = p->number;
    pnew->lastnumber = p->lastnumber;

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

            printf("(%d,%d)", p->coordinate.x, p->coordinate.y);
            printf("step:%d ", p->step);
            printf("number:%d ", p->number);
            printf("lastnumber:%d \n", p->lastnumber);
            p = p->next;
        }
    }

}
NODE *findQueue(QUEUE *queue, int number){
	
	NODE *p = queue->head;
	
	if (!isEmptyQueue(queue)){
		while (p->number != number){
			p = p->next;
		}
		return p;
    }
	return NULL;
}

NODE *getHeadQueue(QUEUE *queue){

    if (!isEmptyQueue(queue)){
       return queue->head;
    }
    return NULL;
}

NODE *getRearQueue(QUEUE *queue){

    if (!isEmptyQueue(queue)){
       return queue->rear;
    }
    return NULL;
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

