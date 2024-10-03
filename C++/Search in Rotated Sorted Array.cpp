// Problem statement

/* 
LeetCode- https://leetcode.com/problems/search-in-rotated-sorted-array/description/
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity. 

Constraints:
1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
 */


// Solution

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& A, int tar) {
        int st = 0,end = A.size()-1;

        while(st <= end){
            int mid = (st+end)/2;
            if(A[mid] == tar){
                return mid;
            }

            if(A[st] <= A[mid]){
                if(A[st] <= tar && tar <= A[mid]){
                    end = mid-1;
                }else{
                    st = mid+1;
                }
            } else{
                if(A[mid] <= tar && tar <=A[end]){
                st = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
    
};


// Expected output

/*
test case 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

test case 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

test case 3:
Input: nums = [1], target = 0
Output: -1

*/