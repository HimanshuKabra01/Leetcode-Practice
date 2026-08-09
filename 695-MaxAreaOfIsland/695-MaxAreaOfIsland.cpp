// Last updated: 8/9/2026, 12:36:24 PM
class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid, int m, int n, int &curr) {
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] != 1) {
            return;
        }

        vis[i][j] = true; 
        curr++;

        dfs(i-1, j, vis, grid, m, n, curr);
        dfs(i, j+1, vis, grid, m, n, curr);
        dfs(i+1, j, vis, grid, m, n, curr);
        dfs(i, j-1, vis, grid, m, n, curr);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int curr = 0;
                if(grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, vis, grid, m, n, curr); 
                }

                ans = max(ans, curr);
            }
        }

        return ans;
    }
};