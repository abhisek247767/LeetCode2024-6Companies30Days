/*199. Binary Tree Right Side View
Medium
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
(PROBLEM LINK: https://leetcode.com/problems/binary-tree-right-side-view/)*/
//TIME-COMPLEXITY: O(N) WHERE N IS NUMBER OF NODES IN THE TREE

//SOLUTION
// BFS: pick last node of each level
/* 199. Binary Tree Right Side View
   BFS level-order: pick the last node of each level.
   Time: O(N), Space: O(W) (queue), where W is max width. */

#include <bits/stdc++.h>   // If unavailable, replace with: <iostream>, <vector>, <queue>, <optional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
                if (i == sz - 1) ans.push_back(node->val); 
            }
        }
        return ans;
    }
};


TreeNode* buildTree(const vector<optional<int>>& a) {
    if (a.empty() || !a[0].has_value()) return nullptr;
    vector<TreeNode*> nodes(a.size(), nullptr);
    for (size_t i = 0; i < a.size(); ++i)
        if (a[i].has_value()) nodes[i] = new TreeNode(*a[i]);
    for (size_t i = 0, j = 1; j < a.size(); ++i) {
        if (nodes[i]) {
            if (j < a.size()) nodes[i]->left  = nodes[j++];
            if (j < a.size()) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

int main() {
    
    vector<optional<int>> arr = {1,2,3, nullopt,5, nullopt,4};
    TreeNode* root = buildTree(arr);

    Solution sol;
    vector<int> view = sol.rightSideView(root);

    for (size_t i = 0; i < view.size(); ++i) {
        if (i) cout << " ";
        cout << view[i];
    }
    cout << "\n";
    return 0;
}
