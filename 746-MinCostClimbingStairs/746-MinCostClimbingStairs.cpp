// Last updated: 4/21/2026, 1:01:16 PM
1    class Solution {
2    public:
3        int rec(vector<int> &cost, vector<int> &dp, int i) {
4            if(i >= cost.size()) return 0;
5            if(dp[i] != -1) return dp[i];
6
7            dp[i] = cost[i] + min(rec(cost, dp, i+1), rec(cost, dp, i+2));
8
9            return dp[i];
10        }
11        int minCostClimbingStairs(vector<int>& cost) {
12            vector<int> dp(cost.size(), -1);
13            
14            int one = rec(cost, dp, 0);
15            int two = rec(cost, dp, 1);
16
17            return min(one, two);
18        }
19    };