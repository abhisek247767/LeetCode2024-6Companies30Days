class Solution {
public:
    map<int, vector<int>> tree;     
    vector<vector<int>> adj;        
    vector<int> vis;                

    void dfs(int node, int t) {
        tree[t].push_back(node);
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, t);
            }
        }
    }

    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        adj.resize(n);

        for (auto &it : swaps) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vis.resize(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, cnt);
                cnt++;
            }
        }

        long long ans = 0ll;

        for (int i = 0; i < cnt; i++) {
            vector<long long> val;
            for (auto idx : tree[i]) {
                val.push_back(nums[idx]);
            }
            sort(val.begin(), val.end());

            int l = 0, r = val.size() - 1;
            for (auto idx : tree[i]) {
                if (idx & 1) {      
                    ans -= val[l++];
                } else {           
                    ans += val[r--];
                }
            }
        }

        return ans;
    }
};