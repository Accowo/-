#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char name[20];
	int date;
	struct node *next;
}NODE;

NODE *CreatList_headnode(){

	NODE *head = (NODE*)malloc(sizeof(NODE));
	if (head == NULL){
		exit(0);
	}
	head->next = NULL;

	return head;
}
void AddList_tailnode(NODE *head, const char *name, int date){   //Î²²¿²åÈë

	NODE *pos = head;
	NODE*pnew = (NODE*)malloc(sizeof(NODE));

	if (pnew == NULL){
		exit(0);
	}

    strcpy(pnew->name, name);
	pnew->date = date;

	while (pos->next != NULL){
		pos = pos->next;
	}

	pnew->next = NULL;
	pos->next = pnew;


}
void PrintList(NODE *head){

	NODE *pos = head;

	while(pos->next != NULL){
		pos = pos->next;
		printf("%s %d\n", pos->name, pos->date);
	}

}
void DeleteNode_Bydate(NODE *head, int date){

	NODE *index1 = head;
	NODE *index2 = head->next;

	while (index2 != NULL){
		if (index2->date == date){
			index1->next = index2->next;
			free(index2);
			index2 = index1->next;
		}
		else{
			index1 = index1->next;
			index2 = index2->next;
  		}
	}

}

void InsertList_Bydate(NODE *head, const char *name, int date){

	NODE *index2 = head->next;
	NODE *index1 = head;

	NODE *pnew = (NODE*)malloc(sizeof(NODE));
	if (pnew == NULL){
        exit(0);
 	}

 	strcpy(pnew->name, name);
	pnew->date = date;

	while (index2 != NULL && index2->date < date ){
			index1 = index1->next;
			index2 = index2->next;
	}
	pnew->next = index2;
	index1->next = pnew;

}
void Sort_List_Bydate(NODE *head, ){
	
	
	
	
	
	
}
int main(){

	NODE *head = CreatList_headnode();

	AddList_tailnode(head, "yasuo",1);
	AddList_tailnode(head, "akali",2);
	AddList_tailnode(head, "amumu",3);
	AddList_tailnode(head, "bulong",4);
	AddList_tailnode(head, "meidusha",5);


	PrintList(head);


	return 0;
}
