//using Recursive approach
bool hasPathSum(TreeNode*root,int targetSum){
	if(!root)
	return false;
	
	if(!root->left && !root->right && root->val == targetSum)
	return true;
	else
	return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val));
}