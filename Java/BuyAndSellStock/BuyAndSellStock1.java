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
