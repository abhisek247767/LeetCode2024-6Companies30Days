//using Two pointers approach
ListNode*removeNthfromEnd(ListNode*head,int n){
	ListNode*slow = head;
	ListNode*fast = head;
	
	for(int i=0;i<n;i++){
		fast = fast->next;
	}
	
	if(fast==NULL){
		slow = slow->next;
		delete head;
		return slow;
	}
	
	while(fast->next!=NULL){
		fast = fast->next;
		slow = slow->next;
		
		ListNode*temp = slow->next;
		slow->next = slow->next>next;
		delete temp;
		
		return head;
	}
}