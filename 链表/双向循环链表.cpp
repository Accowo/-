#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char name[20];
	int date;
	struct node *next;
	struct node *prior;
}NODE;

NODE *CreatList(){

	NODE *head = (NODE*)malloc(sizeof(NODE));

	if (head == NULL){
		exit(0);
	}

	head->next = head;
	head->prior = head;
	
	return head;
}
void AddList_nodenixu(NODE *head, const char *name, int date){

	NODE*pnew = (NODE*)malloc(sizeof(NODE));                    

	if (pnew == NULL){
		exit(0);
	}
	strcpy(pnew->name, name);
	pnew->date = date;
	
	pnew->next = head->next;
	head->next->prior = pnew;
	pnew->prior = head;
	head->next = pnew;
}
void AddList_nodeshunxu(NODE *head, const char *name, int date){

	NODE*pnew = (NODE*)malloc(sizeof(NODE));

	if (pnew == NULL){
		exit(0);
	}
	strcpy(pnew->name, name);
	pnew->date = date;

	pnew->prior = head->prior;
	head->prior->next = pnew;
	pnew->next = head;
	head->prior = pnew;
}
void DisplayList(NODE *head){

	NODE *pos = head;

	while(pos->next != head){
		pos = pos->next;
		printf("%s %d\n", pos->name, pos->date);
	}

}
void DeleteNode_Bydate(NODE *head, int date){

	NODE *index1 = head;
	NODE *index2 = head->next;
	
	while (index2 != head){
		if (index2->date == date){
			index2->prior->next = index2->next;
			index2->next->prior = index2->prior;
			free(index2);
			index2 = index1->next;
		}
		else {
			index1 = index1->next;
     		index2 = index2->next;
		}
	}
}
void ClearList(NODE *head){

	NODE *pos = head;

	while (pos->next != head){
		pos = pos->next;
		free(pos);
	}

}
void DestoryList(NODE **head){


	ClearList(*head);

	free(*head);
	*head = NULL;
}


int main(){

	NODE *head = CreatList();
	AddList_nodeshunxu(head, "akali",2);
	AddList_nodeshunxu(head, "yasuo",1);

	AddList_nodeshunxu(head, "akali",2);
	AddList_nodeshunxu(head, "amumu",3);
	AddList_nodeshunxu(head, "bulong",4);
	AddList_nodeshunxu(head, "meidusha",5);
	DeleteNode_Bydate(head,2);

	DisplayList(head);

	DestoryList(&head);

	return 0;
}
