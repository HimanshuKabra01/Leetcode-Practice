// Last updated: 7/20/2026, 12:47:21 PM
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        while(k != 0) {
8            vector<int> last;
9            for(int i = 0; i < m; i++) {
10                last.push_back(grid[i][n-1]);
11            }
12
13            for(int j = n-2; j >= 0; j--) {
14                for(int i = 0; i < m; i++) {
15                    grid[i][j+1] = grid[i][j];
16                } 
17            }
18
19            grid[0][0] = last[last.size()-1];
20
21            for(int i = 1; i < last.size(); i++) {
22                grid[i][0] = last[i-1];
23            }
24
25            k--;
26        }
27
28        return grid;        
29    }
30};