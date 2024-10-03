"""
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.split()[-1])
    

"""
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
"""