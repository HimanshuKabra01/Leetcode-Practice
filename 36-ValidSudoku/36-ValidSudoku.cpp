// Last updated: 1/1/2026, 5:52:31 PM
1class Solution {
2public:
3    bool isValidSudoku(vector<vector<char>>& board) {
4        bool found = false;
5        //horizontal
6        for(int i = 0; i < 9; i++) {
7            unordered_set<char> s;
8            for(int j = 0; j < 9; j++) {
9                if(board[i][j] != '.') {
10                    if(s.find(board[i][j]) != s.end()) {
11                        return false;
12                    } else {
13                        s.insert(board[i][j]);
14                    }
15                }
16            } 
17        }
18
19        //vertical
20        for(int i = 0; i < 9; i++) {
21            unordered_set<char> s;
22            for(int j = 0; j < 9; j++) {
23                if(board[j][i] != '.') {
24                    if(s.find(board[j][i]) != s.end()) {
25                        return false;
26                    } else {
27                        s.insert(board[j][i]);
28                    }
29                }
30            } 
31        }
32
33        //grid
34        for(int i = 0; i < 9; i++) {
35            for(int j = 0; j < 9; j++) {
36                int srow = (i/3)*3;
37                int scol = (j/3)*3;
38                unordered_set<char> s;
39                for(int k = srow; k <= srow+2; k++) {
40                    for(int l = scol; l <= scol+2; l++) {
41                        if(board[k][l] != '.') {
42                            if(s.find(board[k][l]) != s.end()) {
43                                return false;
44                            } else {
45                                s.insert(board[k][l]);
46                            }
47                        }
48                    }
49                }
50            }
51        }
52
53        return true;
54    }
55};