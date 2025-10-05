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
