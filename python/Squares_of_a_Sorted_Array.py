"""
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
"""

class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        return sorted([num * num for num in nums])
    
"""
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100]. After sorting, it becomes [0,1,9,16,100].
"""