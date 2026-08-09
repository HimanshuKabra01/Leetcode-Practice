// Last updated: 8/9/2026, 12:34:04 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<vector<int>> q;
        if(grid[0][0] != 0) {
            return -1;
        }
        q.push({0, 0, 0});
        grid[0][0] = 1;
        int ans = INT_MAX;
        while(!q.empty()) {
            vector<int> vec = q.front();
            int i = vec[0];
            int j = vec[1];
            int dis = vec[2];

            q.pop();
            if(i == n-1 && j == n-1) {
                ans = min(ans, dis);
                continue;
            }

            if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 0) {
                q.push({i-1, j-1, dis+1});
                grid[i-1][j-1] = 1;
            }

            if(i-1 >= 0 && grid[i-1][j] == 0) {
                q.push({i-1, j, dis+1});
                grid[i-1][j] = 1;
            }

            if(i-1 >= 0 && j+1 < n && grid[i-1][j+1] == 0) {
                q.push({i-1, j+1, dis+1});
                grid[i-1][j+1] = 1;
            }

            if(j+1 < n && grid[i][j+1] == 0) {
                q.push({i, j+1, dis+1});
                grid[i][j+1] = 1;
            }

            if(i+1 < n && j+1 < n && grid[i+1][j+1] == 0) {
                q.push({i+1, j+1, dis+1});
                grid[i+1][j+1] = 1;
            }

            if(i+1 < n && grid[i+1][j] == 0) {
                q.push({i+1, j, dis+1});
                grid[i+1][j] = 1;
            }

            if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 0) {
                q.push({i+1, j-1, dis+1});
                grid[i+1][j-1] = 1;
            }

            if(j-1 >= 0 && grid[i][j-1] == 0) {
                q.push({i, j-1, dis+1});
                grid[i][j-1] = 1;
            }
        }

        if(ans == INT_MAX) {
            return -1;
        }
        return ans+1;
    }
};