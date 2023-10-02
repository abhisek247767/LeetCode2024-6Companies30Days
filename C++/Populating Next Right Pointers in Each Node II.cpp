//using Binary Tree
Node*connect(Node*root){
	vector<Node*>q;
	q.push_back(root);
	while(!q.empty()){
		vector<Node*>t;
		if(q[0]==NULL)
		return root;
		for(auto x:q){
			if(x->left)
			t.push_back(x->left);
			if(x->right)
			t.push_back(x->right);
		}
		for(int i=0;i<q.size()-1;i++){
			q[i]->next = q[i+1];
		}
		swap(q,t);
	}
	return root;
}