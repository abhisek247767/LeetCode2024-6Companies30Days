class Solution:
    def minimumSteps(self, s: str) -> int:
        
        cnt = 0

        pos = 0

        for i in range(len(s)):

            if s[i] =='0':

                cnt += i - pos

                pos += 1

        return cnt