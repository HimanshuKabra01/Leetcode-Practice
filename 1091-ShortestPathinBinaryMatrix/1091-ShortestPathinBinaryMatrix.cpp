// Last updated: 6/18/2026, 12:06:04 PM
1class Solution {
2public:
3    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
4        int n = grid.size();
5
6        queue<vector<int>> q;
7        if(grid[0][0] != 0) {
8            return -1;
9        }
10        q.push({0, 0, 0});
11        grid[0][0] = 1;
12        int ans = INT_MAX;
13        while(!q.empty()) {
14            vector<int> vec = q.front();
15            int i = vec[0];
16            int j = vec[1];
17            int dis = vec[2];
18
19            q.pop();
20            if(i == n-1 && j == n-1) {
21                ans = min(ans, dis);
22                continue;
23            }
24
25            if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 0) {
26                q.push({i-1, j-1, dis+1});
27                grid[i-1][j-1] = 1;
28            }
29
30            if(i-1 >= 0 && grid[i-1][j] == 0) {
31                q.push({i-1, j, dis+1});
32                grid[i-1][j] = 1;
33            }
34
35            if(i-1 >= 0 && j+1 < n && grid[i-1][j+1] == 0) {
36                q.push({i-1, j+1, dis+1});
37                grid[i-1][j+1] = 1;
38            }
39
40            if(j+1 < n && grid[i][j+1] == 0) {
41                q.push({i, j+1, dis+1});
42                grid[i][j+1] = 1;
43            }
44
45            if(i+1 < n && j+1 < n && grid[i+1][j+1] == 0) {
46                q.push({i+1, j+1, dis+1});
47                grid[i+1][j+1] = 1;
48            }
49
50            if(i+1 < n && grid[i+1][j] == 0) {
51                q.push({i+1, j, dis+1});
52                grid[i+1][j] = 1;
53            }
54
55            if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 0) {
56                q.push({i+1, j-1, dis+1});
57                grid[i+1][j-1] = 1;
58            }
59
60            if(j-1 >= 0 && grid[i][j-1] == 0) {
61                q.push({i, j-1, dis+1});
62                grid[i][j-1] = 1;
63            }
64        }
65
66        if(ans == INT_MAX) {
67            return -1;
68        }
69        return ans+1;
70    }
71};