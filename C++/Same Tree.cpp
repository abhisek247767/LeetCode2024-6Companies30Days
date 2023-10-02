//using binary Tree
bool isSameTree(TreeNode*p,TreeNode*q){
	if(p==NULL && q==NULL){
		return true;
	}
	else if(p&&q ==NULL ||q&&p==NULL){
		return false;
	}
	else{
		if(p->val==q->val){
			if(isSameTree(p->left,q->left) && isSameTree(p->right,q->right)){
				return true;
			}
		}
	}
	return false;
}