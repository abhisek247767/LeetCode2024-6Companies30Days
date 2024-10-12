#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find the peak index in a mountain array
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int start = 0, end = n - 1, mid;

        // Binary search to find the peak index
        while (start <= end)
        {
            mid = start + (end - start) / 2; 

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            {
                return mid; // Return peak index
            }
            else if (arr[mid - 1] < arr[mid]) 
                start = mid + 1;
            else 
                end = mid - 1;
        }
        return -1; // Return -1 if no peak is found
    }
};
