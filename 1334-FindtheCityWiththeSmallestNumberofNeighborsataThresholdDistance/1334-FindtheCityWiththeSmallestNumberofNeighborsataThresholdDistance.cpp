// Last updated: 6/23/2026, 4:25:51 PM
1class Solution {
2public:
3    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
4        vector<vector<int>> adj(n, vector<int> (n, INT_MAX));
5
6        for(int i = 0; i < n; i++) {
7            adj[i][i] = 0;
8        }
9
10        for(int k = 0; k < edges.size(); k++) {
11            int i = edges[k][0];
12            int j = edges[k][1];
13            int wt = edges[k][2];
14
15            adj[i][j] = wt;
16            adj[j][i] = wt;
17        }  
18
19        for(int via = 0; via < n; via++) {
20            for(int i = 0; i < n; i++) {
21                for(int j = 0; j < n; j++) {
22                    if(adj[i][via] != INT_MAX && adj[via][j] != INT_MAX) {
23                        adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
24                    }
25                }
26            }
27        }
28
29        int ans = -1;
30        int ansDist = INT_MAX;
31
32        for(int i = 0; i < n; i++) {
33            int curr = 0;
34            for(int j = 0; j < n; j++) {
35                if(adj[i][j] <= distanceThreshold) {
36                    curr++;
37                }
38            }
39
40            if(curr <= ansDist) {
41                ansDist = curr;
42                ans = i;
43            }
44        }
45
46        return ans;
47    }
48};