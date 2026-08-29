// Last updated: 8/29/2026, 2:57:15 PM
1class Solution {
2public:
3    int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
4        if(i < 0 || j < 0) {
5            return 1e9;
6        }
7
8        if(i == 0 && j == 0) {
9            return grid[0][0];
10        }
11
12        if(dp[i][j] != -1) {
13            return dp[i][j];
14        }
15    
16        int up = rec(i-1, j, grid, dp);
17        int left = rec(i, j-1, grid, dp);
18
19        return dp[i][j] = min(grid[i][j]+up, grid[i][j]+left);
20    }
21    int minPathSum(vector<vector<int>>& grid) {
22        int m = grid.size();
23        int n = grid[0].size();
24
25        vector<vector<int>> dp(m, vector<int>(n, -1));
26
27        return rec(m-1, n-1, grid, dp);
28    }
29};