// problem statement :- 
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

package Java.BuyAndSellStock;

class BuyAndSellStock1 {
    public static void main(String[] args) {
        BuyAndSellStock1 bss = new BuyAndSellStock1();
        int[] a = {7,1,5,3,6,4};
        System.out.println(bss.maxProfit(a));
    }
    public int maxProfit(int[] a) {
        int n = a.length, profit = Integer.MIN_VALUE, previousStock = a[0];
        for(int i = 1; i<n; i++) {
            int currProfit = a[i] - previousStock;
            profit = Math.max(profit, currProfit);
            previousStock = Math.min(previousStock, a[i]);
        }
        return profit > 0 ? profit : 0;
    }
}
