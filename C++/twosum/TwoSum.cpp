#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> a;
        int sum = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum = nums[i] + nums[j];
                if (sum == target)
                {
                    a.push_back(i);
                    a.push_back(j);
                }
            }
        }
        return a;
    }
};