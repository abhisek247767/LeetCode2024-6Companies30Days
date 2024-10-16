// BEST TIME TO BUY AND SELL STOCK II

// Problem statement-

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output:7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.

// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

// Constraints:
// 1 <= prices.length <= 3 * 104
// 0 <= prices[i] <= 104


# include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// dynamic programming approach
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // Two vectors ahead and curr to store the results of the next day and the current day.
        // We need two states: [0] means not buying (sell), [1] means buying.
        vector<int> ahead(2,0),curr(2,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            // Try both states, whether we buy or we sell
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    // If we are in the buy state, we can either:
                    // 1. Buy today, which costs `prices[idx]` and the profit comes from not buying tomorrow (ahead[0])
                    // 2. Skip this day and the profit comes from 'ahead[1]' (no action on the next day)
                    profit=max(-prices[idx]+ahead[0],0+ahead[1]);
                }
                else
                {
                    // If we are in the sell state, we can either:
                    // 1. Sell today, which gives a profit of `prices[idx]` plus the result of buying tomorrow (ahead[1])
                    // 2. The profit comes from 'ahead[0]'
                    profit=max(prices[idx]+ahead[1],0+ahead[0]);
                }
                curr[buy]=profit;   
            }
            ahead=curr;
        }
        return ahead[1];
    }
    
};