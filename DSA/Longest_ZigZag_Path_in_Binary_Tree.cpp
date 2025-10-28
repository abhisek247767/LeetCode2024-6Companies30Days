/*
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3

Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Constraints:
The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100

Approach: Returning pair of left and right length

TC: O(N)
*/

class Solution {
public:
    
    int maxPath = 0;
    
    vector<int> solve(TreeNode* root) {
        if(root == NULL)
            return {0, 0};
        
        vector<int> reL = solve(root->left);
        vector<int> reR = solve(root->right);
        
        int L = reL[0];
        int R = reR[1];
        
        maxPath = max({maxPath, L, R});
        
        return {R+1, L+1};
    
    }
    
    int longestZigZag(TreeNode* root) 
    {
        solve(root);
        return maxPath;
    }
};
