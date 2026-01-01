// Last updated: 1/1/2026, 12:15:42 PM
1class Solution {
2public:
3
4    bool helper(vector<vector<char>>& board, string word, int row, int col, int idx) {
5        int m = board.size();
6        int n = board[0].size();
7
8        if(idx == word.size()) {
9            return true;
10        }
11
12        //base case
13        if(row >= m || col >= n || row < 0 || col < 0 || board[row][col] != word[idx] || board[row][col] == '#') {
14            return false;
15        }
16
17        char temp = board[row][col];
18        board[row][col] = '#';
19
20        bool found = false;
21
22        if(helper(board, word, row, col+1, idx+1) || helper(board, word, row, col-1, idx   +1) || helper(board, word, row+1, col, idx+1) || helper(board, word, row-1, col, idx+1)) {
23            found = true;
24        }
25
26        //backtracking
27        board[row][col] = temp;
28
29        return found;
30    }
31
32    bool exist(vector<vector<char>>& board, string word) {
33        int m = board.size();
34        int n = board[0].size();
35
36        int first = word[0];
37
38        for(int i = 0; i < m; i++) {
39            for(int j = 0; j < n; j++) {
40                if(board[i][j] == first) {
41                    if(helper(board, word, i, j, 0)) return true;
42                }
43            }
44        }
45
46        return false;
47    }
48};