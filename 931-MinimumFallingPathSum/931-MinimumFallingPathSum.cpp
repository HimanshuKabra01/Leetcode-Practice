// Last updated: 9/4/2026, 1:38:06 AM
1class Solution {
2public:
3    int rec(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
4        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix.size()) {
5            return 1e9;
6        }
7
8        if(i == 0) {
9            return matrix[0][j];
10        }
11
12        if(dp[i][j] != INT_MAX) {
13            return dp[i][j];
14        }
15
16        return dp[i][j] = matrix[i][j] + min(rec(i-1, j+1, matrix, dp), min(rec(i-1, j-1, matrix, dp), rec(i-1, j, matrix, dp)));
17    }
18    int minFallingPathSum(vector<vector<int>>& matrix) {
19        int n = matrix.size();
20
21        vector<vector<int>> dp(n+1, vector<int> (n+1, INT_MAX));
22
23        int ans = INT_MAX;
24
25        for(int i = 0; i < n; i++) {
26            ans = min(ans, rec(n-1, i, matrix, dp));
27        }
28
29        return ans;
30    }
31};