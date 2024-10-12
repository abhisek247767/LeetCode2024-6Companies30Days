/*
Approach:
- Given an integer x, return true if x is a palindrome, and false otherwise.
Time Complexity: O(log₁₀(n))
- The time complexity is O(log₁₀(n)), where n is the input number, because we are dividing the number by 10 in each iteration of the loop.
Space Complexity: O(1)
- The space complexity is O(1) since we are using only a few extra variables.
Example 1:
- Input: x = 121
- Output: true
- Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:
- Input: x = -121
- Output: false
- Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
- Input: x = 10
- Output: false
- Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

class Solution {
    public static boolean isPalindrome(int x) {
        // If the number is negative or if it ends with 0 (but is not 0 itself), it can't be a palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse the second half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // If the number has an odd number of digits, we can get rid of the middle digit by reversedHalf / 10
        // For example, when x is 12321, at the end of the loop we have x = 12, reversedHalf = 123,
        // so we remove the last digit from reversedHalf.
        return x == reversedHalf || x == reversedHalf / 10;
    }

    public static void main(String[] args) {
        System.out.println(isPalindrome(121));   // true
        System.out.println(isPalindrome(-121));  // false
        System.out.println(isPalindrome(10));    // false
        System.out.println(isPalindrome(1221));  // true
    }
}
