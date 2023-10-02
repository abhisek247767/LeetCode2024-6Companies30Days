//using DFS + binary search Tree
bool help(TreeNode*root,long low,long high){
	if(root==NULL)
	return true;

if((root->val>low) && (root->val<high)){
	return (help(root->left,low,root->val) && help(root->right,root->val,high));
}
else{
	return false;
 }
}

bool isValidateBST(TreeNode*root){
	bool ans = help(root,LONG_MIN,LONG_MAX);
	return ans;
}