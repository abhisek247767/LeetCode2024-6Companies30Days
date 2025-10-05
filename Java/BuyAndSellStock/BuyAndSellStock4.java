// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:
// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

package Java.BuyAndSellStock;

import java.util.Arrays;

public class BuyAndSellStock4 {
    public static void main(String[] args) {
        BuyAndSellStock4 bss = new BuyAndSellStock4();
        int[] a = {2,4,1};
        int k = 2;
        System.out.println(bss.maxProfit(k, a));
    }
    private int f(int i, int buy, int t, int[] a, int[][][] dp) {
        if(i == a.length || t==0){
            return 0;
        }
        if(dp[i][buy][t] != -1){
            return dp[i][buy][t];
        }

        int profit = 0;
        if(buy == 1) {
            profit = Math.max(f(i+1,0,t,a,dp)-a[i], f(i+1,1,t,a,dp));
        }  
        else {
            profit = Math.max(f(i+1,1,t-1,a,dp)+a[i], f(i+1,0,t,a,dp));
        }
        return dp[i][buy][t] = profit;
    }
    public int maxProfit(int k, int[] a) {
        int n = a.length;
        int[][][] dp = new int[n+1][3][k+1];
        for(int[][] r:dp){
            for(int[] rr: r){
                Arrays.fill(rr,-1);
            }
        }

        return f(0,1,k,a,dp);
    }
}
