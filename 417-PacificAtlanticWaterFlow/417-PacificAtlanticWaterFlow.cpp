// Last updated: 4/1/2026, 1:02:44 AM
1class Solution {
2public:
3    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
4        vector<vector<int>> ans;
5
6       int m = heights.size();
7       int n = heights[0].size();
8
9        vector<vector<bool>> vis_pac(m, vector<bool>(n, false));
10       vector<vector<bool>> vis_atl(m, vector<bool>(n, false));
11
12       queue<pair<int,int>> pac;
13
14       for(int j = 0; j < n; j++) {
15         pac.push({0, j});
16         vis_pac[0][j] = true;
17       }
18
19       for(int i = 0; i < m; i++) {
20         pac.push({i, 0});
21         vis_pac[i][0] = true;
22       }
23
24       queue<pair<int, int>> atl;
25
26       for(int j = 0; j < n; j++) {
27         atl.push({m-1, j});
28         vis_atl[m-1][j] = true;
29       }
30
31        for(int i = 0; i < m; i++) {
32            atl.push({i, n-1});
33            vis_atl[i][n-1] = true;
34       }
35
36       while(!pac.empty()) {
37            int i = pac.front().first;
38            int j = pac.front().second;
39
40            pac.pop();
41
42            if(i-1 >= 0 && heights[i-1][j] >= heights[i][j] && !vis_pac[i-1][j]) {
43                pac.push({i-1, j});
44                vis_pac[i-1][j] = true;
45            }
46
47            if(j+1 < n && heights[i][j+1] >= heights[i][j] && !vis_pac[i][j+1]) {
48                pac.push({i, j+1});
49                vis_pac[i][j+1] = true;
50            }
51
52            if(i+1 < m && heights[i+1][j] >= heights[i][j] && !vis_pac[i+1][j]) {
53                pac.push({i+1, j});
54                vis_pac[i+1][j] = true;
55            }
56
57            if(j-1 >= 0 && heights[i][j-1] >= heights[i][j] && !vis_pac[i][j-1]) {
58                pac.push({i, j-1});
59                vis_pac[i][j-1] = true;
60            }
61       }
62
63       while(!atl.empty()) {
64            int i = atl.front().first;
65            int j = atl.front().second;
66
67            atl.pop();
68
69            if(i-1 >= 0 && heights[i-1][j] >= heights[i][j] && !vis_atl[i-1][j]) {
70                atl.push({i-1, j});
71                vis_atl[i-1][j] = true;
72            }
73
74            if(j+1 < n && heights[i][j+1] >= heights[i][j] && !vis_atl[i][j+1]) {
75                atl.push({i, j+1});
76                vis_atl[i][j+1] = true;
77            }
78
79            if(i+1 < m && heights[i+1][j] >= heights[i][j] && !vis_atl[i+1][j]) {
80                atl.push({i+1, j});
81                vis_atl[i+1][j] = true;
82            }
83
84            if(j-1 >= 0 && heights[i][j-1] >= heights[i][j] && !vis_atl[i][j-1]) {
85                atl.push({i, j-1});
86                vis_atl[i][j-1] = true;
87            }
88       }
89
90       for(int i = 0; i < m; i++) {
91        for(int j = 0; j < n; j++) {
92            if(vis_pac[i][j] && vis_atl[i][j]) {
93                ans.push_back({i, j});
94            }
95        }
96       }
97
98       return ans;
99    }
100};