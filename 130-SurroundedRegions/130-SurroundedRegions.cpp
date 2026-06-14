// Last updated: 6/14/2026, 9:06:49 PM
1class Solution {
2public:
3    int numEnclaves(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        queue<pair<int, int>> q;
8
9        for(int i = 0; i < n; i++) {
10            if(grid[0][i] == 1) {
11                q.push({0, i});
12                grid[0][i] = 2;
13            }
14
15            if(grid[m-1][i] == 1) {
16                q.push({m-1, i});
17                grid[m-1][i] = 2;
18            }
19        }
20
21        for(int i = 0; i < m; i++) {
22            if(grid[i][0] == 1) {
23                q.push({i, 0});
24                grid[i][0] = 2;
25            }
26
27            if(grid[i][n-1] == 1) {
28                q.push({i, n-1});
29                grid[i][n-1] = 2;
30            }
31        }
32
33        while(!q.empty()) {
34            int k = q.size();
35
36            for(int l = 0; l < k; l++) {
37                int i = q.front().first;
38                int j = q.front().second;
39
40                q.pop();
41
42                if(i-1 >= 0 && grid[i-1][j] == 1) {
43                    q.push({i-1, j});
44                    grid[i-1][j] = 2;
45                }
46
47                if(j+1 < n && grid[i][j+1] == 1) {
48                    q.push({i, j+1});
49                    grid[i][j+1] = 2;
50                }
51
52                if(i+1 < m && grid[i+1][j] == 1) {
53                    q.push({i+1, j});
54                    grid[i+1][j] = 2;
55                }
56
57                if(j-1 >= 0 && grid[i][j-1] == 1) {
58                    q.push({i, j-1});
59                    grid[i][j-1] = 2;
60                }
61            }
62        }
63
64        int ans = 0;
65
66        for(int i = 0; i < m; i++) {
67            for(int j = 0; j < n; j++) {
68                if(grid[i][j] == 1) {
69                    ans++;
70                }
71            }
72        }
73
74        return ans;
75    }
76};