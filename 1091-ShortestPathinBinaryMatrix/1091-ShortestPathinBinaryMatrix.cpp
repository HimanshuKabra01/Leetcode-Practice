// Last updated: 6/19/2026, 1:32:06 AM
1class Solution {
2public:
3    int minimumEffortPath(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        
7        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
8        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
9        q.push({0, 0, 0});
10        ans[0][0] = 0;
11        while(!q.empty()) {
12            vector<int> vec = q.top();
13            int dis = vec[0];
14            int i = vec[1];
15            int j = vec[2];
16
17            q.pop();
18
19            if(i == m-1 && j == n-1) {
20                return dis;
21            }
22
23            if(i-1 >= 0 && max(dis,abs(grid[i-1][j]-grid[i][j])) < ans[i-1][j]) {
24                q.push({max(dis, abs(grid[i-1][j]-grid[i][j])), i-1, j});
25                ans[i-1][j] = max(dis,abs(grid[i-1][j]-grid[i][j]));
26            }
27
28            if(j+1 < n && max(dis,abs(grid[i][j+1]-grid[i][j])) < ans[i][j+1]) {
29                q.push({max(dis,abs(grid[i][j+1]-grid[i][j])), i, j+1}); 
30                ans[i][j+1] = max(dis,abs(grid[i][j+1]-grid[i][j]));
31            }
32
33            if(i+1 < m && max(dis,abs(grid[i+1][j]-grid[i][j])) < ans[i+1][j]) {
34                q.push({max(dis,abs(grid[i+1][j]-grid[i][j])), i+1, j}); 
35                ans[i+1][j] = max(dis,abs(grid[i+1][j]-grid[i][j]));
36            }
37
38            if(j-1 >= 0 && max(dis,abs(grid[i][j-1]-grid[i][j])) < ans[i][j-1]) {
39                q.push({max(dis,abs(grid[i][j-1]-grid[i][j])), i, j-1});
40                ans[i][j-1] = max(dis,abs(grid[i][j-1]-grid[i][j]));
41            }
42        }
43
44        return -1;
45    }
46};