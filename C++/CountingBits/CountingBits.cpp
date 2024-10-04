#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int num)
    {
        int count;
        vector<int> dp(num + 1, 0);

        for (int i = 1; i <= num; i++)
        {
            if (i % 2 == 0)
                dp[i] = dp[i / 2];
            else
                dp[i] = dp[int(i / 2)] + 1;
        }

        return dp;
    }
};