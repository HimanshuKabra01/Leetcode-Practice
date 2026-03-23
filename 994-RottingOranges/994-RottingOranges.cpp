// Last updated: 3/23/2026, 12:40:59 PM
1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int ans = 0;
5        int m = grid.size();
6        int n = grid[0].size();
7
8        queue<pair<int, int>> q;
9        int fresh = 0;
10        
11        for(int i = 0; i < m; i++) {
12            for(int j = 0; j < n; j++) {
13                if(grid[i][j] == 2) {
14                    q.push({i, j});
15                }
16
17                if(grid[i][j] == 1) {
18                    fresh++;
19                }
20            }
21        }
22
23        if(fresh == 0) {
24            return 0;
25        }
26
27        while(!q.empty()) {
28            int k = q.size();
29
30            bool done = false;
31            for(int l = 0; l < k; l++) {
32                int i = q.front().first;
33                int j = q.front().second;
34
35                q.pop();
36
37                if(i-1 >= 0 && grid[i-1][j] == 1) {
38                    grid[i-1][j] = 2;
39                    q.push({i-1, j});
40                    fresh--;
41                    done = true;
42                }
43
44                if(j+1 < n && grid[i][j+1] == 1) {
45                    grid[i][j+1] = 2;
46                    q.push({i, j+1});
47                    fresh--;
48                    done = true;
49                }
50
51                if(i+1 < m && grid[i+1][j] == 1) {
52                    grid[i+1][j] = 2;
53                    q.push({i+1, j});
54                    fresh--;
55                    done = true;
56                }
57
58                if(j-1 >= 0 && grid[i][j-1] == 1) {
59                    grid[i][j-1] = 2;
60                    q.push({i, j-1});
61                    fresh--;
62                    done = true;
63                }
64            }
65
66            if(done) {
67                ans++;
68            }
69        }
70
71       if(fresh > 0) {
72        return -1;
73       } else {
74        return ans;
75       }
76    }
77};