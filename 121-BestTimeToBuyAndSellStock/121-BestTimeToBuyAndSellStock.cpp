// Last updated: 6/7/2025, 5:39:33 PM
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
        if(maxProfit < 0) {
            return 0;
        } else {
            return maxProfit;
        }
    }
};