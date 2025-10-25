class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq;
        
        for (char c : s) 
            freq[c]++;
        
        unordered_map<int, vector<char>> grp;
        
        for (auto p : freq) {
            grp[p.second].push_back(p.first);
        }
        
        int mxsz = 0, bstfreq = 0;
        vector<char> ans;
        
        for (auto pr : grp) {
            int k = pr.first;
            vector<char> ch = pr.second;
            int sz = ch.size();
            
            if (sz > mxsz || (sz == mxsz && k > bstfreq)) {
                mxsz = sz;
                bstfreq = k;
                ans = ch;
            }
        }
        
        return string(ans.begin(), ans.end());
    }
};
