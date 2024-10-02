//using Two Pointers approach
ListNode*rotateRight(ListNode*head,int k){
	if(head==NULL)
		return NULL;
	int n =1;
	ListNode*tail = head;
	while(tail->next){
		n++:
		tail = tail->next;
	}
	
	tail->next = head;
	
	int sz = n-k%n;
	for(int i=0;i<sz;i++){
		tail = tail->next;
	}
	
	head = tail->next;
	tail->next =NULL;
	return head;
}