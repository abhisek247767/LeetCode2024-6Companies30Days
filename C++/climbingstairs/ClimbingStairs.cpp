/*
Problem Statement:
Given an integer n, return the number of distinct ways to climb to the top of a staircase.
You can climb either 1 or 2 steps at a time.

Time Complexity: O(n)
   - Each step is computed once using dynamic programming.
Space Complexity: O(n)
   - An array is used to store intermediate results.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;

        vector<int> dp(n + 1, -1);

        for (int i = 0; i <= n; i++) {
            if (i >= 2)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = 1;
        }

        return dp[n];
    }
};

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    Solution solution;
    cout << "Number of distinct ways to climb: " << solution.climbStairs(n) << endl;

    return 0;
}

/*
Sample Test Case:
Input:
Enter number of steps: 5
Output:
Number of distinct ways to climb: 8
*/
