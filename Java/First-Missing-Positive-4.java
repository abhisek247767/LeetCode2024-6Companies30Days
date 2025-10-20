// 41. First Missing Positive (https://leetcode.com/problems/first-missing-positive/)
// problem statement: Given an unsorted integer array nums, return the smallest missing positive integer.
// Time Complexity: O(n), space Complexity: O(1)

class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;

        // Place each number at its correct index if possible
        for (int i = 0; i < n; i++) {
            while (
                nums[i] > 0 && nums[i] <= n &&
                nums[nums[i] - 1] != nums[i]
            ) {
                // Swap nums[i] with nums[nums[i] - 1]
                int correctIndex = nums[i] - 1;
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            }
        }

        // After sorting, the first number not in the right place tells us the answer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // All numbers are in correct place, so the missing one is n + 1
        return n + 1;
    }
}

// Input: [1, 2, 0]
// Step after cyclic sort: [1, 2, 0]
// First missing positive: 3

// Output:
// 3