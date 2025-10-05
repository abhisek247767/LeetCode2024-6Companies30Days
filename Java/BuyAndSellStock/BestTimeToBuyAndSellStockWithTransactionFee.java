// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note:
// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.

// Example 1:
// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

// Example 2:
// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6

package Java.BuyAndSellStock;

import java.util.Arrays;

public class BestTimeToBuyAndSellStockWithTransactionFee {
    public static void main(String[] args) {
        BestTimeToBuyAndSellStockWithTransactionFee bss = new BestTimeToBuyAndSellStockWithTransactionFee();
        int[] a = {1,3,2,8,4,9};
        int fee = 2;
        System.out.println(bss.maxProfit(a,fee));
    }
    private int f(int i, int buy, int fee, int[] a, int[][] dp) {
        if(i>=a.length){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy == 1) {
            profit = Math.max(f(i+1,0,fee,a,dp)-a[i] , f(i+1,1,fee,a,dp));
        }
        else {
            profit = Math.max(f(i+1,1,fee,a,dp)+a[i]-fee , f(i+1,0,fee,a,dp));
        }
        return dp[i][buy] = profit;
    }
    public int maxProfit(int[] a, int fee) {
        int n = a.length;
        int[][] dp = new int[n+1][3];
        for(int[] r : dp){
            Arrays.fill(r,-1);
        }
        return f(0,1,fee,a,dp);
    }
}
