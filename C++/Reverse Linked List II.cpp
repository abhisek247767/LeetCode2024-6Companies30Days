//using Linkedlist
ListNode*reverseBetween(ListNode*head,int left,int right){
	vector<int>nums;
	while(head){
		nums.push_back(head->val);
		head = head->next;
	}
	
	reverse(nums.begin()+left-1,nums.begin()+right);
	ListNode*ans = new ListNode(-1);
	ListNode*temp = ans;
	
	for(auto it:nums){
		ListNode*curr = new ListNode(it);
		temp->next = curr;
		temp = curr;
	}
	return ans->next;
}
