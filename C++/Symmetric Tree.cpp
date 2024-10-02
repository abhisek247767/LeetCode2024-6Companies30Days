//using recursive approach
bool isTreeSymmetric(TreeNode*leftRoot,Treenode*rightRoot){
	if(leftRoot==NULL && rightRoot==NULL)
	return true;
	if((leftRoot==NULL && rightRoot!=NULL) ||(leftRoot!=NULL && rightRoot==NULL))
	return false;
	if(leftRoot->val!=rightRoot->val)
	return false;
	return isSymmetric(leftRoot->left,rightRoot->val) && isSymmetric(leftRoot->right,rightRoot->left);
}

bool isSymmetric(TreeNode*root){
	return isSymmetric(root->left,root->right);
}