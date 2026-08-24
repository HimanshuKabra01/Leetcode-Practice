// Last updated: 8/25/2026, 1:23:42 AM
1class Solution {
2public:
3    int rec(int amt, int i, vector<int> &arr, vector<vector<int>> &dp) {
4        if(amt == 0) {
5            return 1;
6        } 
7
8        if(amt < 0 || i < 0) {
9            return 0;
10        }
11
12        if(dp[amt][i] != -1) {
13            return dp[amt][i];
14        }
15
16        int ways = rec(amt-arr[i], i, arr, dp);
17        int two = rec(amt, i-1, arr, dp);
18
19        return dp[amt][i] = ways+two;
20    }
21    int change(int amount, vector<int>& coins) {
22        int n = coins.size();
23
24        vector<vector<int>> dp(amount+1, vector<int>(n, -1));
25        return rec(amount, n-1, coins, dp);
26    }
27};