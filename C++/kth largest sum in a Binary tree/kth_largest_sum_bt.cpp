/*
PROBKEM STATEMENT:
You are given the root of a binary tree and a positive integer k.
The level sum in the tree is the sum of the values of the nodes that are on the same level.
Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
Note that two nodes are on the same level if they have the same distance from the root.

Output: A long long value that depicts the answer to the problem statement.

Example:

Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> ans;
    deque<TreeNode*> q;

    void bfs(TreeNode* root){
        q.push_back(root); //pushes the current head into the queue

        while(!q.empty()){// while the tree still has values
            long long sum = 0;
            int n = q.size(); 
            for(int i=0;i<n;i++){ //traversing each level, one at a time
                TreeNode* node = q.front();
                sum += node -> val; // sum at each level

                if(node -> left){
                    q.push_back(node -> left);
                }
                if(node -> right){
                    q.push_back(node -> right);
                }
                q.pop_front();
            }
            ans.push_back(sum); // storing the sum at each level
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        bfs(root); // bfs function called
        if(ans.size() < k){ // if there are less than k levels
            return -1;
        }
        sort(ans.rbegin(), ans.rend()); // to get the kth largest value
        return ans[k-1];
    }
};