#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPivot(vector<int> &nums, int n)
    {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        while (s < e)
        {
            if (nums[mid] >= nums[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }

    int binarySearch(vector<int> nums, int s, int e, int target)
    {
        int start = s;
        int end = e;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int> nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return -1;

        int pivot = findPivot(nums, n);
        if (target >= nums[pivot] && target <= nums[n - 1])
        {
            return binarySearch(nums, pivot, n - 1, target);
        }
        else
        {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};
