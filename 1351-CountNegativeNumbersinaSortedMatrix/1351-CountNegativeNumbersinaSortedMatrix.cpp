// Last updated: 12/28/2025, 9:49:07 AM
1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4        int ans = 0;
5        int m = grid[0].size();
6        int n = grid.size();
7
8        for(int i = 0; i < n; i++) {
9            for(int j = 0; j < m; j++) {
10                if(grid[i][j] < 0) {
11                    ans++;
12                }
13            }
14        }
15
16        return ans;
17    }
18};