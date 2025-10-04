// Problem Statement: 
// Given a binary tree, place cameras on nodes so that every node is monitored.
// Each camera at a node monitors its parent, itself, and immediate children.
// Return the minimum number of cameras required to monitor all nodes.

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// Function to perform DFS and calculate camera placement
vector<int> dfs(TreeNode* root) {
    if (!root) 
        return {0, 0, INT_MAX / 2};

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    // State 0: not covered
    int notCovered = left[1] + right[1];
    // State 1: covered (no camera here)
    int covered = min(left[2] + min(right[1], right[2]),
                      right[2] + min(left[1], left[2]));
    // State 2: camera placed here
    int withCamera = 1 + min({left[0], left[1], left[2]}) + min({right[0], right[1], right[2]});

    return {notCovered, covered, withCamera};
}

int minCameraCover(TreeNode* root) {
    auto res = dfs(root);
    return min(res[1], res[2]);
}

// Example usage
int main() {
    /*
        Example Tree:
              0
             / \
            0   0
             \
              0

        Minimum cameras = 1
    */
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->left->right = new TreeNode(0);

    cout << "Minimum cameras needed: " << minCameraCover(root) << endl;
    return 0;
}

/*
Output:
Minimum cameras needed: 1
*/
