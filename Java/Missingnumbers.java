//https://leetcode.com/problems/missing-number/description/
// 268. Missing Number

class Solution {
    public int missingNumber(int[] nums) {
        // Calculate the expected sum of the numbers from 0 to n (inclusive)
        int n = nums.length;
        int originalSum = (n * (n + 1)) / 2;
        
        // Subtract each number in the array from the original sum
        for (int num : nums) {
            originalSum -= num;
        }
        
        // The remaining sum is the missing number
        return originalSum;
    }
}

/*
Example 1:

Input: nums = [3, 7, 1, 2, 8, 4, 5]
Output: 6

Explanation:
The array contains numbers from 0 to 8, except for 6. The missing number is 6.
 */
