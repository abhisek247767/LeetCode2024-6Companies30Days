'''
Question : We are given an array with consecutive natural numbers , with one number missing 
           We have to return that number .
Example : Input = a =[1,2,3,4,5,6,8,9,10]
          output = 7
Approach : There exists a very simple approach to this problem . But , overthinking can mess it up,
           Sum= (n(n+1))/2 is the formula for sum of n natural numbers , if we subtract then sum of 
           elements of the given array with this then the result will be the remaining number .
           where , n = len(a)
'''
class Solution:
    def missingNumber(self, nums: list[int]) -> int:
         n = len(nums)
         expected_sum = n * (n + 1) // 2
         actual_sum = sum(nums)
         return expected_sum - actual_sum