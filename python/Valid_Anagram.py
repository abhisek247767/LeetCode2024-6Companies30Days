"""
Given two strings s and t, return true if t is an 
anagram of s, and false otherwise.
"""

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count = 0
        if len(s)== len(t):
            for i in s:
                s_count = s.count(i)
                if i in t and t.count(i)==s_count:
                    count+=1
            if count==len(t):
                return True

        return False
    

"""
Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
"""