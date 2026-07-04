// Last updated: 7/5/2026, 1:02:40 AM
1class Solution {
2public:
3    int timer = 1;
4    void dfs(int u, int par, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &ans) {
5        vis[u] = true;
6        tin[u] = low[u] = timer;
7        timer++;
8
9        for(int v : adj[u]) {
10            if(!vis[v]) {
11                dfs(v, u, adj, vis, tin, low, ans);
12                low[u] = min(low[u], low[v]);
13
14                if(low[v] > tin[u]) {
15                    ans.push_back({u, v});
16                }
17            } else if(vis[v] && v != par) {
18                if(tin[v] < low[u]) {
19                    low[u] = tin[v];
20                }
21            }
22        }
23    }
24    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
25        vector<vector<int>> adj(n);
26
27        for(int i = 0; i < connections.size(); i++) {
28            adj[connections[i][0]].push_back(connections[i][1]);
29            adj[connections[i][1]].push_back(connections[i][0]);
30        }
31
32        vector<bool> vis(n, false);
33        vector<int> tin(n);
34        vector<int> low(n);
35
36        vector<vector<int>> ans;
37        
38        for(int i = 0; i < n; i++) {
39            if(!vis[i]) {
40                dfs(i, -1, adj, vis, tin, low, ans);
41            }
42        }
43
44        return ans;
45    }   
46};