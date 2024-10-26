"""
Problem statement:
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

"""



class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
    # Check if the input is a negtaive number, palindrome are not negative values  

        if x < 0:
            return False
        
    # Convert the number to a string and reverse it
        
        str_x = str(x)
        reversed_str_x = str_x[::-1]
        
    # Compare the original number with its reversed version
        
        return str_x == reversed_str_x


# Example usage
"""
Input: x = 121
Output: true

Input: x = -121
Output: false

Explanation: From left to right, it reads -121. 
From right to left, it becomes 121-. Therefore it is not a palindrome.
"""
        