/* # Problem: Peak Index in a Mountain Array

You are given an integer mountain array `arr` of length `n` where the values increase to a peak element and then decrease.
Your task is to find and return the index of the peak element in O(log(n)) time complexity.

## Example 1:
Input: arr = [0,1,0]  
Output: 1

## Example 2:
Input: arr = [0,2,1,0]  
Output: 1

## Example 3:
Input: arr = [0,10,5,2]  
Output: 1

## Approach:

1. Use binary search to find the peak index.
2. Initialize pointers `start` and `end` to the beginning and end of the array, respectively.
3. Calculate the middle index `mid` and check if it is the peak.
4. If the left neighbor is less than `mid` and the right neighbor is less than `mid`, return `mid` as the peak index.
5. If the left neighbor is greater than `mid`, search in the left half; otherwise, search in the right half.
6. Continue until the peak index is found.

*/
/*Solution Implementation: */

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
/*

## Time Complexity:
- **O(log n)**: Each step reduces the search space by half.

## Space Complexity:
- **O(1)**: No extra space is used; only a few variables are required for pointers and indices.

## Constraints:
- `3 <= arr.length <= 10^5`
- `0 <= arr[i] <= 10^6`
- The array is guaranteed to be a mountain array.

## Resouce
[LeetCode](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

*/
