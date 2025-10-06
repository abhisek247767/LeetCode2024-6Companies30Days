package Java.HouseRobber;

/**
 * LeetCode 213: House Robber II
 * 
 * Problem:
 * Houses are arranged in a circle. The first house is the neighbor of the last one.
 * Adjacent houses have security systems connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * 
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Algorithm Description:
 * ----------------------
 * - Since the houses are in a circle, robbing both the first and last house is not allowed.
 * - To solve this, consider two scenarios:
 *   1. Exclude the first house and solve the problem for houses 1 to n-1.
 *   2. Exclude the last house and solve the problem for houses 0 to n-2.
 * - For each scenario, use recursion with memoization (top-down DP):
 *   - At each house, decide to rob it (and skip the previous) or skip it.
 *   - Store results in dp[] to avoid recomputation.
 * - Return the maximum result from both scenarios.
 * 
 * Complexity Analysis:
 * --------------------
 * Let n be the number of houses.
 * - Time Complexity: O(n), since for each house we compute the result once and memoize it.
 * - Space Complexity: O(n) for the memoization table.
 */
import java.util.Arrays;

public class houseRobber2 {
    /**
     * Helper function to compute max money up to house i.
     * @param i  Current house index (working backwards)
     * @param a  Array of money in each house
     * @param dp Memoization table
     * @return   Maximum money that can be robbed up to house i
     */
    private int f(int i, int[] a, int[] dp) {
        // Out of bounds
        if(i < 0) return 0;
        // Base case: first house
        if(i == 0) return a[i];
        // Already computed
        if(dp[i] != -1) return dp[i];

        // Option 1: Rob current house, skip previous
        // Option 2: Skip current house
        return dp[i] = Math.max(a[i] + f(i-2, a, dp), f(i-1, a, dp));
    }

    /**
     * Main function to calculate max money that can be robbed in a circular arrangement.
     * @param a Array of money in each house
     * @return  Maximum money that can be robbed
     */
    public int rob(int[] a) {
        int n = a.length;
        if(n == 1) return a[0];
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);

        // Scenario 1: Exclude first house
        int[] arr1 = Arrays.copyOfRange(a, 1, n);
        // Scenario 2: Exclude last house
        int[] arr2 = Arrays.copyOfRange(a, 0, n-1);

        int first = f(n-2, arr1, dp);
        Arrays.fill(dp, -1);
        int last = f(n-2, arr2, dp);
        return Math.max(first, last);
    }
}

