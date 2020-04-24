#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	int number;
	struct node *next;
}NODE;

NODE *CreatList_headnode(){

	NODE *head = (NODE*)malloc(sizeof(NODE));
	if (head == NULL){
		exit(0);
	}
	head->number = 1; //��һ���˵ı��
	head->next = head;//һ���˵Ļ�

	return head;
}
void AddList_Cycle(NODE *head ,int number){   //β������

	NODE *pos = head;
	NODE *pnew = (NODE*)malloc(sizeof(NODE));

	if (pnew == NULL){
		exit(0);
	}

	pnew->number = number;

	while (pos->next != head){
		pos = pos->next;
	}

	pnew->next = head;
	pos->next = pnew;

}

NODE *Del(NODE *head, int number){

	NODE *index1 = head;
	NODE *index2 = head->next;

	while (1){
		if (index2->number == number){
			index1->next = index2->next;
			free(index2);
			index2 = index1->next;
			return index2;
		}
		else {
			index1 = index1->next;
			index2 = index2->next;
		}
	}
}

void DestoryList(NODE **head){  //�βζ���ָ��,һ��ָ���޷��ı�head��ָ��
	NODE *p = *head;
	while ((*head)->next != *head){
		p = (*head)->next;
		(*head)->next = p->next;
		free(p);
	}
	free(*head);
	*head = NULL; //ʹheadָ��NULL,
}
bool hasCycle(NODE *head){
	NODE *slow = head;
	NODE *fast = head;

	while (fast != NULL && fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast){
			printf("�л�\n");
			return 1;
		}

	}
	printf("û�л�\n");
	return 0;
}
int main(){

	NODE *head = CreatList_headnode();
	int i;
	int j = 0;  //����
	int n = 10; //������
	int k = 4;  //������
	for (i = 2; i <= n; i++){
		AddList_Cycle(head, i);
	}
	
	NODE *p1 = head;
	NODE *p2 = head->next;
	
	while (head->next != head){
		j++;
		if (j == k){
			j = 0;
			printf("%d ", p1->number);
			head = Del(head, p1->number);
		}
		p1 = p2;
		p2 = p2->next;
	}
	printf("\n����߱��:%d", head->number);
	DestoryList(&head);
	return 0;
}
