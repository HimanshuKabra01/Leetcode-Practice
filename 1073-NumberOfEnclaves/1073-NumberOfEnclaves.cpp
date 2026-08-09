// Last updated: 8/9/2026, 12:34:27 PM
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 1) {
                q.push({0, i});
                grid[0][i] = 2;
            }

            if(grid[m-1][i] == 1) {
                q.push({m-1, i});
                grid[m-1][i] = 2;
            }
        }

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 2;
            }

            if(grid[i][n-1] == 1) {
                q.push({i, n-1});
                grid[i][n-1] = 2;
            }
        }

        while(!q.empty()) {
            int k = q.size();

            for(int l = 0; l < k; l++) {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                if(i-1 >= 0 && grid[i-1][j] == 1) {
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                }

                if(j+1 < n && grid[i][j+1] == 1) {
                    q.push({i, j+1});
                    grid[i][j+1] = 2;
                }

                if(i+1 < m && grid[i+1][j] == 1) {
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                }

                if(j-1 >= 0 && grid[i][j-1] == 1) {
                    q.push({i, j-1});
                    grid[i][j-1] = 2;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};