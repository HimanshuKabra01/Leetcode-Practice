// Last updated: 8/9/2026, 12:36:08 PM
    class Solution {
    public:
        int rec(vector<int> &cost, vector<int> &dp, int i) {
            if(i >= cost.size()) return 0;
            if(dp[i] != -1) return dp[i];

            dp[i] = cost[i] + min(rec(cost, dp, i+1), rec(cost, dp, i+2));

            return dp[i];
        }
        int minCostClimbingStairs(vector<int>& cost) {
            vector<int> dp(cost.size(), -1);
            
            int one = rec(cost, dp, 0);
            int two = rec(cost, dp, 1);

            return min(one, two);
        }
    };