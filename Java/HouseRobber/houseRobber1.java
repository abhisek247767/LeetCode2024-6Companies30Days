package Java.HouseRobber;

/**
 * LeetCode 198: House Robber
 * 
 * Problem:
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
 * The only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
 * it will automatically contact the police if two adjacent houses were broken into on the same night.
 * 
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Algorithm Description:
 * ----------------------
 * - Use recursion with memoization (top-down DP).
 * - At each house, decide to rob it (and skip the next) or skip it.
 * - Store results in dp[] to avoid recomputation.
 * - Return the maximum result starting from the first house.
 * 
 * Complexity Analysis:
 * --------------------
 * Let n be the number of houses.
 * - Time Complexity: O(n), since for each house we compute the result once and memoize it.
 * - Space Complexity: O(n) for the memoization table.
 */
import java.util.Arrays;

public class houseRobber1 {
    /**
     * Helper function to compute max money from house i onwards.
     * @param i  Current house index
     * @param a  Array of money in each house
     * @param dp Memoization table
     * @return   Maximum money that can be robbed from house i onwards
     */
    private int f(int i, int[] a, int[] dp) {
        // Base case: last house
        if(i == a.length - 1){
            return a[i];
        }
        // Out of bounds
        if(i >= a.length){
            return 0;
        }
        // Already computed
        if(dp[i] != -1) {
            return dp[i];
        }

        // Option 1: Rob current house, skip next
        int take = a[i] + f(i+2, a, dp);
        // Option 2: Skip current house
        int notTake = f(i+1, a, dp);
        // Store and return max
        return dp[i] = Math.max(take, notTake);
    }

    /**
     * Main function to calculate max money that can be robbed.
     * @param a Array of money in each house
     * @return  Maximum money that can be robbed
     */
    public int rob(int[] a) {
        int n = a.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1); // Initialize memoization table
        return f(0, a, dp);  // Start from first house
    }
}


