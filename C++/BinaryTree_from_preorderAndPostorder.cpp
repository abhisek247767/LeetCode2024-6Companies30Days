#include<bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
TreeNode* Tree(vector<int>& pre, vector<int>& in,int Start,int End,int index,unordered_map<int,int>&mp){
    if(Start>End)return NULL;

TreeNode * root=new TreeNode(pre[index]);
    int value=pre[index];
    int pos=mp[value];

    //left side
    root->left=Tree(pre,in,Start,pos-1,index+1,mp);
    //right side
    root->right=Tree(pre,in,pos+1,End,index+(pos-Start)+1,mp);
return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int, int>mp;
       int n=preorder.size();
       for(int i=0;i<n;i++){
        mp[inorder[i]]=i;
       }
       return Tree(preorder,inorder,0,n-1,0,mp); 
    }
};
