// Last updated: 1/21/2026, 3:13:44 PM
1class Solution {
2public:
3    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        int m = matrix[0].size();
6
7        vector<vector<int>> trans(m, vector<int>(n, 0));
8        for(int i = 0; i < n; i++) {
9            for(int j = 0; j < m; j++) {
10                trans[j][i] = matrix[i][j];
11            }
12        }
13
14        return trans;
15    }
16};