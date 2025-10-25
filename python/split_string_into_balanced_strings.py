'''
LeetCode 1221 — Split a String in Balanced Strings

You are given a string s consisting of only 'L' and 'R'.
A balanced string is one where the number of 'L' and 'R' characters are equal.

Your goal is to split the given string into the maximum number of balanced substrings and return that count.
Example 1:
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: The balanced strings are "RL", "RRLL", "RL", "RL".
Example 2:
Input: s = "RLLLLRRRLR"
Output: 3
Explanation: The balanced strings are "RL", "LLLRRR", "LR".

Intitution:
We want to count how many times we can form a balanced substring — that means the count of 'L' and 'R' becomes equal.

To track this balance, the solution uses a variable b (let’s call it balance) and another variable a (the answer count).

When we see an 'L', we increase the balance (b += 1).

When we see an 'R', we decrease the balance (b -= 1).

Whenever the balance reaches 0, it means we’ve found one balanced substring.
→ Increment a (our result counter).
'''

class Solution:
    def balancedStringSplit(self, s: str) -> int:
        b=0
        a=0
        if len(s)==2:
            if s.count('L')==1 and s.count('R')==1:
                return(1)
            else:
                return(0)
        else:
            
            for i in range(0,len(s),1):
                if s[i]=='L':
                    b+=1
                    if b==0:
                        a+=1
                elif s[i]=='R':
                    b-=1
                    if b==0:
                        a+=1
        return(a)