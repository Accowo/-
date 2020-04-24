typedef struct node{
	char name[20];
	int date;
	struct node *next;
}NODE;

NODE *MergeList(NODE *head1,NODE *head2){

	NODE *newhead = head1;
	NODE *pos = newhead;
	NODE *index1 = head1->next;
	NODE *index2 = head2->next;

	while (index1 != NULL && index2 != NULL){
		if (index1->date <= index2->date){
			pos->next = index1;
			index1 = index1->next;
		}
		else {
			pos->next = index2;
			index2 = index2->next;
		}
		pos = pos->next;
	}

	if (index1 == NULL){
		pos->next = index2;
	}
	if (index2 == NULL){
		pos->next = index1;
	}

	return newhead;
}
