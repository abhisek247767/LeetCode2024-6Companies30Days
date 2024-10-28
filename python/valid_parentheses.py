"""
Problem statement:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

"""
class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # create a stack to the brackets
        stacks = []

        # define the brackets and their corresponding pairs
        brackets = {')': '(', '}': '{', ']': '['}

        # iterate over each character in the string
        for char in s:
            # if the character is an open bracket, push it to the stack
            if char in brackets.values():
                stacks.append(char)
            # if the character is a close bracket
            else:
                # if the stack is empty or the top of the stack does not match the corresponding open bracket, return False
                if not stacks or brackets[char] != stacks.pop():
                    return False

        # if the stack is empty, the string is valid
        return not stacks


# Example usage:
"""
Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

Input: s = "([)]"
Output: false
"""