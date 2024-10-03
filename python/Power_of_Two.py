"""
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
"""


from math import *
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        return ceil(log2(n))==floor(log2(n))
    

"""
Input: n = 16
Output: true

Input: n = 3
Output: false
"""