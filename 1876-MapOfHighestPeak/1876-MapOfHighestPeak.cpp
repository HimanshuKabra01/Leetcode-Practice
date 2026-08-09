// Last updated: 8/9/2026, 12:32:58 PM
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int> (n, 0));
        vector<vector<bool>> vis(m, vector<bool> (n, false));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            if(i - 1 >= 0 && !vis[i-1][j] && mat[i-1][j] == 0) {
                q.push({i-1, j});
                ans[i-1][j] = ans[i][j] + 1;
                vis[i-1][j] = true;
            }
            
            if(j + 1 < n && !vis[i][j+1] && mat[i][j+1] == 0) {
                q.push({i, j+1});
                ans[i][j+1] = ans[i][j] + 1;
                vis[i][j+1] = true;
            }
            
            if(i + 1 < m && !vis[i+1][j] && mat[i+1][j] == 0) {
                q.push({i+1, j});
                ans[i+1][j] = ans[i][j] + 1;
                vis[i+1][j] = true;
            }
            
            if(j - 1 >= 0 && !vis[i][j-1] && mat[i][j-1] == 0) {
                q.push({i, j-1});
                ans[i][j-1] = ans[i][j] + 1;
                vis[i][j-1] = true;
            }
        }

        return ans;
    }
};