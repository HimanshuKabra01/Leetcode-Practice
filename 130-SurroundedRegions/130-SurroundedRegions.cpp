// Last updated: 3/28/2026, 2:53:36 PM
1class Solution {
2public:
3    void solve(vector<vector<char>>& board) {
4        int m = board.size();
5        int n = board[0].size();
6
7        if(n == 1) {
8            return;
9        }
10
11        queue<pair<int, int>> q;
12
13        for(int i = 0; i < n; i++){
14            if(board[0][i] == 'O') {
15                q.push({0, i});
16                board[0][i] = 'S';
17            }
18
19            if(board[m-1][i] == 'O') {
20                q.push({m-1, i});
21                board[m-1][i] = 'S';
22            }
23        }
24
25        for(int i = 0; i < m; i++){
26            if(board[i][0] == 'O') {
27                q.push({i, 0});
28                board[i][0] = 'S';
29            }
30
31            if(board[i][n-1] == 'O') {
32                q.push({i, n-1});
33                board[i][n-1] = 'S';
34            }
35        }
36
37        while(!q.empty()) {
38            int k = q.size();
39
40            for(int l = 0; l < k; l++) {
41                int i = q.front().first;
42                int j = q.front().second;
43
44                q.pop();
45
46                if(i-1 >= 0 && board[i-1][j] == 'O') {
47                    q.push({i-1, j});
48                    board[i-1][j] = 'S';
49                }
50
51                if(j+1 < n && board[i][j+1] == 'O') {
52                    q.push({i, j+1});
53                    board[i][j+1] = 'S';
54                }
55
56                if(i+1 < m && board[i+1][j] == 'O') {
57                    q.push({i+1, j});
58                    board[i+1][j] = 'S';
59                }
60
61                if(j-1 >= 0 && board[i][j-1] == 'O') {
62                    q.push({i, j-1});
63                    board[i][j-1] = 'S';
64                }
65            }
66        }
67
68        for(int i = 0; i < m; i++) {
69            for(int j = 0; j < n; j++) {
70                if(board[i][j] == 'O') {
71                    board[i][j] = 'X';
72                }
73
74                if(board[i][j] == 'S') {
75                    board[i][j] = 'O';
76                }
77            }
78        }
79    }
80};