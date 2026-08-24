// Last updated: 8/24/2026, 7:00:43 PM
1class Solution {
2public:
3    int rec(int i, int j, vector<vector<int>> &dp) {
4        if(i == 0 && j == 0) {
5            return dp[i][j] = 1;
6        }
7
8        if(i < 0 || j < 0) {
9            return 0;
10        }
11
12        if(dp[i][j] != -1) {
13            return dp[i][j];
14        }
15
16        int up = rec(i-1, j, dp);
17        int left = rec(i, j-1, dp);
18
19        return dp[i][j] = up+left;
20    } 
21    int uniquePaths(int m, int n) {
22        vector<vector<int>> dp(m, vector<int> (n, -1));
23
24        return rec(m-1, n-1, dp);
25    }
26};