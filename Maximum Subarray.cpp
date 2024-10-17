// Problem Statement

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

*/

// Solution

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];

        for(int i = 0 ; i<nums.size() ; i++){
            sum = sum + nums[i];

            maxi = max(maxi , sum);

            if(sum < 0)
            sum = 0;
        }
        return maxi;
    }
};



// Expected Output

/*
Test Case 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Test Case 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
*/