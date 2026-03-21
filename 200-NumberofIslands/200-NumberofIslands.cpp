// Last updated: 3/21/2026, 4:51:40 PM
1class Solution {
2public:
3    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int n, int m) {
4        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1') {
5            return;
6        }
7
8        vis[i][j] = true;
9
10        dfs(i-1, j, vis, grid, n, m);
11        dfs(i, j+1, vis, grid, n, m);
12        dfs(i+1, j, vis, grid, n, m);
13        dfs(i, j-1, vis, grid, n, m);
14    }
15
16    int numIslands(vector<vector<char>>& grid) {
17        int ans = 0;
18        int n = grid.size();
19        int m = grid[0].size();
20
21        vector<vector<bool>> vis(n, vector<bool>(m, false));
22
23        for(int i = 0; i < n; i++) {
24            for(int j = 0; j < m; j++) {
25                if(grid[i][j] == '1' && !vis[i][j]) {
26                    dfs(i, j, vis, grid, n, m);
27                    ans++;
28                }
29            }
30        }
31
32        return ans;
33    }
34};