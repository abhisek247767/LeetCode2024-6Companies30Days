// 32. Longest Valid Parentheses (https://leetcode.com/problems/longest-valid-parentheses/description/)
// Problem statement: Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

//Time Complexity: O(n), Space Complexity: O(n)

class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            if (s.charAt(i - 1) == ')') {
                if (s.charAt(i - 2) == '(') {
                    f[i] = f[i - 2] + 2;
                } else {
                    int j = i - f[i - 1] - 1;
                    if (j > 0 && s.charAt(j - 1) == '(') {
                        f[i] = f[i - 1] + 2 + f[j - 1];
                    }
                }
                ans = Math.max(ans, f[i]);
            }
        }
        return ans;
    }
}