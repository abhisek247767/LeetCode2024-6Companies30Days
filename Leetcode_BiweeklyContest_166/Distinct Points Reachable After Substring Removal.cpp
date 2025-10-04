class Solution {
public:
    int distinctPoints(string s, int k) {  
        int n = s.size();
        vector<int> px(n + 1, 0), py(n + 1, 0);

        for (int i = 0; i < n; i++) {
            px[i+1] = px[i];
            py[i+1] = py[i];

            switch (s[i]) {
                case 'U': py[i+1]++; break;
                case 'D': py[i+1]--; break;
                case 'L': px[i+1]--; break;
                case 'R': px[i+1]++; break;
            }
        }

        set<pair<int,int>> ans;
        for (int i = 0; i <= n - k; i++) {
            int x = px[i] + (px[n] - px[i+k]);
            int y = py[i] + (py[n] - py[i+k]);
            ans.insert({x, y});
        }

        return ans.size();
    }
};
