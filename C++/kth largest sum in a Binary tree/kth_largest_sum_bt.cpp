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
        q.push_back(root);

        while(!q.empty()){
            long long sum = 0;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                sum += node -> val;

                if(node -> left){
                    q.push_back(node -> left);
                }
                if(node -> right){
                    q.push_back(node -> right);
                }
                q.pop_front();
            }
            ans.push_back(sum);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        bfs(root);
        if(ans.size() < k){
            return -1;
        }
        sort(ans.rbegin(), ans.rend());
        return ans[k-1];
    }
};