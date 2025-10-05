// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// Example 1:
// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

// Example 2:
// Input: prices = [1]
// Output: 0

package Java.BuyAndSellStock;

import java.util.Arrays;

public class BestTimeToBuyAndSellStockWithCooldown {
    public static void main(String[] args) {
        BestTimeToBuyAndSellStockWithCooldown bss = new BestTimeToBuyAndSellStockWithCooldown();
        int[] a = {1,2,3,0,2};
        System.out.println(bss.maxProfit(a));
    }
    private int f(int i, int buy, int[] a, int[][] dp) {
        if(i >= a.length){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = 0;
        if(buy == 1){
            profit = Math.max(f(i+1,0,a,dp)-a[i], f(i+1,1,a,dp));
        }
        else{
            profit = Math.max(f(i+2, 1, a, dp) + a[i], f(i+1,0,a,dp));
        }
        return dp[i][buy] = profit;
    }
    public int maxProfit(int[] a) {
        int n = a.length;
        int[][] dp = new int[n+1][3];
        for(int[] r: dp) {
            Arrays.fill(r,-1);
        }
        return f(0,1,a,dp);
    }
}
