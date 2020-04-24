#ifndef QUEUE_H
#define QUEUE_H
/**********************************
����ͷ�ļ�
**********************************/
#include <stdio.h>
#include <stdlib.h>
/**********************************
�ṹ�嶨��
**********************************/
typedef struct coordinate{

	int x;
	int y;

}COORDINATE;

typedef struct node{

	COORDINATE coordinate;
	int step;
	int number;
	int lastnumber;
    struct node *next;

}NODE;
typedef struct queue{

    NODE *head;
    NODE *rear;

}QUEUE;

/**********************************
��������
**********************************/
extern QUEUE* createQueue ();
extern int isEmptyQueue(QUEUE *queue);
extern void addQueue(QUEUE *queue, NODE *p);
extern void delQueue(QUEUE *queue);
extern void displayQueue(QUEUE *queue);
extern NODE *getHeadQueue(QUEUE *queue);
extern NODE *getRearQueue(QUEUE *queue);
extern void clrQueue(QUEUE *queue);
extern void destryQueue(QUEUE **queue);
extern NODE *findQueue(QUEUE *queue, int number);

#endif
