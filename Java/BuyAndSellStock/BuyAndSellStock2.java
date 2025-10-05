// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold than one share of the stock.

// Find and return the maximum profit you can achieve.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

package Java.BuyAndSellStock;

import java.util.Arrays;

class BuyAndSellStock2 {
    public static void main(String[] args) {
        BuyAndSellStock2 bss = new BuyAndSellStock2();
        int[] a = {7,1,5,3,6,4};
        System.out.println(bss.maxProfit(a));
    }

    private int f(int i, int buy, int[] a, int[][] dp) {
        if(i == a.length){
            return 0;
        }
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy == 1) {
            profit = Math.max(f(i+1,0,a,dp)+a[i], f(i+1,1,a,dp));
        }
        else{
            profit = Math.max(f(i+1,1,a,dp)-a[i], f(i+1,0,a,dp));
        }
        return dp[i][buy] = profit;
    }
    public int maxProfit(int[] a) {
        int n = a.length;
        int[][] dp = new int[n][3];

        for(int[] r:dp){
            Arrays.fill(r,-1);
        }

        return f(0,0,a,dp);
    }
}