/*
# Problem:Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3

Example 2:
Input: s = "bbbbb"
Output: 1

Example 3:
Input: s = "pwwkew"
Output: 3

# Aproach
    1. Initialization: Use a boolean vector count to track characters and two pointers (first and second) to represent the substring bounds.

    2. Iterate: Move the second pointer through the string:
        If s[second] is a duplicate, increment first until it's removed.
    3. Update: Mark s[second] as present and update the maximum length (len).
    4. Return: Output the longest length found.

*/
/*Solution Implementation: */
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Create a vector to track characters in current substring
        vector<bool> count(256, 0);
        int first = 0, second = 0, len = 0;

        // Iterate over the string using the 'second' pointer
        while (second < s.length())
        {
            // If character at 'second' is already in current substring
            while (count[s[second]])
            {
                count[s[first]] = 0;
                first++;
            }
            count[s[second]] = 1; // char at 'second' as seen
            // Update the max length
            len = max(len, second - first + 1);
            second++; // Move the end index to the right
        }
        return len; // Return the length
    }
};

/*
## Time and Space Complexity:
- Time Complexity: O(n) — Single pass through the string.

- Space Complexity: O(1) — Constant space for the boolean vector (256 elements).

## Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.

*/