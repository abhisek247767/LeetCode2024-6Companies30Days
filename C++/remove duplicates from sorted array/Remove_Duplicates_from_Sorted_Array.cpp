#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int uniqueCount = 1;
        int n = nums.size();

        for (int i = 1; i < n; ++i)
        {

            if (nums[i] != nums[i - 1])
            {

                nums[uniqueCount] = nums[i];

                uniqueCount++;
            }
        }

        return uniqueCount;
    }
};