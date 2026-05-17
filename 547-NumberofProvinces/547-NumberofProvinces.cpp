// Last updated: 5/18/2026, 1:19:13 AM
1class Solution {
2public:
3    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int u) {
4        vis[u] = true;
5
6        for(int v : adj[u]) {
7            if(!vis[v]) {
8                dfs(adj, vis, v);
9            }
10        }
11    }
12
13    int findCircleNum(vector<vector<int>>& isConnected) {
14        int n = isConnected.size();
15
16        vector<vector<int>> adj(n);
17
18        for(int i = 0; i < n; i++) {
19            for(int j = 0; j < n; j++) {
20                if(isConnected[i][j] == 1) {
21                    adj[i].push_back(j);
22                    adj[j].push_back(i);
23                }
24            }
25        }
26        vector<bool> vis(n, false);
27        int ans = 0;
28
29        for(int i = 0; i < n; i++) {
30            if(!vis[i]){
31                dfs(adj, vis, i);
32                ans++;
33            }
34        }
35
36        return ans;
37    }
38};