#214. Shortest Palindrome
#Problem Statement: You are given a string s. You can convert s to a palindrome by adding characters in front of it.
#Time Complexity: O(n)
#Space Complexity: O(1)
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        base = 131
        mod = 10**9 + 7
        n = len(s)
        prefix = suffix = 0
        mul = 1
        idx = 0
        for i, c in enumerate(s):
            prefix = (prefix * base + (ord(c) - ord('a') + 1)) % mod
            suffix = (suffix + (ord(c) - ord('a') + 1) * mul) % mod
            mul = (mul * base) % mod
            if prefix == suffix:
                idx = i + 1
        return s if idx == n else s[idx:][::-1] + s
    
# Input:
# s = "aacecaaa"

# Output:
# "aaacecaaa"

# Explanation:
# The shortest palindrome formed by adding characters in front of "aacecaaa" is "aaacecaaa".    