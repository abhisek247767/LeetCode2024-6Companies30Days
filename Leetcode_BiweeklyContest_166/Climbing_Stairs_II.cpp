#define ll long long
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<ll> dp(n+1, LLONG_MAX);
        dp[0] = 0; 

        for (int i = 1; i <= n; i++) {
            if(i >= 1) 
                dp[i] = min(dp[i], dp[i-1] + (ll)costs[i-1] + 1LL*1*1);
            if(i >= 2) 
                dp[i] = min(dp[i], dp[i-2] + (ll)costs[i-1] + 1LL*2*2);
            if(i >= 3) 
                dp[i] = min(dp[i], dp[i-3] + (ll)costs[i-1] + 1LL*3*3);
        }

        return (int)dp[n];
    }
};
