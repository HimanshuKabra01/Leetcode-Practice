// Last updated: 8/9/2026, 12:33:01 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});
        ans[0][0] = 0;
        while(!q.empty()) {
            vector<int> vec = q.top();
            int dis = vec[0];
            int i = vec[1];
            int j = vec[2];

            q.pop();

            if(i == m-1 && j == n-1) {
                return dis;
            }

            if(i-1 >= 0 && max(dis,abs(grid[i-1][j]-grid[i][j])) < ans[i-1][j]) {
                q.push({max(dis, abs(grid[i-1][j]-grid[i][j])), i-1, j});
                ans[i-1][j] = max(dis,abs(grid[i-1][j]-grid[i][j]));
            }

            if(j+1 < n && max(dis,abs(grid[i][j+1]-grid[i][j])) < ans[i][j+1]) {
                q.push({max(dis,abs(grid[i][j+1]-grid[i][j])), i, j+1}); 
                ans[i][j+1] = max(dis,abs(grid[i][j+1]-grid[i][j]));
            }

            if(i+1 < m && max(dis,abs(grid[i+1][j]-grid[i][j])) < ans[i+1][j]) {
                q.push({max(dis,abs(grid[i+1][j]-grid[i][j])), i+1, j}); 
                ans[i+1][j] = max(dis,abs(grid[i+1][j]-grid[i][j]));
            }

            if(j-1 >= 0 && max(dis,abs(grid[i][j-1]-grid[i][j])) < ans[i][j-1]) {
                q.push({max(dis,abs(grid[i][j-1]-grid[i][j])), i, j-1});
                ans[i][j-1] = max(dis,abs(grid[i][j-1]-grid[i][j]));
            }
        }

        return -1;
    }
};