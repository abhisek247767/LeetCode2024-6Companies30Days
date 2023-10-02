//using depth first search(DFS)
int dfs(TreeNode*root,int sum){
	if(!root){
		return;
	}
	sum = sum*10+root->val;
	if(!root->left && !root->right){
		return sum;
	}
	return dfs(root->left,sum)+dfs(root->right,sum);
}
int sumNumbers(TreeNode*root){
	return dfs(root,0);
}