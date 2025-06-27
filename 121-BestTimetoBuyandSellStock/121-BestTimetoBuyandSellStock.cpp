// Last updated: 6/27/2025, 4:31:18 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int bestBuy = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < n; i++) {
            if(prices[i] > bestBuy) {
             maxProfit = max(maxProfit, prices[i]-bestBuy);   
            }
            

            bestBuy = min(bestBuy, prices[i]);
        }

        return maxProfit;
    }
};