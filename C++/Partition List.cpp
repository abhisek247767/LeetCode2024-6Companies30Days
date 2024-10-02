//using Two pointers approach
ListNode*partition(ListNode*head,int x){
	if(head==NULL){
		return NULL;
	}
	
	vector<int>v;
	while(head){
		v.push_back(head->val);
		head = head->next;
	}
	vector<int>vec;
	for(int i=0;i<vec.size();i++){
		if(v[i]<x){
		vec.push_back(v[i]);
		v.erase(v.begin()+i);
		i--;
	}
}
	reverse(v.begin().v.end());
	for(int i=vec.size()-1;i>=0;i--){
		v.push_back(vec[i]);
	}
	
	reverse(v.begin(),v.end());
	ListNode*root=NULL;
	for(int i= v.size()-1;i>=0;i--){
		ListNode*temp = new ListNode;
		temp->val = v[i];
		temp->next = root;
		root=temp;
	}
	return root;
}
