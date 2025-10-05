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
