"""
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
"""



class Solution:
    def mySqrt(self, x: int) -> int:
        if x==1:
            return 1
        result=1
        for i in range(0,int(x/2)+1):
            if i*i<=x:
                result =i
            else:
                break
        return result
    

"""
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Input: x = 8
Output: 2
"""