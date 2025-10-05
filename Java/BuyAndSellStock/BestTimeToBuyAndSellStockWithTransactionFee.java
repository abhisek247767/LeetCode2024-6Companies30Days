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
