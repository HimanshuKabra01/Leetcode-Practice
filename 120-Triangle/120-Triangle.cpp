// Last updated: 9/2/2026, 11:45:33 PM
1class Solution {
2public:
3    int rec(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
4        if(j < 0 || i < 0 || j > i) {
5            return 1e9;
6        }
7
8        if(i == 0) {
9            return triangle[0][0];
10        }
11
12        if(dp[i][j] != -1) {
13            return dp[i][j];
14        }
15
16        return dp[i][j] = triangle[i][j] + min(rec(i-1, j, triangle, dp), rec(i-1, j-1, triangle, dp));
17    }
18    int minimumTotal(vector<vector<int>>& triangle) {
19        int ans = INT_MAX;
20        int n = triangle.size();
21
22        vector<vector<int>> dp(n, vector<int>(n,  -1));
23
24        for(int i = 0; i < triangle[n-1].size(); i++) {
25            ans = min(ans, rec(n-1, i, triangle, dp));
26        }
27
28        return ans;
29    }
30};