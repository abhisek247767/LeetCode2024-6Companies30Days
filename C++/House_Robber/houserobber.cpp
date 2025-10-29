/*
# Problem Statement:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
but robbing two adjacent houses will alert the police.

# Approach:
Using Memoization (Top-Down Dynamic Programming)

# Time Complexity: O(N)
# Space Complexity: O(N) — for recursion + dp array
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function for memoization
    int solve(int index, vector<int>& nums, vector<int>& dp) {
        if (index == 0) return nums[index];
        if (index < 0) return 0;
        if (dp[index] != -1) return dp[index];

        int pick = nums[index] + solve(index - 2, nums, dp);
        int notPick = solve(index - 1, nums, dp);
        return dp[index] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter money in each house: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Maximum money that can be robbed: " << s.rob(nums) << endl;
    return 0;
}
