"""
Given an array of integers nums and an integer target, return indices of the three numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
"""

class Solution:
    def threeSum(self, nums: list[int], target: int) -> list[int]:
        n = len(nums)
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                for k in range(j + 1, n):
                    if nums[i] + nums[j] + nums[k] == target:
                        return [i, j, k]

# Example usage:
"""
Input: nums = [1, 2, 3, 4, 5], target = 9
Output: [0, 1, 3]
Explanation: Because nums[0] + nums[1] + nums[3] == 9, we return [0, 1, 3].

Input: nums = [0, -1, 2, -3, 1], target = 0
Output: [0, 2, 3]
"""
