// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// Example 1:
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

package Java.BuyAndSellStock;

import java.util.Arrays;

public class BuyAndSellStock3 {
    public static void main(String[] args) {
        BuyAndSellStock3 bss = new BuyAndSellStock3();
        int[] a = {3,3,5,0,0,3,1,4};
        System.out.println(bss.maxProfit(a));
    }
    private int f(int i, int buy, int t, int[] a, int[][][] dp) {
        if(i >= a.length || t >= 2){
            return 0;
        }
        if(dp[i][buy][t] != -1){
            return dp[i][buy][t];
        }

        int profit = 0;
        if(buy == 1) {
            profit = Math.max(f(i+1,0,t,a,dp)-a[i], f(i+1,1,t,a,dp));
        }
        else{
            profit = Math.max(f(i+1,1,t+1,a,dp)+a[i], f(i+1,0,t,a,dp));
        }
        return dp[i][buy][t] = profit;
    }
    public int maxProfit(int[] a) {
        int n = a.length;
        int[][][] dp = new int[n][3][3];

        for(int[][] r:dp){
            for(int[] rr:r){
                Arrays.fill(rr,-1);
            }
        }

        return f(0,1,0,a,dp);
    }
}
