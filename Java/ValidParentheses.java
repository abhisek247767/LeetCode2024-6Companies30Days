/*
 * Problem Statement: Valid Parentheses (LeetCode #20)
 * 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 * 
 * Example 1:
 * Input: s = "()"
 * Output: true
 * 
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 * 
 * Example 3:
 * Input: s = "(]"
 * Output: false
 * 
 * Example 4:
 * Input: s = "([])"
 * Output: true
 * 
 * Time Complexity: O(n) - We process each character once
 * Space Complexity: O(n) - Stack can contain up to n/2 opening brackets in worst case
 * 
 * Approach:
 * - Use a Stack data structure to track opening brackets
 * - When we see an opening bracket, push it onto stack
 * - When we see a closing bracket, check if it matches the top of stack
 * - If matches, pop from stack; if doesn't match or stack is empty, return false
 * - At the end, stack should be empty for valid parentheses
 */

import java.util.Stack;
import java.util.HashMap;

public class ValidParentheses {
    
    /**
     * Checks if a string has valid parentheses structure
     * 
     * @param s Input string containing brackets
     * @return true if brackets are valid, false otherwise
     */
    public static boolean isValid(String s) {
        // Edge case: empty string is valid
        if (s == null || s.length() == 0) {
            return true;
        }
        
        // Edge case: odd length strings can't be valid
        if (s.length() % 2 != 0) {
            return false;
        }
        
        // Stack to keep track of opening brackets
        Stack<Character> stack = new Stack<>();
        
        // HashMap for matching pairs (closing -> opening)
        HashMap<Character, Character> matchingBrackets = new HashMap<>();
        matchingBrackets.put(')', '(');
        matchingBrackets.put('}', '{');
        matchingBrackets.put(']', '[');
        
        // Process each character
        for (char c : s.toCharArray()) {
            // If it's a closing bracket
            if (matchingBrackets.containsKey(c)) {
                // Check if stack is empty or top doesn't match
                if (stack.isEmpty() || stack.peek() != matchingBrackets.get(c)) {
                    return false;
                }
                // Pop the matching opening bracket
                stack.pop();
            } 
            // If it's an opening bracket
            else {
                stack.push(c);
            }
        }
        
        // Valid only if all brackets were matched (stack is empty)
        return stack.isEmpty();
    }
    
    /**
     * Alternative implementation without HashMap (slightly more verbose)
     */
    public static boolean isValidAlternative(String s) {
        if (s == null || s.length() == 0) return true;
        if (s.length() % 2 != 0) return false;
        
        Stack<Character> stack = new Stack<>();
        
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) return false;
                
                char top = stack.pop();
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        
        return stack.isEmpty();
    }
    
    /**
     * Helper method to test and print results
     */
    public static void testCase(String input, boolean expected) {
        boolean result = isValid(input);
        String status = (result == expected) ? "✓ PASS" : "✗ FAIL";
        
        System.out.println("Input: \"" + input + "\"");
        System.out.println("Output: " + result);
        System.out.println("Expected: " + expected);
        System.out.println("Status: " + status);
        
        // Explain the result
        if (result) {
            System.out.println("Explanation: All brackets are properly matched and closed.");
        } else {
            System.out.println("Explanation: Brackets are not properly matched or closed.");
        }
        System.out.println();
    }
    
    /**
     * Main method with comprehensive test cases
     */
    public static void main(String[] args) {
        System.out.println("=== LeetCode Problem #20: Valid Parentheses ===\n");
        
        // Test Case 1: Simple valid case
        System.out.println("Test Case 1: Single pair");
        testCase("()", true);
        
        // Test Case 2: Multiple types valid
        System.out.println("Test Case 2: Multiple types of brackets");
        testCase("()[]{}", true);
        
        // Test Case 3: Invalid - mismatched types
        System.out.println("Test Case 3: Mismatched brackets");
        testCase("(]", false);
        
        // Test Case 4: Nested valid
        System.out.println("Test Case 4: Nested brackets");
        testCase("([{}])", true);
        
        // Test Case 5: Invalid - wrong order
        System.out.println("Test Case 5: Wrong closing order");
        testCase("([)]", false);
        
        // Test Case 6: Complex valid
        System.out.println("Test Case 6: Complex valid structure");
        testCase("{[()()]}", true);
        
        // Test Case 7: Empty string
        System.out.println("Test Case 7: Empty string");
        testCase("", true);
        
        // Test Case 8: Only opening brackets
        System.out.println("Test Case 8: Only opening brackets");
        testCase("((((", false);
        
        // Test Case 9: Only closing brackets
        System.out.println("Test Case 9: Only closing brackets");
        testCase("))))", false);
        
        // Test Case 10: Single bracket
        System.out.println("Test Case 10: Single bracket (odd length)");
        testCase("(", false);
        
        // Algorithm Analysis
        System.out.println("=== Algorithm Analysis ===");
        System.out.println("Time Complexity: O(n) - Process each character once");
        System.out.println("Space Complexity: O(n) - Stack can hold up to n/2 brackets");
        System.out.println("\nKey Concepts:");
        System.out.println("1. Stack (LIFO) - Perfect for matching pairs");
        System.out.println("2. HashMap - Quick lookup for bracket pairs");
        System.out.println("3. Early termination - Return false immediately on mismatch");
        System.out.println("\nCommon Edge Cases:");
        System.out.println("- Empty string (valid)");
        System.out.println("- Odd length string (invalid)");
        System.out.println("- Only opening or closing brackets");
        System.out.println("- Nested vs. interleaved brackets");
    }
}

