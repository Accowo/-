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
void List_reverse(NODE *head){
	
	NODE *p1,*p2,*p3;
	p1 = head;
	p2 = p1->next;
	p3 = p2->next;
	
	p2->next = NULL;
	p2 = p3;
	p1 = p1->next;
	p3 = p3->next;
	while (p3 != NULL ){
		p2->next = p1;

		p2 = p3;
		p3 = p3->next;
    }
	head->next = p2;
	

}
int main(){

	NODE *head = CreatList_headnode();

	AddList_tailnode(head, "ÑÇË÷",1);
	AddList_tailnode(head, "°¢¿¨Àö",2);
	AddList_tailnode(head, "°¢Ä¾Ä¾",3);
	AddList_tailnode(head, "²¼Â¡",4);
	AddList_tailnode(head, "ÃÀ¶ÅÉ¯",5);
	List_reverse(head);

	PrintList(head);


	return 0;
}
