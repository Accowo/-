void hasCycle(struct NODE *head){
	struct NODE *slow = head;
	struct NODE *fast = head;
	
	while (fast != NULL && fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast){
			printf("�л�\n");
		}
		
	}
	printf("û�л�\n");
}
