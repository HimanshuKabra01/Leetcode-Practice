// Last updated: 8/26/2026, 1:36:13 AM
1class Solution {
2public:
3    int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
4        if(i < 0 || j < 0 || grid[i][j] == 1) {
5            return 0;
6        }
7
8        if(i == 0 && j == 0) {
9            return 1;
10        }
11
12        if(dp[i][j] != -1) {
13            return dp[i][j];
14        }
15
16        int up = rec(i-1, j, grid, dp);
17        int left = rec(i, j-1, grid, dp);
18
19        return dp[i][j] = up+left;
20    }
21    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
22        int m = grid.size();
23        int n = grid[0].size();
24
25        vector<vector<int>> dp(m, vector<int> (n, -1));
26
27        return rec(m-1, n-1, grid, dp);
28    }
29};