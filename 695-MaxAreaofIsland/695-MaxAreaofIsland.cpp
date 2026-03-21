// Last updated: 3/21/2026, 4:49:32 PM
1class Solution {
2public:
3    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid, int m, int n, int &curr) {
4        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] != 1) {
5            return;
6        }
7
8        vis[i][j] = true; 
9        curr++;
10
11        dfs(i-1, j, vis, grid, m, n, curr);
12        dfs(i, j+1, vis, grid, m, n, curr);
13        dfs(i+1, j, vis, grid, m, n, curr);
14        dfs(i, j-1, vis, grid, m, n, curr);
15    }
16    int maxAreaOfIsland(vector<vector<int>>& grid) {
17        int ans = 0;
18        int m = grid.size();
19        int n = grid[0].size();
20
21        vector<vector<bool>> vis(m, vector<bool>(n, false));
22
23        for(int i = 0; i < m; i++) {
24            for(int j = 0; j < n; j++) {
25                int curr = 0;
26                if(grid[i][j] == 1 && !vis[i][j]) {
27                    dfs(i, j, vis, grid, m, n, curr); 
28                }
29
30                ans = max(ans, curr);
31            }
32        }
33
34        return ans;
35    }
36};