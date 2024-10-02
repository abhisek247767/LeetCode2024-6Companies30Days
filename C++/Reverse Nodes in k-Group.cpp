//using Linkedlist+recursion
ListNode*reveresKGroup(ListNode*head,int k){
	if(head==NULL ||head->next==NULL){
		return head;
	}
	
	ListNode*prev = NULL;
	ListNode*curr = head;
	ListNode*fowd;
	
// Check whether 'k' no. of nodes present in list or not
	if(!possible(head,k)){
		return head;
	}
	
	//reverse first 'k' nodes
	for(int i=0;i<k;i++){
		fowd = curr->next;
		
		curr->next = prev;
		prev = curr;
		curr = fowd;
		
		if(curr==NULL){
			return prev;
		}
	}
	head-next = reverseKGroup(curr,k);
	return prev;
}

	bool possible(ListNode*head,int k){
		int length =0;
		ListNode*temp = head;
		
		while(temp!=NULL){
			temp = temp->next;
			length++;
		if(length>=k){
			return true;
		}
	}
	return false;
}
