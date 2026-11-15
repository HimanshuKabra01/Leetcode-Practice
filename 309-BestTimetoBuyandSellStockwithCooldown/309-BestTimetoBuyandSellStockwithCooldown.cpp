// Last updated: 11/16/2026, 1:47:29 AM
1class Solution {
2public:
3    int rec(vector<int> &prices, int i, int j, vector<vector<int>> &dp) {
4        if(i >= prices.size()) {
5            return 0;
6        }
7
8        if(dp[i][j] != -1) {
9            return dp[i][j];
10        }
11
12        int ans = 0;
13        if(j == 1) {
14            int buy = -prices[i] + rec(prices, i+1, 0, dp);
15            int skip = rec(prices, i+1, 1, dp);
16            ans = max(buy, skip);
17        } else {
18            int sell = prices[i] + rec(prices, i+2, 1, dp);
19            int hold = rec(prices, i+1, 0, dp);
20            ans = max(sell, hold);
21        }
22
23        return dp[i][j] = ans;
24    }
25    int maxProfit(vector<int>& prices) {
26        int n = prices.size();
27
28        vector<vector<int>> dp(n, vector<int>(2, -1));
29
30        return rec(prices, 0, 1, dp);
31    }
32};