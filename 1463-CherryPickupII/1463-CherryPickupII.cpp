// Last updated: 9/19/2026, 1:53:26 AM
1class Solution {
2public:
3    int rec(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
4        int c = grid[0].size();
5        
6        if(i < 0 || j1 < 0 || j2 < 0 || j1 >=c || j2 >= c) {
7            return -1e9;
8        }
9
10        if(i == grid.size()-1) {
11            if(j1 != j2) {
12                return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
13            } else {
14                return dp[i][j1][j2] = grid[i][j1];
15            }
16        }
17
18        if(dp[i][j1][j2] != -1) {
19            return dp[i][j1][j2];
20        }
21
22        int val = max(rec(i+1, j1-1, j2-1, grid, dp), max(rec(i+1, j1-1, j2, grid, dp), max(rec(i+1, j1-1, j2+1, grid, dp), max(rec(i+1, j1, j2-1, grid, dp), max(rec(i+1, j1, j2, grid, dp), max(rec(i+1, j1, j2+1, grid, dp), max(rec(i+1, j1+1, j2-1, grid, dp), max(rec(i+1, j1+1, j2, grid, dp), rec(i+1, j1+1, j2+1, grid, dp)))))))));
23
24        if(j1 != j2) {
25            return dp[i][j1][j2] = val+grid[i][j1]+grid[i][j2];
26        } else {
27            return dp[i][j1][j2] = val+grid[i][j1];
28        }
29    }
30    int cherryPickup(vector<vector<int>>& grid) {
31        int r = grid.size();
32        int c = grid[0].size();
33
34        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
35
36        return rec(0, 0, c-1, grid, dp);
37    }
38};