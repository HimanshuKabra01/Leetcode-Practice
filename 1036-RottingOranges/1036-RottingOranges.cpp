// Last updated: 8/9/2026, 12:34:31 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }

                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) {
            return 0;
        }

        while(!q.empty()) {
            int k = q.size();

            bool done = false;
            for(int l = 0; l < k; l++) {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                if(i-1 >= 0 && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                    fresh--;
                    done = true;
                }

                if(j+1 < n && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                    fresh--;
                    done = true;
                }

                if(i+1 < m && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                    fresh--;
                    done = true;
                }

                if(j-1 >= 0 && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    fresh--;
                    done = true;
                }
            }

            if(done) {
                ans++;
            }
        }

       if(fresh > 0) {
        return -1;
       } else {
        return ans;
       }
    }
};