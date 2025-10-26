class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.isEmpty()) {
            return "";
        }

        if (s.length() == 1) {
            return s;
        }

        String longest = s.substring(0, 1); // Single character is the minimum palindrome

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome (center at i)
            String tmp = expandAroundCenter(s, i, i);
            if (tmp.length() > longest.length()) {
                longest = tmp;
            }

            // Even length palindrome (center between i and i+1)
            tmp = expandAroundCenter(s, i, i + 1);
            if (tmp.length() > longest.length()) {
                longest = tmp;
            }
        }

        return longest;
    }

    private String expandAroundCenter(String s, int left, int right) {
        // Expand as long as characters are equal and indices are valid
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }

        // Substring from left+1 to right (exclusive)
        return s.substring(left + 1, right);
    }
}
