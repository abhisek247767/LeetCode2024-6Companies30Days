/*
Leetcode 322
Problem Link: https://leetcode.com/problems/coin-change/description/

You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/ 

#include <bits/stdc++.h>
#define mod 1e9 + 7
#define pb push_back
#define pob pop_back
using namespace std;
int coinChange(vector<int> &coins, int target);

int dp[12][10000 + 1];
int solve(int index, int target, vector<int> &coins)
{
    if (index >= coins.size() || target <= 0)
        return target == 0 ? 0 : INT_MAX - 1;

    if (dp[index][target] != -1)
        return dp[index][target];

    int res = -1;
    if (coins[index] > target)
    {
        int notTake = solve(index + 1, target, coins);
        dp[index][target] = res = notTake;
    }
    else
    {
        int take = 1 + solve(index, target - coins[index], coins);
        int notTake = solve(index + 1, target, coins);
        dp[index][target] = res = min(take, notTake);
    }

    return dp[index][target] = res;
}
int coinChange(vector<int> &coins, int target)
{
    if (target == 0)
        return 0;

    memset(dp, -1, sizeof(dp));
    int res = solve(0, target, coins);

    return res == INT_MAX - 1 ? -1 : res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int n;
    // cin>>n;
    // vector<int> v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    vector<int> v ={1,2,5}; 
    int target = 11;
    // int target;
    // cin>>target;

    int res = coinChange(v,target);
    cout<<res<<'\n';

    return 0;
}
