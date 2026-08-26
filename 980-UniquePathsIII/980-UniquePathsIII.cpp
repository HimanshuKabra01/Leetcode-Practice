// Last updated: 8/26/2026, 4:33:18 PM
1class Solution {
2public:
3    int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int sqCount) {
4        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1 || vis[i][j] != -1) {
5            return 0;
6        }
7
8        if(grid[i][j] == 1) {
9            if(sqCount == 0) {
10                return 1;
11            } else {
12                return 0;
13            }
14        }
15
16        vis[i][j] = 0;
17        sqCount--;
18
19        int up = rec(i-1, j, grid, vis, sqCount);
20        int down = rec(i+1, j, grid, vis, sqCount);
21        int left = rec(i, j-1, grid, vis, sqCount);
22        int right = rec(i, j+1, grid, vis, sqCount);
23
24        vis[i][j] = -1;
25
26        return up+left+down+right;
27    }
28    int uniquePathsIII(vector<vector<int>>& grid) {
29        int m = grid.size();
30        int n = grid[0].size();
31
32        int edi = -1;
33        int edj = -1;
34        int sqCount = 0;
35
36        vector<vector<int>> vis(m, vector<int> (n, -1));
37
38        for(int i = 0; i < m; i++) {
39            for(int j = 0; j < n; j++) {
40                if(grid[i][j] == 2) {
41                    edi = i;
42                    edj = j;
43                } else if(grid[i][j] == 0) {
44                    sqCount++;
45                }
46            }
47            
48        }
49
50        return rec(edi, edj, grid, vis, sqCount+1);
51    }   
52};