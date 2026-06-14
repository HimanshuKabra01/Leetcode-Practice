// Last updated: 6/14/2026, 7:12:15 PM
1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        int m = mat.size();
5        int n = mat[0].size();
6
7        vector<vector<int>> ans(m, vector<int> (n, 0));
8        vector<vector<bool>> vis(m, vector<bool> (n, false));
9
10        queue<pair<int, int>> q;
11
12        for(int i = 0; i < m; i++) {
13            for(int j = 0; j < n; j++) {
14                if(mat[i][j] == 0) {
15                    q.push({i, j});
16                }
17            }
18        }
19
20        while(!q.empty()) {
21            int i = q.front().first;
22            int j = q.front().second;
23
24            q.pop();
25
26            if(i - 1 >= 0 && !vis[i-1][j] && mat[i-1][j] == 1) {
27                q.push({i-1, j});
28                ans[i-1][j] = ans[i][j] + 1;
29                vis[i-1][j] = true;
30            }
31            
32            if(j + 1 < n && !vis[i][j+1] && mat[i][j+1] == 1) {
33                q.push({i, j+1});
34                ans[i][j+1] = ans[i][j] + 1;
35                vis[i][j+1] = true;
36            }
37            
38            if(i + 1 < m && !vis[i+1][j] && mat[i+1][j] == 1) {
39                q.push({i+1, j});
40                ans[i+1][j] = ans[i][j] + 1;
41                vis[i+1][j] = true;
42            }
43            
44            if(j - 1 >= 0 && !vis[i][j-1] && mat[i][j-1] == 1) {
45                q.push({i, j-1});
46                ans[i][j-1] = ans[i][j] + 1;
47                vis[i][j-1] = true;
48            }
49        }
50
51        return ans;
52    }
53};