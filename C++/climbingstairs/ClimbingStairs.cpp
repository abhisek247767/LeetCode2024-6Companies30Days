class Solution
{
public:
    int climbStairs(int n)
    {
     if(n<=1)return 1;

     vector<int>dp;
     dp.assgin(n+1,-1);
     
       for(int i=0;i<=n;i++){
        if(i>=2)
        dp[i]=dp[i-1]+dp[i-2];
        else
        dp[i]=1;
       }

       return dp[n];
    }
};