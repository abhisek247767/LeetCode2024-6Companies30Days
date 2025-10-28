# Problem Statement: LeetCode 1221 - Split a String in Balanced Strings
# Given a string s consisting of 'L' and 'R' characters, split it into the maximum number of balanced strings.
# A balanced string is one where the number of 'L' and 'R' characters are equal.
# Time Complexity: O(N)
# Space Complexity: O(1)

def balancedStringSplit(s):
    balance = 0
    count = 0
    for ch in s:
        if ch == 'L':
            balance += 1
        else:
            balance -= 1
        if balance == 0:
            count += 1
    return count

# Example
print(balancedStringSplit("RLRRLLRLRL"))  # Output: 4
