'''
we have been given a Random list containing zeros , 
We have to move all the zeros in the list to the end .

Example 1: input l1=[1,0,2,0,3,0]
           Output l1=[1,2,3,0,0,0]
Example 2: input l1=[0]
           output l1=[0] 
Example 3 :input l1=[1,2,0,0]
           output l1=[1,2,0,0]


'''

class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Pointer to keep track of the position of the last non-zero element
        last_non_zero = 0

        # Iterate through the array
        for i in range(len(nums)):
            # If the current element is not zero, swap it with the element at last_non_zero index  
            if nums[i] != 0:
                nums[last_non_zero], nums[i] = nums[i], nums[last_non_zero]
                last_non_zero += 1
