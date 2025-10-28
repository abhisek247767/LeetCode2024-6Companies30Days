#Basic Calculator(224)
# problem statement : Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
#Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
# Time Complexity: O(n)
# Space Complexity: O(n)

class Solution:
    def calculate(self, s: str) -> int:
        stk = []
        ans, sign = 0, 1
        i, n = 0, len(s)
        while i < n:
            if s[i].isdigit():
                x = 0
                j = i
                while j < n and s[j].isdigit():
                    x = x * 10 + int(s[j])
                    j += 1
                ans += sign * x
                i = j - 1
            elif s[i] == "+":
                sign = 1
            elif s[i] == "-":
                sign = -1
            elif s[i] == "(":
                stk.append(ans)
                stk.append(sign)
                ans, sign = 0, 1
            elif s[i] == ")":
                ans = stk.pop() * ans + stk.pop()
            i += 1
        return ans
    

# Input:
# s = "2 - (3 - 4)"

# Output:
# 3

# Explanation:
# 2 - (3 - 4) → 2 - (-1) → 3    