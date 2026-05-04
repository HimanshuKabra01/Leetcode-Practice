// Last updated: 5/5/2026, 1:32:04 AM
1class Solution {
2public:
3    void rotate(vector<vector<int>>& mat) {
4        int n = mat.size();
5
6        for(int i = 0; i < n; i++) {
7            for(int j = i + 1; j < n; j++) {
8                swap(mat[i][j], mat[j][i]);
9            }
10        }
11
12        for(int i = 0; i < n; i++) {
13            reverse(mat[i].begin(), mat[i].end());
14        }
15    }
16};