/*
 * Output:
 * === LeetCode Problem #20: Valid Parentheses ===
 * 
 * Test Case 1: Single pair
 * Input: "()"
 * Output: true
 * Expected: true
 * Status: ✓ PASS
 * Explanation: All brackets are properly matched and closed.
 * 
 * Test Case 2: Multiple types of brackets
 * Input: "()[]{}"
 * Output: true
 * Expected: true
 * Status: ✓ PASS
 * Explanation: All brackets are properly matched and closed.
 * 
 * Test Case 3: Mismatched brackets
 * Input: "(]"
 * Output: false
 * Expected: false
 * Status: ✓ PASS
 * Explanation: Brackets are not properly matched or closed.
 * 
 * Test Case 4: Nested brackets
 * Input: "([{}])"
 * Output: true
 * Expected: true
 * Status: ✓ PASS
 * Explanation: All brackets are properly matched and closed.
 * 
 * Test Case 5: Wrong closing order
 * Input: "([)]"
 * Output: false
 * Expected: false
 * Status: ✓ PASS
 * Explanation: Brackets are not properly matched or closed.
 * 
 * Test Case 6: Complex valid structure
 * Input: "{[()()]}"
 * Output: true
 * Expected: true
 * Status: ✓ PASS
 * Explanation: All brackets are properly matched and closed.
 * 
 * Test Case 7: Empty string
 * Input: ""
 * Output: true
 * Expected: true
 * Status: ✓ PASS
 * Explanation: All brackets are properly matched and closed.
 * 
 * Test Case 8: Only opening brackets
 * Input: "(((("
 * Output: false
 * Expected: false
 * Status: ✓ PASS
 * Explanation: Brackets are not properly matched or closed.
 * 
 * Test Case 9: Only closing brackets
 * Input: "))))"
 * Output: false
 * Expected: false
 * Status: ✓ PASS
 * Explanation: Brackets are not properly matched or closed.
 * 
 * Test Case 10: Single bracket (odd length)
 * Input: "("
 * Output: false
 * Expected: false
 * Status: ✓ PASS
 * Explanation: Brackets are not properly matched or closed.
 * 
 * === Algorithm Analysis ===
 * Time Complexity: O(n) - Process each character once
 * Space Complexity: O(n) - Stack can hold up to n/2 brackets
 * 
 * Key Concepts:
 * 1. Stack (LIFO) - Perfect for matching pairs
 * 2. HashMap - Quick lookup for bracket pairs
 * 3. Early termination - Return false immediately on mismatch
 * 
 * Common Edge Cases:
 * - Empty string (valid)
 * - Odd length string (invalid)
 * - Only opening or closing brackets
 * - Nested vs. interleaved brackets
 */
