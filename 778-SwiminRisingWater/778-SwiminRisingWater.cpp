// Last updated: 7/6/2026, 1:29:44 AM
1class Solution {
2public:
3    int swimInWater(vector<vector<int>>& grid) {
4        int n = grid.size();
5
6        vector<vector<bool>> vis(n, vector<bool>(n, false));
7        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
8        pq.push({grid[0][0], {0, 0}});
9        vis[0][0] = true;
10
11        while(!pq.empty()) {
12            int curr = pq.top().first;
13            int i = pq.top().second.first;
14            int j = pq.top().second.second;
15
16            pq.pop();
17
18            if(i == n-1 && j == n-1) {
19                return curr;
20            }
21
22            if(i-1 >= 0 && !vis[i-1][j]) {
23                pq.push({max(curr, grid[i-1][j]), {i-1, j}});
24                vis[i-1][j] = true;
25            }
26
27            if(j-1 >= 0 && !vis[i][j-1]) {
28                pq.push({max(curr, grid[i][j-1]), {i, j-1}});
29                vis[i][j-1] = true;
30            }
31
32            if(i+1 < n && !vis[i+1][j]) {
33                pq.push({max(curr, grid[i+1][j]), {i+1, j}});
34                vis[i+1][j] = true;
35            }
36
37            if(j+1 < n && !vis[i][j+1]) {
38                pq.push({max(curr, grid[i][j+1]), {i, j+1}});
39                vis[i][j+1] = true;
40            }
41        }
42
43        return -1;
44    }
45};