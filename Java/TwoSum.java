/*
 * Problem Statement: Two Sum (LeetCode #1)
 * 
 * Given an array of integers nums and an integer target, return indices of the 
 * two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may 
 * not use the same element twice.
 * You can return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(n) - HashMap storage for complements
 * 
 * Approach:
 * - Use HashMap to store complement values and their indices
 * - For each element, check if its complement (target - current) exists in map
 * - If found, return the indices
 * - Otherwise, store current element and its index in map
 */

import java.util.HashMap;

public class TwoSum {
    
    /**
     * Finds two indices in the array that sum up to the target value
     * 
     * @param nums   Array of integers
     * @param target Target sum value
     * @return Array containing two indices whose values sum to target
     */
    public static int[] twoSum(int[] nums, int target) {
        // HashMap to store value -> index mapping
        HashMap<Integer, Integer> map = new HashMap<>();
        
        // Iterate through the array
        for (int i = 0; i < nums.length; i++) {
            // Calculate the complement (the value we need to find)
            int complement = target - nums[i];
            
            // Check if complement exists in the map
            if (map.containsKey(complement)) {
                // Found the pair! Return indices
                return new int[] { map.get(complement), i };
            }
            
            // Store current number and its index for future lookups
            map.put(nums[i], i);
        }
        
        // No solution found (though problem guarantees one exists)
        return new int[] { -1, -1 };
    }
    
    /**
     * Helper method to print array in readable format
     */
    public static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) System.out.print(", ");
        }
        System.out.println("]");
    }
    
    /**
     * Main method with test cases
     */
    public static void main(String[] args) {
        System.out.println("=== LeetCode Problem #1: Two Sum ===\n");
        
        // Test Case 1
        int[] nums1 = {2, 7, 11, 15};
        int target1 = 9;
        System.out.println("Test Case 1:");
        System.out.print("Input: nums = ");
        printArray(nums1);
        System.out.println("Target = " + target1);
        int[] result1 = twoSum(nums1, target1);
        System.out.print("Output: ");
        printArray(result1);
        System.out.println("Explanation: nums[" + result1[0] + "] + nums[" + result1[1] + 
                         "] = " + nums1[result1[0]] + " + " + nums1[result1[1]] + " = " + target1);
        System.out.println();
        
        // Test Case 2
        int[] nums2 = {3, 2, 4};
        int target2 = 6;
        System.out.println("Test Case 2:");
        System.out.print("Input: nums = ");
        printArray(nums2);
        System.out.println("Target = " + target2);
        int[] result2 = twoSum(nums2, target2);
        System.out.print("Output: ");
        printArray(result2);
        System.out.println("Explanation: nums[" + result2[0] + "] + nums[" + result2[1] + 
                         "] = " + nums2[result2[0]] + " + " + nums2[result2[1]] + " = " + target2);
        System.out.println();
        
        // Test Case 3
        int[] nums3 = {3, 3};
        int target3 = 6;
        System.out.println("Test Case 3:");
        System.out.print("Input: nums = ");
        printArray(nums3);
        System.out.println("Target = " + target3);
        int[] result3 = twoSum(nums3, target3);
        System.out.print("Output: ");
        printArray(result3);
        System.out.println("Explanation: nums[" + result3[0] + "] + nums[" + result3[1] + 
                         "] = " + nums3[result3[0]] + " + " + nums3[result3[1]] + " = " + target3);
        System.out.println();
        
        // Test Case 4 - Larger array
        int[] nums4 = {-1, -2, -3, -4, -5};
        int target4 = -8;
        System.out.println("Test Case 4 (Negative numbers):");
        System.out.print("Input: nums = ");
        printArray(nums4);
        System.out.println("Target = " + target4);
        int[] result4 = twoSum(nums4, target4);
        System.out.print("Output: ");
        printArray(result4);
        System.out.println("Explanation: nums[" + result4[0] + "] + nums[" + result4[1] + 
                         "] = " + nums4[result4[0]] + " + " + nums4[result4[1]] + " = " + target4);
        System.out.println();
        
        System.out.println("=== Algorithm Analysis ===");
        System.out.println("Time Complexity: O(n) - We traverse the array once");
        System.out.println("Space Complexity: O(n) - HashMap stores at most n elements");
        System.out.println("\nKey Insight: Using HashMap trades space for time efficiency.");
        System.out.println("Alternative O(n²) approach with two nested loops would use O(1) space.");
    }
}

/*
 * Output:
 * === LeetCode Problem #1: Two Sum ===
 * 
 * Test Case 1:
 * Input: nums = [2, 7, 11, 15]
 * Target = 9
 * Output: [0, 1]
 * Explanation: nums[0] + nums[1] = 2 + 7 = 9
 * 
 * Test Case 2:
 * Input: nums = [3, 2, 4]
 * Target = 6
 * Output: [1, 2]
 * Explanation: nums[1] + nums[2] = 2 + 4 = 6
 * 
 * Test Case 3:
 * Input: nums = [3, 3]
 * Target = 6
 * Output: [0, 1]
 * Explanation: nums[0] + nums[1] = 3 + 3 = 6
 * 
 * Test Case 4 (Negative numbers):
 * Input: nums = [-1, -2, -3, -4, -5]
 * Target = -8
 * Output: [2, 4]
 * Explanation: nums[2] + nums[4] = -3 + -5 = -8
 * 
 * === Algorithm Analysis ===
 * Time Complexity: O(n) - We traverse the array once
 * Space Complexity: O(n) - HashMap stores at most n elements
 * 
 * Key Insight: Using HashMap trades space for time efficiency.
 * Alternative O(n²) approach with two nested loops would use O(1) space.
 */
