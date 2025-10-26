class Solution {
    public int lengthOfLastWord(String s) {
        // Remove leading and trailing spaces
        String trimmed = s.trim();
        int len = 0;

        // Iterate through each character
        for (int i = 0; i < trimmed.length(); i++) {
            if (trimmed.charAt(i) == ' ') {
                // Reset length when a space is encountered
                len = 0;
            } else {
                // Increment length for a non-space character
                len++;
            }
        }

        return len; // Length of the last word
    }
}
