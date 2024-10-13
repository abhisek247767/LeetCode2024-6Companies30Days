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