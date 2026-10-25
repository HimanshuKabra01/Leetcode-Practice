// Last updated: 10/26/2026, 12:49:28 AM
1class Solution {
2public:
3    int closedIsland(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        queue<pair<int, int>> q;
8
9        for (int j = 0; j < n; j++) {
10            if (grid[0][j] == 0) {
11                q.push({0, j});
12                grid[0][j] = 2;
13            }
14
15            if (grid[m - 1][j] == 0) {
16                q.push({m - 1, j});
17                grid[m - 1][j] = 2;
18            }
19        }
20
21        for (int i = 0; i < m; i++) {
22            if (grid[i][0] == 0) {
23                q.push({i, 0});
24                grid[i][0] = 2;
25            }
26
27            if (grid[i][n - 1] == 0) {
28                q.push({i, n - 1});
29                grid[i][n - 1] = 2;
30            }
31        }
32
33        while (!q.empty()) {
34            int i = q.front().first;
35            int j = q.front().second;
36            q.pop();
37
38            if (i - 1 >= 0 && grid[i - 1][j] == 0) {
39                grid[i - 1][j] = 2;
40                q.push({i - 1, j});
41            }
42
43            if (j + 1 < n && grid[i][j + 1] == 0) {
44                grid[i][j + 1] = 2;
45                q.push({i, j + 1});
46            }
47
48            if (i + 1 < m && grid[i + 1][j] == 0) {
49                grid[i + 1][j] = 2;
50                q.push({i + 1, j});
51            }
52
53            if (j - 1 >= 0 && grid[i][j - 1] == 0) {
54                grid[i][j - 1] = 2;
55                q.push({i, j - 1});
56            }
57        }
58
59        int ans = 0;
60
61        for (int i = 0; i < m; i++) {
62            for (int j = 0; j < n; j++) {
63                if (grid[i][j] == 0) {
64                    ans++;
65                    grid[i][j] = 2;
66                    q.push({i, j});
67
68                    while (!q.empty()) {
69                        int x = q.front().first;
70                        int y = q.front().second;
71                        q.pop();
72
73                        if (x - 1 >= 0 && grid[x - 1][y] == 0) {
74                            grid[x - 1][y] = 2;
75                            q.push({x - 1, y});
76                        }
77
78                        if (y + 1 < n && grid[x][y + 1] == 0) {
79                            grid[x][y + 1] = 2;
80                            q.push({x, y + 1});
81                        }
82
83                        if (x + 1 < m && grid[x + 1][y] == 0) {
84                            grid[x + 1][y] = 2;
85                            q.push({x + 1, y});
86                        }
87
88                        if (y - 1 >= 0 && grid[x][y - 1] == 0) {
89                            grid[x][y - 1] = 2;
90                            q.push({x, y - 1});
91                        }
92                    }
93                }
94            }
95        }
96
97        return ans;
98    }
99};
100