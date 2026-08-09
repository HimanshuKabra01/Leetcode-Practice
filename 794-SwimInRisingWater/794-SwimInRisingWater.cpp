// Last updated: 8/9/2026, 12:35:49 PM
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;

        while(!pq.empty()) {
            int curr = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if(i == n-1 && j == n-1) {
                return curr;
            }

            if(i-1 >= 0 && !vis[i-1][j]) {
                pq.push({max(curr, grid[i-1][j]), {i-1, j}});
                vis[i-1][j] = true;
            }

            if(j-1 >= 0 && !vis[i][j-1]) {
                pq.push({max(curr, grid[i][j-1]), {i, j-1}});
                vis[i][j-1] = true;
            }

            if(i+1 < n && !vis[i+1][j]) {
                pq.push({max(curr, grid[i+1][j]), {i+1, j}});
                vis[i+1][j] = true;
            }

            if(j+1 < n && !vis[i][j+1]) {
                pq.push({max(curr, grid[i][j+1]), {i, j+1}});
                vis[i][j+1] = true;
            }
        }

        return -1;
    }
};